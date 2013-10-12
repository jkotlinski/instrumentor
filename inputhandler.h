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

#include <gb.h>

#include "globals.h"
#include "ui.h"

#ifndef _INPUTHANDLER_H
#define _INPUTHANDLER_H

UBYTE prev_keystate;
/* key_delay and key_repeat values are measured in vblanks */
UBYTE key_delay=6,key_repeat=3;
UBYTE key_delay_counter,key_repeat_counter;
UBYTE new_keypress;

void handle_input() {
	UBYTE keystate=joypad();

	/* handle key delay */
	if(key_delay_counter) {
		if(key_delay_counter==key_delay) {
			key_delay_counter--;
			key_repeat_counter=0;
		} else {
			key_delay_counter--;
			return;
		}
	} 
	
	/*handle key repeat*/
	if(key_repeat_counter--) {
		return;
	} 
	key_repeat_counter=key_repeat;

	//start-stop
	if(keystate&J_START&&new_keypress) { 
  		if(!playing_pattern) {
  			playing_pattern = 1;
  			stepcounter=0;
  		} else {
  			playing_pattern=0;
  		}
	}

	//erase step
	if((keystate&J_A)&&(keystate&J_B)) {
		new_keypress=0;
		if(step_note[edit_step]!=13) {
			prev_note=step_note[edit_step];
			prev_oct=step_oct[edit_step];
			step_note[edit_step]=13;
		} else {
			step_note[edit_step]=prev_note;
			step_oct[edit_step]=prev_oct;
		}
		return;
	}
	
	if(keystate&J_B) {
		//note up
		if(keystate&J_UP) {
			if(step_note[edit_step]==13) {
				step_note[edit_step]=prev_note;
				step_oct[edit_step]=prev_oct;
			}
			step_note[edit_step]++;
			if(step_note[edit_step]==12) {
				step_note[edit_step]=0;
			}
		}
		//note down
		if(keystate&J_DOWN) {
			if(step_note[edit_step]==13) {
				step_note[edit_step]=prev_note;
				step_oct[edit_step]=prev_oct;
			}
			step_note[edit_step]--;
			if(step_note[edit_step]==0xffU) {
				step_note[edit_step]=11;
			}
		}
	} else if(keystate&J_A) {
		//octave up
		if(keystate&J_UP) {
			if(step_note[edit_step]==13) {
				step_note[edit_step]=prev_note;
				step_oct[edit_step]=prev_oct;
			}
			step_oct[edit_step]++;
			if(step_oct[edit_step]==6) {
				step_oct[edit_step]=0;
			}
		}
		//octave down
		if(keystate&J_DOWN) {
			if(step_note[edit_step]==13) {
				step_note[edit_step]=prev_note;
				step_oct[edit_step]=prev_oct;
			}
			step_oct[edit_step]--;
			if(step_oct[edit_step]==0xffU) {
				step_oct[edit_step]=5;
			}
		}
	} else { //neither A nor B are pressed!
		//cursor up
		if(keystate&J_UP) {
			edit_step--;
			if(edit_step==0xffU) {
				edit_step=pattern_length-1;
			}
		}
		//cursor down
		if(keystate&J_DOWN) {
			edit_step++;
			if(edit_step==pattern_length) {
				edit_step=0;
			}
		}
		//cursor_right
		if(keystate&J_RIGHT) {
		}
	}
	
	new_keypress=0;
}

#endif
