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

#include <drawing.h>
#include <console.h>

#ifndef _UI_H
#define _UI_H

void print_menu() {
	UBYTE j;
	for(j=0;j<8;j++) {
    		gotoxy(2,2+j);
		if(edit_step==j) {
    			printf(">");
    		} else {
			printf(" ");    			
    		}
    		if(stepcounter==j) {
    			printf("*");
    		} else {
			printf(" ");    			
    		}
    		if(step_note[j]==13) {
    			printf("---");
    		} else {
        		printf("%s%d",NOTES[step_note[j]],step_oct[j]);
        	}
        	switch(step_effect[j]) {
        		case 0:
        			printf(" 000");
        			break;
        		case 1:
        			printf(" M%2x",step_effect_value[j]);
        	}
  	}
}

#endif
