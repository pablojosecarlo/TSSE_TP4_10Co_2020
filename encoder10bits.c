////////////////////////////ENCODER 10 BITS//////////////////////////////////

//Definiciones del encoder de 12 bits
#define BITS 10
#define LSB 12


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
    readVal = !digitalRead(i);
    rawValues[j] = readVal; 
    j--;
  }

  result = binToDec(rawValues, BITS); 
  result = gray_decode(result); 

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

int gray_decode(unsigned int n) { 
  unsigned int p = n;
  while ( n = n >> 1) p = p ^ n;
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

