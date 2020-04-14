#include "build/temp/_test_encoder10bits.c"
#include "build/test/mocks/mock_hardware.h"
#include "src/encoder10bits.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"














void test_setupEncoder(void){



    for (int i = 12; i > 12 - 10; i--){

        pinMode_CMockExpect(14, i, 1);

    }



    setupEncoder();



}



void test_grayDecode(void){







    if ((600 == grayDecode( 884 ))) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(25)));};

}



void test_binToDec(void){

    int rawValues[10] = {1, 1, 1, 1, 1, 1, 0, 0, 0, 0};



    if ((1008 == binToDec( rawValues, 10 ))) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(31)));};

}



void test_leerEncoder(void){





    digitalRead_CMockExpectAndReturn(37, 12, 0);

    digitalRead_CMockExpectAndReturn(38, 11, 0);

    digitalRead_CMockExpectAndReturn(39, 10, 1);

    digitalRead_CMockExpectAndReturn(40, 9, 1);

    digitalRead_CMockExpectAndReturn(41, 8, 0);

    digitalRead_CMockExpectAndReturn(42, 7, 1);

    digitalRead_CMockExpectAndReturn(43, 6, 0);

    digitalRead_CMockExpectAndReturn(44, 5, 1);

    digitalRead_CMockExpectAndReturn(45, 4, 0);

    digitalRead_CMockExpectAndReturn(46, 3, 0);



 if ((200 == leerEncoder())) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(48)));};

}





void test_encoderToDistance(void){



    float tolerancia = 0.1f;

    float radio = 55.00;

    int lecturaEncoder = 512;

    float distanciaEsperada = 172.7825f;



    float distanciaActual = encoderToDistance( lecturaEncoder, radio );



    UnityAssertFloatsWithin((UNITY_FLOAT)((tolerancia)), (UNITY_FLOAT)((distanciaEsperada)), (UNITY_FLOAT)((distanciaActual)), (

   ((void *)0)

   ), (UNITY_UINT)(61));

}



void test_BIN16_A_DIGITAL5( void ){





    BIN16_A_DIGITAL5 ( 128, 1 );



    if ((3 == NUM[4])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(69)));};

    if ((2 == NUM[3])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(70)));};

    if ((7 == NUM[2])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(71)));};

    if ((6 == NUM[1])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(72)));};

    if ((9 == NUM[0])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(73)));};



}





void test_FLOAT_A_LCD_BLE( void ){



    write_lcd_CMockExpect(80, '-');

    write_lcd_CMockExpect(81, '1');

    write_lcd_CMockExpect(82, '2');

    write_lcd_CMockExpect(83, '3');

    write_lcd_CMockExpect(84, '.');

    write_lcd_CMockExpect(85, '4');

    write_lcd_CMockExpect(86, '5');



    float x = -123.45;



    FLOAT_A_LCD_BLE ( x );



    if ((1 == NUM[4])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(92)));};

    if ((2 == NUM[3])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(93)));};

    if ((3 == NUM[2])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(94)));};

    if ((4 == NUM[1])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(95)));};

    if ((5 == NUM[0])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(96)));};

}



void test_FLOAT_A_DIGITAL5( void ){



    float x = 123.45;

    FLOAT_A_DIGITAL5 ( x );



    if ((1 == NUM[4])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(104)));};

    if ((2 == NUM[3])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(105)));};

    if ((3 == NUM[2])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(106)));};

    if ((4 == NUM[1])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(107)));};

    if ((5 == NUM[0])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(108)));};



}
