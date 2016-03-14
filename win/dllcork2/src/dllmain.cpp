// Win32Project1.cpp : Defines the exported functions for the DLL application.
//


#include "dllmain.h"
#include "cork.h"
#include <stdexcept>

namespace ma {

	uint GetNbVertices() {		
		return result.n_vertices;
	};


	uint GetNbFaces() {
		return result.n_triangles;
	};


	float* GetVertices(uint* pSize)
	{
		int n_float = result.n_vertices * 3;
		float* list = (float*)malloc(n_float * sizeof(float));
		for (unsigned int i = 0; i < n_float; i++)
		{
			list[i] = result.vertices[i];
		}
		*pSize = n_float;
		return list; 
	}


	__int32* GetFaces(uint* pSize)
	{		
		unsigned int n_int = result.n_triangles * 3;
		__int32* list = (__int32*)malloc(n_int * sizeof(__int32));
		for (unsigned int i = 0; i < n_int; i++)
		{
			list[i] = result.triangles[i];
		}
		*pSize = n_int;

		return list;
	}

	void RemoveIntList(__int32* list)
	{
		free(list);
	}


	void RemoveFloatList(float* list)
	{
		free(list);
	}

	bool CreateTriMesh(float vertices_1[], uint n_vertices1, uint faces_1[], uint n_faces_1, int target) {

		if (target == 1) {
			mesh1 = {
				n_faces_1,
				n_vertices1,
				faces_1,
				vertices_1
			};
			return true;
		}
		if (target == 2) {
			mesh2 = {
				n_faces_1,
				n_vertices1,
				faces_1,
				vertices_1
			};
			return true;
		}		
			
		return false;
	}


	bool ComputeUnion( ){

		result = {};
		
		if (!isSolid(mesh1) || !isSolid(mesh2)) {
			return false;
		}
	
		computeUnion(mesh1, mesh2, &result);
		//current_mesh = &result;

		//freeCorkTriMesh(&mesh1);
		//freeCorkTriMesh(&mesh2);
	
		return true;
	}

	bool ComputeIntersection() {

		result = {};

		if (!isSolid(mesh1) || !isSolid(mesh2)) {
			return false;
		}

		computeIntersection(mesh1, mesh2, &result);
		//current_mesh = &result;

		//freeCorkTriMesh(&mesh1);
		//freeCorkTriMesh(&mesh2);

		return true;
	}

	bool ComputeDifference() {

		result = {};

		if (!isSolid(mesh1) || !isSolid(mesh2)) {
			return false;
		}

		computeDifference(mesh1, mesh2, &result);
		//current_mesh = &result;

		//freeCorkTriMesh(&mesh1);
		//freeCorkTriMesh(&mesh2);

		return true;
	}

	bool ComputeSymmetricDifference() {

		result = {};

		if (!isSolid(mesh1) || !isSolid(mesh2)) {
			return false;
		}

		computeSymmetricDifference(mesh1, mesh2, &result);
		//current_mesh = &result;

		//freeCorkTriMesh(&mesh1);
		//freeCorkTriMesh(&mesh2);

		return true;
	}

	void MoveResultToMesh1() {
	
		mesh1.n_triangles = result.n_triangles;
		mesh1.n_vertices = result.n_vertices;
		mesh1.triangles = result.triangles;
		mesh1.vertices = result.vertices;

		result.n_triangles = 0 ;
		result.n_vertices = 0 ;
		result.triangles = nullptr;
		result.vertices = nullptr;

		//result = {};
	}


	void EndOp() {
		mesh1 = {};
		mesh2 = {};
		result = {};
	}
}