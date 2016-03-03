// Win32Project1.cpp : Defines the exported functions for the DLL application.
//


#include "dllmain.h"
#include "cork.h"
#include <stdexcept>

namespace ma {


	float testcork() {
		if (false) {
			CorkTriMesh corkmesh = {};
			//computeDifference(NULL, NULL, corkmesh*);				
		}
		return 42;
	}


	//FUNCTION: adds two values
	float addition(float val_1, float val_2) {
		return val_1 + val_2;
	}
	//FUNCTION: substracts two values
	float substraction(float val_1, float val_2) {
		return val_1 - val_2;
	}
	//FUNCTION: multiplies two values
	float multiplication(float val_1, float val_2) {
		return val_1 * val_2;
	}
	//FUNCTION: divide two values
	float division(float val_1, float val_2) {
		if (val_2 == 0)
			throw new std::invalid_argument("denominator cannot be 0");
		return val_1 / val_2;
	}
}