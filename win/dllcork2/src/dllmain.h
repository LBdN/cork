#pragma once
#ifndef MATHASSISTANT_ARITHMETICS_ARITHMETIC_H
#define MATHASSISTANT_ARITHMETICS_ARITHMETIC_H
#include <cork.h>

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

		typedef void* HANDLE;

		static CorkTriMesh current_mesh;

		__declspec(dllexport) float testcork();
		__declspec(dllexport) bool compute_union(float vertices_1[], int n_vertices1, uint faces_1[], int n_faces_1, 
												  float vertices_2[], int n_vertices2, uint faces_2[], int n_faces_2);
		__declspec(dllexport) uint GetNbVertices();
		__declspec(dllexport) uint GetNbFaces();
		__declspec(dllexport) __int32* GetFaces(uint* pSize);
		__declspec(dllexport) float* GetVertices(uint* pSize);
		__declspec(dllexport) void RemoveIntList(__int32* list);
		__declspec(dllexport) void RemoveFloatList(float* list);

		__declspec(dllexport) bool createTriMesh(float vertices_1[], int n_vertices1, uint faces_1[], int n_faces_1);
		__declspec(dllexport) float addition(float val_1, float val_2);
		__declspec(dllexport) float substraction(float val_1, float val_2);
		__declspec(dllexport) float multiplication(float val_1, float val_2);
		__declspec(dllexport) float division(float val_1, float val_2);
		
	}
}

#endif
