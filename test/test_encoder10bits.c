

#include "unity.h"

#include "encoder10bits.h"

#include "mock_hardware.h"



void test_setupEncoder(void){

    //Testeo que pinMode es llamado con los 
    //argumentos correctos el número de veces correcto
    //los GPIO están en orden y van del LSB-BITS al LSB

    for (int i = LSB; i > LSB - BITS; i--){
        pinMode_Expect( i , INPUT_PULLUP );
    }

    setupEncoder();
}

void test_grayDecode(void){

    //Testeo que grayDecode de los valores enteros correctos en 
    //los extremos (0-1023) y en un valor intermedio arbitrario (600)

    //Dec 0 = Bin 0 = Grey 0 
    int numEnCodGrey = 0b0;
    int numEnDecimal = 0;
    TEST_ASSERT( numEnDecimal == grayDecode( numEnCodGrey ) );
    
    //Dec 600 = Bin 10.0101.1000 = Grey 11.0111.0100 -> Bin 11.0111.0100 = Dec 884
    numEnCodGrey = 0b1101110100;
    numEnDecimal = 600;
    TEST_ASSERT( numEnDecimal == grayDecode( numEnCodGrey ) );

    //Dec 1023 = Bin 11.1111.1111 = Grey 10.0000.0000 -> Bin 10.0000.0000 = Dec 512
    numEnCodGrey = 0b1000000000;
    numEnDecimal = 1023;
    TEST_ASSERT( numEnDecimal == grayDecode( numEnCodGrey ) );
}

void test_binToDec(void){

    //Testeo que binToDec de los valores enteros correctos en 
    //los extremos (0-1023) y en un valor intermedio arbitrario (700)

    //Dec 0 = Bin 00.0000.0000 
    int rawValues[BITS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
    int numEnDecimal = 0;

    TEST_ASSERT( numEnDecimal == binToDec( rawValues, BITS ) );

    //Dec 700 = Bin 10.1011.1100 
    rawValues[0] = 1; rawValues[1] = 0; rawValues[2] = 1; rawValues[3] = 0; rawValues[4] = 1;
    rawValues[5] = 1; rawValues[6] = 1; rawValues[7] = 1; rawValues[8] = 0; rawValues[9] = 0;
    numEnDecimal = 700;

    TEST_ASSERT( numEnDecimal == binToDec( rawValues, BITS ) );

    //Dec 1023 = Bin 11.1111.1111 
    rawValues[0] = 1; rawValues[1] = 1; rawValues[2] = 1; rawValues[3] = 1; rawValues[4] = 1;
    rawValues[5] = 1; rawValues[6] = 1; rawValues[7] = 1; rawValues[8] = 1; rawValues[9] = 1;
    numEnDecimal = 1023;

    TEST_ASSERT( numEnDecimal == binToDec( rawValues, BITS ) );

}

void test_leerEncoder(void){

    //Testeo que leerEncoder de los valores enteros correctos 
    //en un valor intermedio arbitrario (200)
    //Nota: En elcoder entrega su salida en código de Grey

    //DEC 200 = GREY 10101100
    int numEnDecimal = 200;

    digitalRead_ExpectAndReturn( LSB-0, 0 );
    digitalRead_ExpectAndReturn( LSB-1, 0 );
    digitalRead_ExpectAndReturn( LSB-2, 1 );
    digitalRead_ExpectAndReturn( LSB-3, 1 );
    digitalRead_ExpectAndReturn( LSB-4, 0 );
    digitalRead_ExpectAndReturn( LSB-5, 1 );
    digitalRead_ExpectAndReturn( LSB-6, 0 );
    digitalRead_ExpectAndReturn( LSB-7, 1 );
    digitalRead_ExpectAndReturn( LSB-8, 0 );
    digitalRead_ExpectAndReturn( LSB-9, 0 );

	TEST_ASSERT( numEnDecimal == leerEncoder() ); 
}


void test_encoderToDistance(void){

    //Testeo que encoderToDistance de los valores decimales 
    //en un valor intermedio arbitrario del encoder (512)
    //con una tolerancia arbitraria y con un radio arbitrario
    //Nota: El encoder está conectado a una rueda con la que 
    //      se mide el desplazamiento

    float tolerancia = 0.1f;
    float radio = 55.00;
    int   lecturaEncoder = 512;
    float despEsperado = 172.7825f;

    float despActual = encoderToDistance( lecturaEncoder, radio );

    TEST_ASSERT_FLOAT_WITHIN(tolerancia, despEsperado, despActual);
}

void test_BIN16_A_DIGITAL5( void ){

    //Testeo que BIN16_A_DIGITAL5 de los valores enteros 
    //correctos en el arreglo NUM[5], tomando dos bytes
    //arbitrarios 128 y 1 
    //1000 0000 - 0000 0001 = 128 - 1 = Dec 32769
    uint8_t byte1 = 128;
    uint8_t byte2 = 1;

    BIN16_A_DIGITAL5 ( byte1, byte2 );

    TEST_ASSERT( 3 == NUM[4] );
    TEST_ASSERT( 2 == NUM[3] );
    TEST_ASSERT( 7 == NUM[2] );
    TEST_ASSERT( 6 == NUM[1] );
    TEST_ASSERT( 9 == NUM[0] );

}

void test_FLOAT_A_DIGITAL5( void ){

    //Testeo que FLOAT_A_DIGITAL5 de los valores  
    //correctos en el arreglo NUM[5], tomando un float arbitrario
    //esta función utiliza BIN16_A_DIGITAL5 testeada previamente

    float unFloat = 123.45f;

    FLOAT_A_DIGITAL5 ( unFloat );

    TEST_ASSERT( 1 == NUM[4] );
    TEST_ASSERT( 2 == NUM[3] );
    TEST_ASSERT( 3 == NUM[2] );
    TEST_ASSERT( 4 == NUM[1] );
    TEST_ASSERT( 5 == NUM[0] );

}

void test_FLOAT_A_LCD_BLE( void ){

    //Testeo que FLOAT_A_LCD_BLE de los valores  
    //correctos en el arreglo TxtBLE[10] y 
    //          en la función write_lcd(uint8_t) 
    //tomando un float arbitrario
    //esta función utiliza FLOAT_A_DIGITAL5 testeada previamente

    write_lcd_Expect( '-' );
    write_lcd_Expect( '1' );
    write_lcd_Expect( '2' );
    write_lcd_Expect( '3' );
    write_lcd_Expect( '.' );
    write_lcd_Expect( '4' );
    write_lcd_Expect( '5' );

    float unFloat = -123.45;

    FLOAT_A_LCD_BLE ( unFloat );

     TEST_ASSERT( TxtBLE[0] == ' ' )
     TEST_ASSERT( TxtBLE[1] == ' ' )
     TEST_ASSERT( TxtBLE[2] == ' ' )
     TEST_ASSERT( TxtBLE[3] == '-' )
     TEST_ASSERT( TxtBLE[4] == '1' )
     TEST_ASSERT( TxtBLE[5] == '2' )
     TEST_ASSERT( TxtBLE[6] == '3' )
     TEST_ASSERT( TxtBLE[7] == '.' )
     TEST_ASSERT( TxtBLE[8] == '4' )
     TEST_ASSERT( TxtBLE[9] == '5' )
}







