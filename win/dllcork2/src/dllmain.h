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


		static CorkTriMesh mesh1;
		static CorkTriMesh mesh2;
		static CorkTriMesh result;

		__declspec(dllexport) bool ComputeUnion();
		__declspec(dllexport) bool ComputeIntersection();
		__declspec(dllexport) bool ComputeDifference();
		__declspec(dllexport) bool ComputeSymmetricDifference();

		__declspec(dllexport) uint GetNbVertices();
		__declspec(dllexport) uint GetNbFaces();
		__declspec(dllexport) __int32* GetFaces(uint* pSize);
		__declspec(dllexport) float* GetVertices(uint* pSize);
		__declspec(dllexport) void RemoveIntList(__int32* list);
		__declspec(dllexport) void RemoveFloatList(float* list);

		__declspec(dllexport) bool CreateTriMesh(float vertices_1[], uint n_vertices1, uint faces_1[], uint n_faces_1, int target);		
	}
}

#endif
