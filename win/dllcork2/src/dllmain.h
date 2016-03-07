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

		static CorkTriMesh* current_mesh;

		__declspec(dllexport) float testcork();
		__declspec(dllexport) bool compute_union(float vertices_1[], int n_vertices1, uint faces_1[], int n_faces_1, 
												  float vertices_2[], int n_vertices2, uint faces_2[], int n_faces_2,
												  HANDLE *outmesh);
		__declspec(dllexport) uint GetNbVertices(HANDLE outmesh);
		__declspec(dllexport) bool createTriMesh(float vertices_1[], int n_vertices1, uint faces_1[], int n_faces_1, HANDLE * outmesh);
		__declspec(dllexport) float addition(float val_1, float val_2);
		__declspec(dllexport) float substraction(float val_1, float val_2);
		__declspec(dllexport) float multiplication(float val_1, float val_2);
		__declspec(dllexport) float division(float val_1, float val_2);
		
	}
}

#endif
