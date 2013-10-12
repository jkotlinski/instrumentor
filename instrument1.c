/* {{{ The MIT License (MIT)

Copyright (c) 2001, 2013 Johan Kotlinski

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE. }}} */

#include <stdio.h>
#include <gb.h>
#include <cgb.h>
#include <font.h>
#include <hardware.h>

#include "freqtable.h"
#include "effects.h"
#include "globals.h"
#include "inputhandler.h"
#include "ui.h"
#include "font_fucktracker1.h"
#include "screen.h"

UBYTE tickcounter;

void play(UBYTE ch, UBYTE oct, UBYTE note) {
  pitch_LSB[ch]=NOTE_LSB[oct][note];
  pitch_MSB[ch]=NOTE_MSB[oct][note];
  pitch[ch] = FREQ[oct][note];
  NR13_REG = pitch_LSB[ch];
  NR14_REG = 0x80U | pitch_MSB[ch];
}

void sound_on(void) {
  NR52_REG = 0x80U;  //öppna alla kanaler
  NR51_REG = 0xffU; //mappa alla kanaler till L+R
  NR50_REG = 0xffU; //max volume SO1 SO2
}

void sound_init(UBYTE ch) {
  if(ch==0) {
    NR12_REG = 0xf0U; // sätt volym till max, env=0
  }
}

void vbl() { /* anropas med frekvensen 60Hz */
	UBYTE ch=0;
	if(playing_pattern) {
	  	tickcounter++;
	  	if(tickcounter==global_speed) {
		    	tickcounter=0;
		    	stepcounter++;
		    	if(stepcounter==pattern_length) {
		      		stepcounter=0;
		    	}
		    	if(step_note[stepcounter]!=13) { //if note not empty
		    		NR51_REG = NR51_REG | (0x11U << ch);
		    		play(ch,step_oct[stepcounter],step_note[stepcounter]);
		    		set_vibrato(ch,5,40,0,0);
		    	}
	  	}
  		handle_effect(ch);
	  	vibrate(ch);
	}
	if(joypad()) {
		handle_input();
	} else {
		new_keypress=1;
		key_delay_counter=key_delay;
	}
} 

void screen_init() {
  font_t fucktracker_font;
	unsigned char c;
	int x,y;
	
	font_init();
	fucktracker_font = font_load(font_fucktracker1);
    	mode(get_mode() | M_NO_SCROLL);
	font_set(fucktracker_font);	

	/* set palettes */
	for(x=0;x!=4;x++) {
		set_bkg_palette(x,1,&fucktracker_p[x*4]);
	}
  
  	/* Set colors */
  	VBK_REG = 1;
  	set_bkg_tiles(0,0,20,18,fucktracker_a);
  	VBK_REG = 0;
}

void init() {
  UBYTE i;

	screen_init();

	disable_interrupts();
  	cgb_compatibility();
  	cpu_fast();
  	
  // add interrupts
  add_VBL(vbl);  	
  	enable_interrupts();
  
  sound_on();
  sound_init(0);

  for(i=0;i<pattern_length;i++) {
    step_oct[i]=3+i%2;
    step_note[i]=5;
  }

  printf(" "); /* initialize text screen */
  global_speed = 6;
}

UBYTE main(void) {
  	init();
  	while(1) {
  		print_menu();
  		delay(60);
  	}
	return 0;
}
