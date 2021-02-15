/*
 * BoolBits.h - Library for storing large arrays of bits efficiently
 * Created by Matthew R Miller, February 14, 2021
 */

#ifndef BoolBits_h
#define BoolBits_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class BoolBits
{

	public:
	  //Constructor/Destructor
		BoolBits(int maxSize);
		~BoolBits();

		//Data Access Functions
		void setBool(int pos, boolean value);
		boolean getBool(int pos);
		int getAvgBool(int startPos, int endPos);


	private:
		//Pointer to byte array
		byte* bitStore;

		//Bit-mask for get/set bit access functitons
		static byte BIT_MASK[];
};

#endif /* BoolBits_h */
