#include "neopixel_hex.h"

void hex_writeOutmostCircle(uint8_t *color, neopixel_hex *hex )
{
	uint8_t x,y;

	for(y=0;y<3;y++)
	{

		for(x=4;x>0;x--)
		{
			hex->first[x][y]=color[y];
			hex->seventh[x][y]=color[y];
		}
		
		
		hex->second[0][y]=color[y];
		hex->second[4][y]=color[y];

		hex->sixth[0][y]=color[y];
		hex->sixth[4][y]=color[y];

		hex->third[0][y]=color[y];
		hex->third[5][y]=color[y];

		hex->fifth[0][y]=color[y];
		hex->fifth[5][y]=color[y];

		hex->fourth[0][y]=color[y];
		hex->fourth[6][y]=color[y];
	}

}

void hex_writeOuterCircle(uint8_t *color, neopixel_hex *hex )
{
	uint8_t x,y;

	for(y=0;y<3;y++)
	{
		for(x=1;x<5;x++)
		{
			hex->second[x][y]=color[y];
			hex->sixth[x][y]=color[y];
		}

		for(x=1;x<6;x++)
		{
			hex->third[x][y]=color[y];
			hex->fifth[x][y]=color[y];
		}
	}
	

}

void hex_writeInner_Circle(uint8_t *color, neopixel_hex *hex )
{
	uint8_t x,y;
	
	for(y=0,x=2;y<3;y++)
	{
		hex->third[x][y]=color[y];
		hex->sixth[x++][y]=color[y];
		hex->third[x][y]=color[y];
		hex->sixth[x][y]=color[y];

		hex->fourth[2][y]=color[y];
		hex->fourth[4][y]=color[y];
	}
}

void hex_write_Center(uint8_t *color, neopixel_hex *hex )
{
	uint8_t y;

	for(y=0;y<3;y++)
	hex->fourth[3][y]=color[y];

}
/*
void hex_writeClear( neopixel_hex hex )
{
	uint8_t x=0;
	
	
	for(x=0;x<HEX_TOTAL_LEDS;x++)
	*hex->first++=0;

}
*/
void hex_writeLeftmostDiagonal(uint8_t *color, neopixel_hex *hex )
{
		uint8_t y;
		
	for(y=0;y<3;y++)
	{
		hex->first[0][y]=color[y];
		hex->second[0][y]=color[y];
		hex->third[0][y]=color[y];
		hex->fourth[0][y]=color[y];
	}
}

void hex_writeLefterDiagonal(uint8_t *color, neopixel_hex *hex )
{
	uint8_t y;
	for(y=0;y<3;y++)
	{
		hex->first[1][y]=color[y];
		hex->second[1][y]=color[y];
		hex->third[1][y]=color[y];
		hex->fourth[1][y]=color[y];
		hex->fifth[1][y]=color[y];
	}
}

/*
void hex_writeLeftDiagonal(uint8_t *color, neopixel_hex hex )
{
	uint8_t y;
	
	for(y=0;y<3;y++)
	{
		hex->first[1][y];
		hex->second[1][y];
		hex->third[1][y];
		hex->fourth[1][y];
		hex->fifth[1][y];
		hex->sixth[1][y];
	}
}


void hex_writeLeftDiagonal(uint8_t *color, neopixel_hex hex )
{
	uint8_t y;
	
	for(y=0;y<3;y++)
	{
		hex->first[1][y];
		hex->second[1][y];
		hex->third[1][y];
		hex->fourth[1][y];
		hex->fifth[1][y];
		hex->sixth[1][y];
		hex->seventh[1][y];
	}
}
*/


//uint8_t hex_writeDiagonal(uint8_t *color, neopixel_hex hex, hex_direction direction, hex_side side, uint8_t row)
uint8_t hex_writeDiagonal(uint8_t *color, neopixel_hex *hex, hex_diagonal_combinations combo, uint8_t row)
{
	
	//uint8_t function_lookup=direction+side;
	//function_lookup=(direction|side<<3)|row;
	
	if(combo>1)
	return false;
	
	uint8_t status;
	
	if(combo)
	{
		status=hex_writeDiagonal_InTop_OutBottom(color,hex,row);
		return status;
	}
	
	else
	{
		status=hex_writeDiagonal_InBottom_OutTop(color,hex,row);
		return status;
	}
	
	
	/*
	//row becomes two's complement to reduce the amount of look up tables
	if( (direction) && (side) )
	row = (row^0x07)+1;
	

	if( (direction|side == InTop) || (direction|side == OutBottom) )
	{
		status=hex_writeDiagonal_InTop_OutBottom(color,&hex,row);
		return status;
	}
	
	
	else if ( (direction|side == InBottom) || (direction|side == OutTop) )
	{
		status=hex_writeDiagonal_InBottom_OutTop(color,&hex,row);
		return status;
	}
	
	else
	return false;
	*/
	
}
uint8_t hex_writeDiagonal_InTop_OutBottom(uint8_t *color, neopixel_hex *hex, uint8_t row)
{
		int y;
		
		switch (row){
			
			case 1:
			for(y=0;y<3;y++)
			{
				hex->first[3][y]=color[y];
				hex->second[4][y]=color[y];
				hex->third[5][y]=color[y];
				hex->fourth[6][y]=color[y];

			}
			break;
			
			case 2:
			for(y=0;y<3;y++)
			{
				hex->first[2][y]=color[y];
				hex->second[3][y]=color[y];
				hex->third[4][y]=color[y];
				hex->fourth[5][y]=color[y];
				hex->fifth[4][y]=color[y];

			}
			break;
			
			case 3:
			for(y=0;y<3;y++)
			{
				hex->first[1][y]=color[y];
				hex->second[2][y]=color[y];
				hex->third[3][y]=color[y];
				hex->fourth[4][y]=color[y];
				hex->fifth[3][y]=color[y];
				hex->sixth[2][y]=color[y];

			}
			break;

			case 4:
			for(y=0;y<3;y++)
			{
				hex->first[0][y]=color[y];
				hex->second[1][y]=color[y];
				hex->third[2][y]=color[y];
				hex->fourth[3][y]=color[y];
				hex->fifth[3][y]=color[y];
				hex->sixth[3][y]=color[y];
				hex->seventh[3][y]=color[y];

			}
			break;
			case 5:
			for(y=0;y<3;y++)
			{
				hex->second[0][y]=color[y];
				hex->third[1][y]=color[y];
				hex->fourth[2][y]=color[y];
				hex->fifth[2][y]=color[y];
				hex->sixth[2][y]=color[y];
				hex->seventh[2][y]=color[y];

			}
			break;
			
			case 6:
			for(y=0;y<3;y++)
			{

					hex->third[0][y]=color[y];
					hex->fourth[1][y]=color[y];
					hex->fifth[1][y]=color[y];
					hex->sixth[1][y]=color[y];
					hex->seventh[1][y]=color[y];

			}
			break;
			
			case 7:
			for(y=0;y<3;y++)
			{

					
					hex->fourth[0][y]=color[y];
					hex->fifth[0][y]=color[y];
					hex->sixth[0][y]=color[y];
					hex->seventh[0][y]=color[y];

			}
			break;
			
			default: return false;
		}
			return true;
}

uint8_t hex_writeDiagonal_InBottom_OutTop(uint8_t *color, neopixel_hex *hex, uint8_t row)
{
		uint8_t y;
		
		switch (row){
			
			case 1:
			for(y=0;y<3;y++)
			{
				hex->fourth[6][y]=color[y];
				hex->fifth[5][y]=color[y];
				hex->sixth[4][y]=color[y];
				hex->seventh[3][y]=color[y];

			}
			break;
			
			case 2:
			for(y=0;y<3;y++)
			{
				hex->third[5][y]=color[y];
				hex->fourth[5][y]=color[y];
				hex->fifth[4][y]=color[y];
				hex->sixth[3][y]=color[y];
				hex->seventh[2][y]=color[y];

			}
			break;
			
			case 3:
			for(y=0;y<3;y++)
			{

				hex->second[4][y]=color[y];
				hex->third[4][y]=color[y];
				hex->fourth[4][y]=color[y];
				hex->fifth[3][y]=color[y];
				hex->sixth[2][y]=color[y];
				hex->seventh[1][y]=color[y];

			}
			break;

			case 4:
			for(y=0;y<3;y++)
			{
				hex->first[3][y]=color[y];
				hex->second[3][y]=color[y];
				hex->third[3][y]=color[y];
				hex->fourth[3][y]=color[y];
				hex->fifth[2][y]=color[y];
				hex->sixth[1][y]=color[y];
				hex->seventh[0][y]=color[y];

			}
			break;
			case 5:
			for(y=0;y<3;y++)
			{
				hex->first[2][y]=color[y];
				hex->second[2][y]=color[y];
				hex->third[2][y]=color[y];
				hex->fourth[2][y]=color[y];
				hex->fifth[1][y]=color[y];
				hex->sixth[0][y]=color[y];			

			}
			break;
			
			case 6:
			for(y=0;y<3;y++)
			{

				hex->first[1][y]=color[y];
				hex->second[1][y]=color[y];
				hex->third[1][y]=color[y];
				hex->fourth[1][y]=color[y];
				hex->fifth[0][y]=color[y];

			}
			break;
			
			case 7:
			for(y=0;y<3;y++)
			{

				
				hex->first[0][y]=color[y];
				hex->second[0][y]=color[y];
				hex->third[0][y]=color[y];
				hex->fourth[0][y]=color[y];
			
			}
			break;
			
			default: return false;
		}
			return true;
	
	
}

uint8_t  hex_writeRow(uint8_t *color, neopixel_hex *hex, uint8_t row)
{
	uint8_t x,y;
	
	switch (row)
	{
		case 1:			
		for(x=0;x<4;x++)
		{
			for(y=0;y<3;y++)
			hex->first[x][y]=color[y];
		}
		break;
	
		case 2:
		for(x=0;x<5;x++)
		{
			for(y=0;y<3;y++)				
			hex->second[x][y]=color[y];	
		}
		break;
		
		case 3:
		for(x=0;x<6;x++)
		{
			for(y=0;y<3;y++)
			hex->third[x][y]=color[y];	
		}
		break;

		case 4:
		for(x=0;x<7;x++)
		{
			for(y=0;y<3;y++)
			hex->fourth[x][y]=color[y];
		}
		break;
		case 5:
		for(x=0;x<6;x++)
		{
			for(y=0;y<3;y++)
			hex->fifth[x][y]=color[y];
		}
		break;
		
		case 6:
		for(x=0;x<5;x++)
		{
			for(y=0;y<3;y++)
			hex->sixth[x][y]=color[y];
		}
		break;
		
		case 7:
		for(x=0;x<4;x++)
		{
			for(y=0;y<3;y++)
			hex->seventh[x][y]=color[y];
		}
		break;
		
		default: 
		return false;
		
	
	}	
		
	return true;
		
}