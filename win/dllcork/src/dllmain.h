#pragma once
#ifndef MATHASSISTANT_ARITHMETICS_ARITHMETIC_H
#define MATHASSISTANT_ARITHMETICS_ARITHMETIC_H

namespace ma {
	extern "C"
	{
		class Arithmetic
		{
		public:
			Arithmetic();//ctor
		protected:
			virtual ~Arithmetic();//dtor
		public:

			static __declspec(dllexport) float addition(float& val_1, float& val_2);
			static __declspec(dllexport) float substraction(float& val_1, float& val_2);
			static __declspec(dllexport) float multiplication(float& val_1, float& val_2);
			static __declspec(dllexport) float division(float& val_1, float& val_2);
		};
	}
}

#endif
