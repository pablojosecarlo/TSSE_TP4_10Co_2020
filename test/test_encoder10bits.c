

#include "unity.h"

#include "encoder10bits.h"

#include "mock_hardware.h"



void test_setupEncoder(void){
    
    for (int i = LSB; i > LSB - BITS; i--){
        pinMode_Expect( i , INPUT_PULLUP );
    }    

    setupEncoder();
	
}

void test_grayDecode(void){
//Dec 600 = Bin 1001011000 = Grey 1101110100
//Bin 1101110100 = Dec 884

    TEST_ASSERT( 600 == grayDecode( 884 ) );
}

void test_binToDec(void){
    int rawValues[BITS] = {1, 1, 1, 1, 1, 1, 0, 0, 0, 0}; //= Dec 1008

    TEST_ASSERT( 1008 == binToDec( rawValues, BITS ) );
}

void test_leerEncoder(void){

  //DEC 200 = GREY 10101100
    digitalRead_ExpectAndReturn( 12, 0 );
    digitalRead_ExpectAndReturn( 11, 0 );
    digitalRead_ExpectAndReturn( 10, 1 );
    digitalRead_ExpectAndReturn( 9 , 1 );
    digitalRead_ExpectAndReturn( 8 , 0 );
    digitalRead_ExpectAndReturn( 7 , 1 );
    digitalRead_ExpectAndReturn( 6 , 0 );
    digitalRead_ExpectAndReturn( 5 , 1 );
    digitalRead_ExpectAndReturn( 4 , 0 );
    digitalRead_ExpectAndReturn( 3 , 0 );

	TEST_ASSERT( 200 == leerEncoder() ); //GREY 10101100
}


void test_encoderToDistance(void){

    float tolerancia = 0.1f;
    float radio = 55.00;
    int   lecturaEncoder = 512;
    float distanciaEsperada = 172.7825f;

    float distanciaActual = encoderToDistance( lecturaEncoder, radio );

    TEST_ASSERT_FLOAT_WITHIN(tolerancia, distanciaEsperada, distanciaActual);
}

void test_BIN16_A_DIGITAL5( void ){

    //1000 0000 - 0000 0001 = 128 - 1 = Dec 32769
    BIN16_A_DIGITAL5 ( 128, 1 );

    TEST_ASSERT( 3 == NUM[4] );
    TEST_ASSERT( 2 == NUM[3] );
    TEST_ASSERT( 7 == NUM[2] );
    TEST_ASSERT( 6 == NUM[1] );
    TEST_ASSERT( 9 == NUM[0] );

}


void test_FLOAT_A_LCD_BLE( void ){

    write_lcd_Expect( '-' );
    write_lcd_Expect( '1' );
    write_lcd_Expect( '2' );
    write_lcd_Expect( '3' );
    write_lcd_Expect( '.' );
    write_lcd_Expect( '4' );
    write_lcd_Expect( '5' );

    float x = -123.45;

    FLOAT_A_LCD_BLE ( x );

    TEST_ASSERT( 1 == NUM[4] );
    TEST_ASSERT( 2 == NUM[3] );
    TEST_ASSERT( 3 == NUM[2] );
    TEST_ASSERT( 4 == NUM[1] );
    TEST_ASSERT( 5 == NUM[0] );
}

void test_FLOAT_A_DIGITAL5( void ){

    float x = 123.45;
    FLOAT_A_DIGITAL5 ( x );

    TEST_ASSERT( 1 == NUM[4] );
    TEST_ASSERT( 2 == NUM[3] );
    TEST_ASSERT( 3 == NUM[2] );
    TEST_ASSERT( 4 == NUM[1] );
    TEST_ASSERT( 5 == NUM[0] );

}





