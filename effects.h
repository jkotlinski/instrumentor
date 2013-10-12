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

#include "globals.h"
#include <types.h>

#ifndef _EFFECTS_H
#define _EFFECTS_H

/* vibrato types are:
   0 - saw
   1 - triangle
   2 - square

   vibrato directions are:
   0 - downwards
   1 - upwards
   */

void handle_effect(BYTE ch) {
	switch(step_effect[stepcounter]) {
		case 0: //empty
			break;
		case 1: //mute
	    		NR51_REG = NR51_REG & (0xeeU << ch);
	}
}

BYTE vibrato_delay[4],vibrato_rate[4],vibrato_depth[4],
             vibrato_current_mod[4],vibrato_type[4],vibrato_direction[4];

void vibrate(BYTE ch) {
  WORD new_pitch;
  BYTE mod;

  vibrato_current_mod[ch]+=vibrato_rate[ch];
	while(vibrato_current_mod[ch]>vibrato_depth[ch]) {
  	vibrato_current_mod[ch]-=vibrato_depth[ch];
  }

  switch(vibrato_type[ch]) {
		case 0: //sawtooth
  		mod = vibrato_current_mod[ch];
  		break;
    case 1: //triangle
      if(vibrato_current_mod[ch]<=(vibrato_depth[ch]/2)) {
				mod = vibrato_current_mod[ch];
				mod += vibrato_current_mod[ch];
			} else {
				mod = vibrato_depth[ch];
				mod -= vibrato_current_mod[ch];
				mod += mod;
			}
  		break;
    case 2: //square
			if(vibrato_current_mod[ch]<vibrato_depth[ch]/2) {
    		mod = 0;
		  } else {
				mod = vibrato_depth[ch];
			}
  		break;

  }

  switch(vibrato_direction[ch]) {
		case 0:
  		new_pitch = pitch[ch] - mod;
  		break;
		case 1:
  		new_pitch = pitch[ch] + mod;
  		break;
	}

  NR13_REG = new_pitch;
  NR14_REG = new_pitch >> 8;
}

void set_vibrato(BYTE ch,BYTE rate,BYTE depth,BYTE type,BYTE direction) {
  vibrato_rate[ch]=rate;
  vibrato_depth[ch]=depth;
  vibrato_type[ch]=type;
  vibrato_direction[ch]=direction;
  vibrato_current_mod[ch]=0;
}

#endif
