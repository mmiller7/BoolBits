/*
 * BoolBits.cpp - Library for storing large arrays of bits efficiently
 * Created by Matthew R Miller, February 14, 2021
 */

#include "BoolBits.h"

//Bit-mask for get/set bit access functitons
static byte BoolBits::BIT_MASK[8] = {
                                 0b00000001,
                                 0b00000010,
                                 0b00000100,
                                 0b00001000,
                                 0b00010000,
                                 0b00100000,
                                 0b01000000,
                                 0b10000000
                               };



BoolBits::BoolBits(int maxSize)
{
	int numBytes=(int) ((maxSize/8.0)+0.5);
	bitStore = new byte[numBytes];

	//Init array with zeros
	for(int x=0; x < numBytes; x++)
	{
		bitStore[x]=0;
	}
}

BoolBits::~BoolBits()
{
	delete[] bitStore;
}


void BoolBits::setBool(int pos, boolean value)
{
	int byte_pos=pos/8;
	int bit_pos=pos%8;
	
	if(value)
	{
		bitStore[byte_pos]=bitStore[byte_pos]|BIT_MASK[bit_pos];
	}
	else
	{
		bitStore[byte_pos]=bitStore[byte_pos]&(~BIT_MASK[bit_pos]);
	}
}

boolean BoolBits::getBool(int pos)
{
	int byte_pos=pos/8;
	int bit_pos=pos%8;
	
	return bitStore[byte_pos]&BIT_MASK[bit_pos];
}

// Averages bits startPos (inclusive) thru endPos (exclusive)
int BoolBits::getAvgBool(int startPos, int endPos)
{
	int sum=0;
	for(int x=startPos; x < endPos; x++)
	{
		if(getBool(x))
		{
			sum++;
		}
	}
	return (sum * 100)/(endPos-startPos);
}

// Float Averages bits startPos (inclusive) thru endPos (exclusive)
float BoolBits::getFloatAvgBool(int startPos, int endPos)
{
	int sum=0;
	for(int x=startPos; x < endPos; x++)
	{
		if(getBool(x))
		{
			sum++;
		}
	}
	return (sum * 100.0)/((float)(endPos-startPos));
}
