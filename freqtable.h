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

#ifndef _FREQTABLE_H
#define _FREQTABLE_H

#include <types.h>

/* assign GB frequency data for 6 octaves x 12 notes */

UBYTE NOTE_LSB[6][12]= 
{{44,156,6,107,201,35,119,198,18,86,155,218},
{22,78,131,181,229,17,59,99,137,172,206,237},
{10,39,66,91,114,137,158,178,196,214,231,247},
{6,20,33,45,57,68,79,89,98,107,115,123},
{131,138,144,151,157,162,167,172,177,182,186,190},
{193,196,200,203,206,209,212,214,217,219,221,223}};

UBYTE NOTE_MSB[6][12] =
{{0,0,1,1,1,2,2,2,3,3,3,3},
{4,4,4,4,4,5,5,5,5,5,5,5},
{6,6,6,6,6,6,6,6,6,6,6,6},
{7,7,7,7,7,7,7,7,7,7,7,7},
{7,7,7,7,7,7,7,7,7,7,7,7},
{7,7,7,7,7,7,7,7,7,7,7,7}};

WORD FREQ[6][12] =
{
{44,156,262,363,457,547,631,710,786,854,923,986},
{1046,1102,1155,1205,1253,1297,1339,1379,1417,1352,1486,1517},
{1546,1575,1602,1627,1650,1673,1694,1714,1732,1750,1767,1783},
{1798,1812,1825,1837,1849,1860,1871,1881,1890,1899,1907,1915},
{1923,1930,1936,1943,1949,1954,1959,1964,1969,1974,1978,1982},
{1985,1988,1992,1995,1998,2001,2004,2006,2009,2011,2013,2015}
};

char NOTES[12][3] =
{"C ", 
 "C#", 
 "D ",
 "D#",
 "E ",
 "F ",
 "F#",
 "G ",
 "G#",
 "A ",
 "A#",
 "B "};
 
#endif
