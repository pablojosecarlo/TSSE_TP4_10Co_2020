#include "build/temp/_test_encoder10bits.c"
#include "build/test/mocks/mock_hardware.h"
#include "src/encoder10bits.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"














void test_setupEncoder(void){











    for (int i = 12; i > 12 - 10; i--){

        pinMode_CMockExpect(18, i, 1);

    }



    setupEncoder();

}



void test_grayDecode(void){











    int numEnCodGrey = 0b0;

    int numEnDecimal = 0;

    if ((numEnDecimal == grayDecode( numEnCodGrey ))) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(32)));};





    numEnCodGrey = 0b1101110100;

    numEnDecimal = 600;

    if ((numEnDecimal == grayDecode( numEnCodGrey ))) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(37)));};





    numEnCodGrey = 0b1000000000;

    numEnDecimal = 1023;

    if ((numEnDecimal == grayDecode( numEnCodGrey ))) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(42)));};

}



void test_binToDec(void){











    int rawValues[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int numEnDecimal = 0;



    if ((numEnDecimal == binToDec( rawValues, 10 ))) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(54)));};





    rawValues[0] = 1; rawValues[1] = 0; rawValues[2] = 1; rawValues[3] = 0; rawValues[4] = 1;

    rawValues[5] = 1; rawValues[6] = 1; rawValues[7] = 1; rawValues[8] = 0; rawValues[9] = 0;

    numEnDecimal = 700;



    if ((numEnDecimal == binToDec( rawValues, 10 ))) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(61)));};





    rawValues[0] = 1; rawValues[1] = 1; rawValues[2] = 1; rawValues[3] = 1; rawValues[4] = 1;

    rawValues[5] = 1; rawValues[6] = 1; rawValues[7] = 1; rawValues[8] = 1; rawValues[9] = 1;

    numEnDecimal = 1023;



    if ((numEnDecimal == binToDec( rawValues, 10 ))) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(68)));};



}



void test_leerEncoder(void){













    int numEnDecimal = 200;



    digitalRead_CMockExpectAndReturn(81, 12 -0, 0);

    digitalRead_CMockExpectAndReturn(82, 12 -1, 0);

    digitalRead_CMockExpectAndReturn(83, 12 -2, 1);

    digitalRead_CMockExpectAndReturn(84, 12 -3, 1);

    digitalRead_CMockExpectAndReturn(85, 12 -4, 0);

    digitalRead_CMockExpectAndReturn(86, 12 -5, 1);

    digitalRead_CMockExpectAndReturn(87, 12 -6, 0);

    digitalRead_CMockExpectAndReturn(88, 12 -7, 1);

    digitalRead_CMockExpectAndReturn(89, 12 -8, 0);

    digitalRead_CMockExpectAndReturn(90, 12 -9, 0);



 if ((numEnDecimal == leerEncoder())) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(92)));};

}





void test_encoderToDistance(void){















    float tolerancia = 0.1f;

    float radio = 55.00;

    int lecturaEncoder = 512;

    float despEsperado = 172.7825f;



    float despActual = encoderToDistance( lecturaEncoder, radio );



    UnityAssertFloatsWithin((UNITY_FLOAT)((tolerancia)), (UNITY_FLOAT)((despEsperado)), (UNITY_FLOAT)((despActual)), (

   ((void *)0)

   ), (UNITY_UINT)(111));

}



void test_BIN16_A_DIGITAL5( void ){











    uint8_t byte1 = 128;

    uint8_t byte2 = 1;



    BIN16_A_DIGITAL5 ( byte1, byte2 );



    if ((3 == NUM[4])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(125)));};

    if ((2 == NUM[3])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(126)));};

    if ((7 == NUM[2])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(127)));};

    if ((6 == NUM[1])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(128)));};

    if ((9 == NUM[0])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(129)));};



}



void test_FLOAT_A_DIGITAL5( void ){











    float unFloat = 123.45f;



    FLOAT_A_DIGITAL5 ( unFloat );



    if ((1 == NUM[4])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(143)));};

    if ((2 == NUM[3])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(144)));};

    if ((3 == NUM[2])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(145)));};

    if ((4 == NUM[1])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(146)));};

    if ((5 == NUM[0])) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(147)));};



}



void test_FLOAT_A_LCD_BLE( void ){















    write_lcd_CMockExpect(159, '-');

    write_lcd_CMockExpect(160, '1');

    write_lcd_CMockExpect(161, '2');

    write_lcd_CMockExpect(162, '3');

    write_lcd_CMockExpect(163, '.');

    write_lcd_CMockExpect(164, '4');

    write_lcd_CMockExpect(165, '5');



    float unFloat = -123.45;



    FLOAT_A_LCD_BLE ( unFloat );



     if ((TxtBLE[0] == ' ')) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(171)));}

     if ((TxtBLE[1] == ' ')) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(172)));}

     if ((TxtBLE[2] == ' ')) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(173)));}

     if ((TxtBLE[3] == '-')) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(174)));}

     if ((TxtBLE[4] == '1')) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(175)));}

     if ((TxtBLE[5] == '2')) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(176)));}

     if ((TxtBLE[6] == '3')) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(177)));}

     if ((TxtBLE[7] == '.')) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(178)));}

     if ((TxtBLE[8] == '4')) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(179)));}

     if ((TxtBLE[9] == '5')) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(180)));}

}
