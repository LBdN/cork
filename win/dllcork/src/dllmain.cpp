// Win32Project1.cpp : Defines the exported functions for the DLL application.
//


#include "dllmain.h"
#include <stdexcept>

namespace ma {


	Arithmetic::Arithmetic() {
		//TODO: Initialize items here
	}
	Arithmetic::~Arithmetic() {
		//TODO: Release unused items here
	}

	//FUNCTION: adds two values
	float Arithmetic::addition(float& val_1, float& val_2) {
		return val_1 + val_2;
	}
	//FUNCTION: substracts two values
	float Arithmetic::substraction(float& val_1, float& val_2) {
		return val_1 - val_2;
	}
	//FUNCTION: multiplies two values
	float Arithmetic::multiplication(float& val_1, float& val_2) {
		return val_1 * val_2;
	}
	//FUNCTION: divide two values
	float Arithmetic::division(float& val_1, float& val_2) {
		if (val_2 == 0)
			throw new std::invalid_argument("denominator cannot be 0");
		return val_1 / val_2;
	}
}