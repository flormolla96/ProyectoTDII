define sw1  17
#define sw2  27

#include "EasyPIO.h"


void main(void){
int leds[]= {23, 24, 25, 12, 16, 20, 21, 26};
int i,k,l,s;
int c,d;
int tabla1[]={   0b00000001,
                                0b10000000,
                0b00000010,
                                0b01000000,
                0b00000100,
                                0b00100000,
                0b00001000,
                                0b00010000,
                0b00010000,
                                0b00001000,
                0b00100000,
                                0b00000100,
                0b01000000,
                                0b00000010,
                0b10000000,
                                0b00000001};
int tabla2[]={   0b00000001,
                                0b00000010,
                0b00000100,
                                0b00001000,
                0b00010000,
                                0b00100000,
                0b01000000,
                                0b10000000,
                0b10000000,
                                0b01000000,
                0b00100000,
                                0b00010000,
                0b00001000,
                                0b00000100,
                0b00000010,
                                0b00000001};

        pioInit();                       //No olvidarse de pioInit
        pinMode(sw1,INPUT);
        for(int j=0;j<8;j++){
        pinMode(leds[j], OUTPUT);}
do{

for(k=0;k<16;k++){

        for(i=0;i<8;i++){
                c = 0b00000001 << i;   //Voy desplazando un 1 en cada iteracion  
        digitalWrite(leds[i],tabla1[k] & (c));  //hago una AND entre el 1 y el valor de la tabla correspondiente
        }
        usleep(150000);
        if(digitalRead(sw1)==1)break;
}

for(l=0;l<16;l++){

        for(s=0;s<8;s++){
                d = 0b00000001 << s;   //Voy desplazando un 1 en cada iteracion$
        digitalWrite(leds[s],tabla2[l] & (d));  //hago una AND entre el 1 y el v$
        }
        usleep(150000);
        if(digitalRead(sw1)==1)break;
}

}while(digitalRead(sw1)!=1);



}




