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
		float* list = (float*)malloc(result.n_vertices * sizeof(float));
		for (unsigned int i = 0; i < result.n_vertices; i++)
		{
			list[i] = result.vertices[i];
		}
		*pSize = result.n_vertices;
		return list; 
	}


	__int32* GetFaces(uint* pSize)
	{		
		__int32* list = (__int32*)malloc(result.n_triangles * sizeof(__int32));
		for (unsigned int i = 0; i < result.n_triangles; i++)
		{
			list[i] = result.triangles[i];
		}
		*pSize = result.n_triangles;

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



	void EndOp() {
		mesh1 = {};
		mesh2 = {};
		result = {};
	}
}