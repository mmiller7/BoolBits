/*
 * BoolBits_NoClass.h - Functions for storing large arrays of bits efficiently
 * Created by Matthew R Miller, February 14, 2021
 *
 * You will need to create an array of your own to store your bits, using
 * this form:
 * //DATA_SIZE - the quantity of bits you want to track
 * byte myDataBits[ ((int) ((DATA_SIZE/8.0)+0.5)) ];
 *
 * Note: You will need to pass this array of bytes into the get/set functions 
 *
 * Also, you should probably initialize all the bits to a known value at start
 * if you don't set them before reading.  Can save program memory with care.
 * //Quickly bulk-init array to all zero's
 * for(int x=0; x < ((int) ((DATA_SIZE/8.0)+0.5)); x++)
 * {
 *   myDataBits[x]=0;
 * }
 */

#ifndef BoolBits_NoClass_h
#define BoolBits_NoClass_h

//Bit-mask for get/set bit access functitons
static byte BIT_MASK[8] = {
                 0b00000001,
                 0b00000010,
                 0b00000100,
                 0b00001000,
                 0b00010000,
                 0b00100000,
                 0b01000000,
                 0b10000000
               };

//Data Access Functions
inline void setBool(byte data[], int pos, boolean value)
{
  int byte_pos=pos/8;
  int bit_pos=pos%8;
  
  if(value)
  {
    data[byte_pos]=data[byte_pos]|BIT_MASK[bit_pos];
  }
  else
  {
    data[byte_pos]=data[byte_pos]&(~BIT_MASK[bit_pos]);
  }
}


inline boolean getBool(byte data[], int pos)
{
  int byte_pos=pos/8;
  int bit_pos=pos%8;
  
  return data[byte_pos]&BIT_MASK[bit_pos];
}

// Averages bits startPos (inclusive) thru endPos (exclusive)
inline int getAvgBool(byte data[], int startPos, int endPos)
{
  int sum=0;
  for(int x=startPos; x < endPos; x++)
  {
    if(getBool(data, x))
    {
      sum++;
    }
  }
  return (sum * 100)/(endPos-startPos);
}


#endif /* BoolBits_NoClass_h */
