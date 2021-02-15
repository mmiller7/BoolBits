/*
 * BoolBits_NoClass.ino - Example for storing large arrays of bits efficiently
 * Created by Matthew R Miller, February 14, 2021
 * 
 * 
 * Expected compilatiton:
 * ----------------------
 * Sketch uses 2280 bytes (7%) of program storage space. Maximum is 32256 bytes.
 * Global variables use 281 bytes (13%) of dynamic memory, leaving 1767 bytes for local variables. Maximum is 2048 bytes.
 * 
 * 
 * Expected output:
 * ----------------
 * counter=100000
 * Starting
 * Setting true and false...
 * Starting
 * Setting true and false...
 * Time (mS)=465
 * Getting Values...
 * Time (mS)=228
 * 
 * counter=0
 */

#include<BoolBits_NoClass.h>

#define NUM_ITERATIONS 1000 //The number of iterations to set/get
#define DATA_SIZE 100 //The number of bits we are interested in

//Declare a bunch of bits
byte myDataBits[ ((int) ((DATA_SIZE/8.0)+0.5)) ];

void setup() {
  Serial.begin(9600);
  Serial.println("Starting");

  Serial.println("Setting true and false...");
  long etime=millis();
  for(long y=0; y < NUM_ITERATIONS; y++)
  {
    for(int x=0; x < DATA_SIZE; x++)
    {
      setBool(myDataBits, x,true);
    }
    for(int x=0; x < DATA_SIZE; x++)
    {
      setBool(myDataBits, x,false);
    }
  }
  etime=millis()-etime;
  Serial.print("Time (mS)=");
  Serial.println(etime);


  Serial.println("Getting Values...");
  long counter=0;
  etime=millis();
  for(long y=0; y < NUM_ITERATIONS; y++)
  {
    for(int x=0; x < DATA_SIZE; x++)
    {
      if(getBool(myDataBits, x))
      {
        counter++;
        //This will always be false since
        //we set the bits all to zero/false.
        //
        //This is just so its "used"
        //and takes nonzero time after
        //optimizing by the compiler
      }
    }
  }
  etime=millis()-etime;
  Serial.print("Time (mS)=");
  Serial.println(etime);
  
  Serial.println();
  Serial.print("counter=");
  Serial.println(counter);
  
}

void loop() {
}
