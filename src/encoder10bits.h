
//Encoder de 10 bits 

#include <stdio.h>
#include <stdint.h>

//typedef enum { TRUE, FALSE } bool_t;

//Definiciones del encoder de 10 bits
#define BITS 10
#define LSB 12
#define INPUT_PULLUP 1
#define ON 1
#define OFF 0
#define TRUE 1
#define FALSE 0 
#define LAST_STATUS_REG_SET 0b00000000

int8_t  NUM[5];// = { 0, 0, 0, 0, 0 };
uint8_t TxtBLE[9];
uint8_t TxtSTS[16];

//El encoder de 10 bits
void setupEncoder( void );
int  leerEncoder ( void );
int  grayDecode  ( unsigned int );
int  binToDec    ( int *, int );
float encoderToDistance( int xEncoder, float );
void FLOAT_A_LCD_BLE ( float );
void FLOAT_A_DIGITAL5( float );
void BIN16_A_DIGITAL5( uint8_t, uint8_t );


