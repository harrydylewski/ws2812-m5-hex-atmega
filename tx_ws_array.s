/*
BYTES: R25:24
PORTX: R23:22 - free after init
PINX:  R21:20
PTR:   R19:18

*/
//extern void tx_ws_array(unsigned char bytes, volatile unsigned char *port, unsigned char pin,  unsigned char *ptr);

#include <avr/io.h>
	//.include "m328pdef.inc"

	.file "tx_ws_array.s"

	.text
	.global hex_update

//FINAL------------------------------------------
hex_update:

	cli
	movw R30,R22  //move PORT pointer to Z
	
	ld  R21,Z    //replace PORTX's pointer with PORTX's value
	or  R20,R21 // are used to preserve PORT values during transmission

	movw R26,R18


start:
	
	ld   R18,X
	ldi  R19,8

maincode:

	st Z,R20 //2	
	lsl R18  //3
	brcc quickexit //4 false/ 5 true

longexit: 

	rcall end //11	

quickexit:

	st Z,R21   //2	
	lpm R22,Z //5
	
	dec R19       //6
	brne maincode //7/8
	
	sbiw R24,1
	brne endtransmit
	
	rjmp start		

endtransmit:

	sei //during demo interrupts will be enabled
end:
	ret
