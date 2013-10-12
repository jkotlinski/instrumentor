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

#ifndef _SCREEN_H
#define _SCREEN_H

/* Gameboy Color palette 0 */
#define FuckTrackerCGBPal0c0 32767
#define FuckTrackerCGBPal0c1 10207
#define FuckTrackerCGBPal0c2 24311
#define FuckTrackerCGBPal0c3 0

/* Gameboy Color palette 1 */
#define FuckTrackerCGBPal1c0 32756
#define FuckTrackerCGBPal1c1 31384
#define FuckTrackerCGBPal1c2 24311
#define FuckTrackerCGBPal1c3 64

/* Gameboy Color palette 2 */
#define FuckTrackerCGBPal2c0 32189
#define FuckTrackerCGBPal2c1 31384
#define FuckTrackerCGBPal2c2 5140
#define FuckTrackerCGBPal2c3 32767

/* Gameboy Color palette 3 */
#define FuckTrackerCGBPal3c0 11455
#define FuckTrackerCGBPal3c1 31384
#define FuckTrackerCGBPal3c2 5140
#define FuckTrackerCGBPal3c3 32767

/* Gameboy Color palette 4 */
#define FuckTrackerCGBPal4c0 6076
#define FuckTrackerCGBPal4c1 8935
#define FuckTrackerCGBPal4c2 6596
#define FuckTrackerCGBPal4c3 5344

/* Gameboy Color palette 5 */
#define FuckTrackerCGBPal5c0 6076
#define FuckTrackerCGBPal5c1 8935
#define FuckTrackerCGBPal5c2 6596
#define FuckTrackerCGBPal5c3 5344

/* Gameboy Color palette 6 */
#define FuckTrackerCGBPal6c0 6076
#define FuckTrackerCGBPal6c1 8935
#define FuckTrackerCGBPal6c2 6596
#define FuckTrackerCGBPal6c3 5344

/* Gameboy Color palette 7 */
#define FuckTrackerCGBPal7c0 6076
#define FuckTrackerCGBPal7c1 8935
#define FuckTrackerCGBPal7c2 6596
#define FuckTrackerCGBPal7c3 5344

UWORD fucktracker_p[] =
{
  FuckTrackerCGBPal0c0,FuckTrackerCGBPal0c1,FuckTrackerCGBPal0c2,FuckTrackerCGBPal0c3,
  FuckTrackerCGBPal1c0,FuckTrackerCGBPal1c1,FuckTrackerCGBPal1c2,FuckTrackerCGBPal1c3,
  FuckTrackerCGBPal2c0,FuckTrackerCGBPal2c1,FuckTrackerCGBPal2c2,FuckTrackerCGBPal2c3,
  FuckTrackerCGBPal3c0,FuckTrackerCGBPal3c1,FuckTrackerCGBPal3c2,FuckTrackerCGBPal3c3,
  FuckTrackerCGBPal4c0,FuckTrackerCGBPal4c1,FuckTrackerCGBPal4c2,FuckTrackerCGBPal4c3,
  FuckTrackerCGBPal5c0,FuckTrackerCGBPal5c1,FuckTrackerCGBPal5c2,FuckTrackerCGBPal5c3,
  FuckTrackerCGBPal6c0,FuckTrackerCGBPal6c1,FuckTrackerCGBPal6c2,FuckTrackerCGBPal6c3,
  FuckTrackerCGBPal7c0,FuckTrackerCGBPal7c1,FuckTrackerCGBPal7c2,FuckTrackerCGBPal7c3
};


unsigned char fucktracker_a[] =
{
  7,7,4,4,4,6,6,6,2,2,2,5,5,5,1,1,1,3,3,3,
  7,7,4,4,4,6,6,6,2,2,2,5,5,5,1,1,1,3,3,3,
  7,7,0,0,0,1,0,0,2,2,2,5,5,5,1,1,1,3,3,3,
  7,7,0,0,0,1,0,0,2,2,2,5,5,5,1,1,1,3,3,3,
  7,7,0,0,0,1,0,0,2,2,2,5,5,5,1,1,1,3,3,3,
  7,7,0,0,0,1,0,0,2,2,2,5,5,5,1,1,1,3,3,3,
  7,7,0,0,0,1,0,0,2,2,2,5,5,5,1,1,1,3,3,3,
  7,7,0,0,0,1,0,0,2,2,2,5,5,5,1,1,1,3,3,3,
  7,7,0,0,0,1,0,0,2,2,2,5,5,5,1,1,1,3,3,3,
  7,7,0,0,0,1,0,0,2,2,2,5,5,5,1,1,1,3,3,3,
  7,7,0,0,4,1,0,0,2,2,2,5,5,5,1,1,1,3,3,3,
  7,7,0,4,4,1,0,0,2,2,2,5,5,5,1,1,1,3,3,3,
  7,7,0,4,4,1,6,6,2,2,2,5,5,5,1,1,1,3,3,3,
  7,7,4,4,4,6,6,6,2,2,2,5,5,5,1,1,1,3,3,3,
  3,3,0,0,0,5,5,5,0,0,0,6,6,6,0,0,0,7,7,7,
  3,3,3,3,0,0,0,0,5,5,5,5,0,0,0,0,0,0,0,0,
  3,3,3,3,0,0,0,0,5,5,5,5,0,0,0,0,0,0,0,0,
  3,3,3,3,0,0,0,0,5,5,5,5,0,0,0,0,0,0,0,0
};


#endif
