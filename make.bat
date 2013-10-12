c:\sdk\gbz80-gb\2-1-5\bin\lcc -Wa-l -c -o instrument1.o instrument1.c
c:\sdk\gbz80-gb\2-1-5\bin\lcc -Wa-l -c -o font.o font.c
c:\sdk\gbz80-gb\2-1-5\bin\lcc -Wl-m -Wl-yp0x143=0x80 -o instrumentor.gb instrument1.o font.o
