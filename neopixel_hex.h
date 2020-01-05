
#ifndef NEOPIXEL_HEX_H
#define NEOPIXEL_HEX_H

#include <stdint.h>
#include <stdbool.h>

#define LAYERS 4
#define OUTMOST 18
#define OUTER   12
#define INNER   6
#define INNEST  1

#define HEX_TOTAL_LEDS (OUTMOST+OUTER+INNER+INNEST)*3

#define MAX_ROWS 7

#define inverseRow(x) x=x^MAX_ROWS+1 

typedef enum
{
	In,
	Out
} hex_direction;


typedef enum
{
	Top,
	Bottom=2
} hex_side;

typedef enum
{
	InTop,
	OutTop,
	InBottom,
	OutBottom
} hex_diagonal;

typedef enum
{
	InTop_OutBottom,
	OutTop_InBottom
} hex_diagonal_combinations;

typedef __attribute__((packed)) struct 
{
	uint8_t first[4][3];
	uint8_t second[5][3];
	uint8_t third[6][3];
	uint8_t fourth[7][3];
	uint8_t fifth[6][3];
	uint8_t sixth[5][3];
	uint8_t seventh[4][3];

} neopixel_hex;


void hex_writeOutmostCircle(uint8_t *color, neopixel_hex  *hex );

void hex_writeOuterCircle(uint8_t *color, neopixel_hex *hex );
void hex_writeInner_Circle(uint8_t *color, neopixel_hex  *hex );
void hex_write_Center(uint8_t *color, neopixel_hex  *hex );
void hex_writeClear( neopixel_hex  *hex );



//uint8_t  hex_writeDiagonal(uint8_t *color, neopixel_hex hex, hex_direction direction, hex_side side, uint8_t row);
uint8_t hex_writeDiagonal(uint8_t *color, neopixel_hex *hex, hex_diagonal_combinations combo, uint8_t row);
uint8_t hex_writeDiagonal_InTop_OutBottom(uint8_t *color, neopixel_hex *hex, uint8_t row);
uint8_t hex_writeDiagonal_InBottom_OutTop(uint8_t *color, neopixel_hex *hex, uint8_t row);
uint8_t hex_writeRow(uint8_t *color, neopixel_hex *hex, uint8_t row);


void hex_writeLeftmostDiagonal(uint8_t *color, neopixel_hex *hex );
void hex_writeLefterDiagonal(uint8_t *color, neopixel_hex *hex );
void hex_writeLeftDiagonal(uint8_t *color, neopixel_hex *hex );

#endif