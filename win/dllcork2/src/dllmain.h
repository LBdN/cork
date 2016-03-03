#pragma once
#ifndef MATHASSISTANT_ARITHMETICS_ARITHMETIC_H
#define MATHASSISTANT_ARITHMETICS_ARITHMETIC_H


#if UNITY_METRO
#define EXPORT_API __declspec(dllexport) __stdcall
#elif UNITY_WIN
#define EXPORT_API __declspec(dllexport)
#else
#define EXPORT_API
#endif



namespace ma {
	extern "C"
	{
		__declspec(dllexport) float testcork();
		__declspec(dllexport) float addition(float val_1, float val_2);
		__declspec(dllexport) float substraction(float val_1, float val_2);
		__declspec(dllexport) float multiplication(float val_1, float val_2);
		__declspec(dllexport) float division(float val_1, float val_2);
		
	}
}

#endif
