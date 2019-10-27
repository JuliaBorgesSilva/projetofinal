#include <LedControl.h>

/**
* Led Matrix test
*/


#include <LedControl.h>

#define DATA_PIN    P1_3        // data for AS1106
#define CLOCK_PIN   P1_4        // clock for AS1106
#define LOAD_PIN    P1_5        // load CS for AS1106

// LedControl(int dataPin, int clkPin, int csPin, int numDevices=1);
LedControl lc=LedControl(DATA_PIN, CLOCK_PIN, LOAD_PIN, 1);

unsigned long delaytime=100;


void setup() {

  pinMode(RED_LED,OUTPUT);
  pinMode(DATA_PIN,OUTPUT);
  pinMode(CLOCK_PIN,OUTPUT);
  pinMode(LOAD_PIN,OUTPUT);
  digitalWrite(LOAD_PIN,HIGH);
  digitalWrite(RED_LED, HIGH);
  delay(1000);
  digitalWrite(RED_LED, LOW);

  /*lc.init(); */
  lc.shutdown(0,false);
  lc.setIntensity(0,10);
  lc.clearDisplay(0);

}
byte piece[7][2] = {
  {B00111000,B00010000}, //t,
  {B00010000,B11110000}, //j
  {B00110000,B01100000}, //s
  {B01100000,B00110000}, //z
  {B01100000,B01100000}, //o
  {B11110000,B00010000}, //l
  {B00111100,B00000000} //i
  };
int blocktype;
void loop() {
  
  digitalWrite(RED_LED, HIGH);
  lc.clearDisplay(0);
   blocktype = random(7);

   for (int r=0; r<1; r++){
    for (int c=0; c<8; c++){
        lc.setColumn(0,c, piece[blocktype][0] );
        lc.setColumn(0,c+1,piece[blocktype][1]);
        if (c>0){
         lc.setColumn(0,c-1, B00000000);
        }
        
        else if(c==0){
        lc.setColumn(0,7, B00000000);
        
        }
        delay(250);
      
    }
   }
}
  /*digitalWrite(RED_LED, LOW);
  lc.clearDisplay(0);
  lc.setColumn(0, 1, B01010101);
        delay(1000);
  lc.setColumn(0, 3, B01010101);
        delay(1000);
  lc.setRow(0, 1, B01010101);
        delay(1000);
  lc.setRow(0, 3, B01010101);
        delay(1000);

  delay(10); */  
