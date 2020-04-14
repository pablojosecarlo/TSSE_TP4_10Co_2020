

#include <stdio.h>
#include <stdint.h>
#include "encoder10bits.h"

////////////////////////////ENCODER 10 BITS//////////////////////////////////



void setupEncoder(){
  int i;
  for (i = LSB; i > LSB - BITS; i--){
    pinMode(i, INPUT_PULLUP);
  } 
}

int leerEncoder(){
  static int resultAnt = 0;
  int rawValues[BITS];
  int i, j;
  int result;

  j = BITS - 1;

  for (i = LSB; i > LSB - BITS; i--){  
    int readVal;
    readVal = digitalRead(i);
    rawValues[j] = readVal; 
    j--;
  }

  result = binToDec(rawValues, BITS); 
  result = grayDecode(result); 

  if(result != resultAnt){
    //for(j = 0; j < BITS; j++){
    //  Serial.print(rawValues[j]);  
    //}
    //Serial.print("\t");
    //Serial.println(result);
    resultAnt = result;
  }

  return resultAnt;
}

int grayDecode(unsigned int n) { 
  unsigned int p = n;
  while ( n = n >> 1) 
    p = p ^ n;
    
  return p;
}

int binToDec(int *inputval, int bits){
  int i;
  int val = 1;
  int result = 0;

  for (i = bits - 1; i >= 0; i--){
    result += inputval[i] * val;
    val *= 2;
  }
return result;
}

float encoderToDistance( int xEncoder, float Radio){
    return 6.283*((float)xEncoder/1024)*Radio;
}

void FLOAT_A_LCD_BLE( float x ){

// Envia el float con resolución +-###.## al lcd
// Prepara el arreglo TxtBLE para enviar el float como +-###.##
// al Bluetooth LE

	FLOAT_A_DIGITAL5( x );

	if ( x   <  0  )  write_lcd( '-' );
	if ( NUM[4] > 0 ) write_lcd( NUM[4] + 48 );
	if ( NUM[3] > 0 ) write_lcd( NUM[3] + 48 );

	write_lcd( NUM[2] + 48 );
	write_lcd( '.' );
	write_lcd( NUM[1] + 48 );

	if( LAST_STATUS_REG_SET & 1 ){
		write_lcd( 48 );  //0   -> si no tengo resolucion pongo 0 en el segundo decimal
	}else{
		write_lcd( NUM[0] + 48 );
	}

	//preparo el string para mandar al BLE por la usart
	uint8_t i = 0;

	for (; i< 9; i++) TxtBLE[i] = ' ';

	i = 3;
	if (   x    < 0 ){ TxtBLE[i] = '-'        ; i++; }
	if ( NUM[4] > 0 ){ TxtBLE[i] = NUM[4] + 48; i++; }
	if ( NUM[3] > 0 ){ TxtBLE[i] = NUM[3] + 48; i++; }
	                   TxtBLE[i] = NUM[2] + 48; i++;
	                   TxtBLE[i] = '.'        ; i++;
	                   TxtBLE[i] = NUM[1] + 48; i++;

	if( LAST_STATUS_REG_SET & 1 ){
		TxtBLE[i] = 48;  //0   -> si no tengo resolucion pongo 0 en el segundo decimal
	}else{
		TxtBLE[i] = NUM[0] + 48;
	}
}


void FLOAT_A_DIGITAL5(float x){

// Convierte de float a dígitos ascii: Tres enteros y dos decimales
// Asume que el formato del float es ###.## i.e. se considera que solo tiene 
// dos decimales válidos --> solo se recuperan dos decimales !!
// La salida está en el arreglo NUM[5].

	union
	{
		unsigned char sector[1];
		unsigned int x;
	} unionX;

  if ( x < 0 ) x = -x;
	unionX.x = (uint16_t) ( 100 *  x );
	BIN16_A_DIGITAL5(unionX.sector[1], unionX.sector[0]);	//CONVIERTE HADD Y LADD A NUM[4] -> NUM[0]
}




void BIN16_A_DIGITAL5(uint8_t HADD, uint8_t LADD){

//convierte un uint_16 formando por dos mitades uint8_t en dígitos ascii que 
//guarda en el arreglo NUM[5]

	NUM[0] = 0; NUM[1] = 0; NUM[2] = 0; NUM[3] = 0; NUM[4] = 0;

	//BLOQUE DE PASAR DE BINARIO A GRUPOS DE UNIDADES, DECENAS, CENTENAS, MILES. ETC
	if (LADD & 0b00000001){ NUM[0] +=1; }//1
	if (LADD & 0b00000010){ NUM[0] +=2; }//2
	if (LADD & 0b00000100){ NUM[0] +=4; }//4
	if (LADD & 0b00001000){ NUM[0] +=8; }//8
	if (LADD & 0b00010000){ NUM[0] +=6; NUM[1] += 1; }//16
	if (LADD & 0b00100000){ NUM[0] +=2; NUM[1] += 3; }//32
	if (LADD & 0b01000000){ NUM[0] +=4; NUM[1] += 6; }//64
	if (LADD & 0b10000000){ NUM[0] +=8; NUM[1] += 2; NUM[2] += 1; }//128

	if (HADD & 0b00000001){ NUM[0] +=6; NUM[1] += 5; NUM[2] += 2; }//256
	if (HADD & 0b00000010){ NUM[0] +=2; NUM[1] += 1; NUM[2] += 5; }//512
	if (HADD & 0b00000100){ NUM[0] +=4; NUM[1] += 2; NUM[2] += 0; NUM[3] += 1; }//1024
	if (HADD & 0b00001000){ NUM[0] +=8; NUM[1] += 4; NUM[2] += 0; NUM[3] += 2; }//2048
	if (HADD & 0b00010000){ NUM[0] +=6; NUM[1] += 9; NUM[2] += 0; NUM[3] += 4; }//4096
	if (HADD & 0b00100000){ NUM[0] +=2; NUM[1] += 9; NUM[2] += 1; NUM[3] += 8; }//8192
	if (HADD & 0b01000000){ NUM[0] +=4; NUM[1] += 8; NUM[2] += 3; NUM[3] += 6; NUM[4] += 1; }//16384
	if (HADD & 0b10000000){ NUM[0] +=8; NUM[1] += 6; NUM[2] += 7; NUM[3] += 2; NUM[4] += 3; }//32768
	//BLOQUE DE PASAR DE GRUPOS DE UNIDADES, DECENAS, CENTENAS Y MILES
	//A UNIDADES DE: UNIDAD, DECENA, CENTENA, MIL, DIEZ MIL, ETC.
	while(NUM[0] >= 0) { NUM[0] -= 10; if ( NUM[0] >= 0 ) NUM[1] += 1;} NUM[0] += 10;
	while(NUM[1] >= 0) { NUM[1] -= 10; if ( NUM[1] >= 0 ) NUM[2] += 1;} NUM[1] += 10;
	while(NUM[2] >= 0) { NUM[2] -= 10; if ( NUM[2] >= 0 ) NUM[3] += 1;} NUM[2] += 10;
	while(NUM[3] >= 0) { NUM[3] -= 10; if ( NUM[3] >= 0 ) NUM[4] += 1;} NUM[3] += 10;

}

