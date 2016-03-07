// Win32Project1.cpp : Defines the exported functions for the DLL application.
//


#include "dllmain.h"
#include "cork.h"
#include <stdexcept>

namespace ma {

	//typedef void* HANDLE;

	//bool CreateCorkMesh(HANDLE *item) {
	//	item = CorkTriMesh result;
	//}
	//;
	//void DestroyCorkMesh(HANDLE item);
	//int GetNbFaces(HANDLE item);
	//int GetNbVertices(HANDLE item);
	//int* GetVertices(HANDLE item);
	//int* GetFaces(HANDLE item);

	//int * GetFaces(HANDLE item)
	//{
	//	return nullptr;
	//}




	uint GetNbVertices() {		
		return current_mesh.n_vertices;
	};


	uint GetNbFaces() {
		return current_mesh.n_triangles;
	};


	float* GetVertices(uint* pSize)
	{
		float* list = (float*)malloc(current_mesh.n_vertices * sizeof(float));
		for (unsigned int i = 0; i < current_mesh.n_vertices; i++)
		{
			list[i] = current_mesh.vertices[i];
		}
		*pSize = current_mesh.n_vertices;
		return list; 
	}


	__int32* GetFaces(uint* pSize)
	{		
		__int32* list = (__int32*)malloc(current_mesh.n_triangles * sizeof(__int32));
		for (unsigned int i = 0; i < current_mesh.n_triangles; i++)
		{
			list[i] = current_mesh.triangles[i];
		}
		*pSize = current_mesh.n_triangles;

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

	bool createTriMesh(float vertices_1[], int n_vertices1, uint faces_1[], int n_faces_1) {
		CorkTriMesh mesh1 = {
			n_faces_1,
			n_vertices1,
			faces_1,
			vertices_1
		};
		current_mesh = mesh1;
		return true;
	}


	bool compute_union( float vertices_1[], int n_vertices1, uint faces_1[], int n_faces_1, 
					    float vertices_2[], int n_vertices2, uint faces_2[], int n_faces_2){
		CorkTriMesh mesh1 = {
			n_faces_1,
			n_vertices1,
			faces_1,
			vertices_1
		};
	
		CorkTriMesh mesh2 = {
			n_faces_2,
			n_vertices2,
			faces_2,
			vertices_2
		};
	
	//CorkTriMesh result;
	
	isSolid(mesh1);
	
	bool ok = isSolid(mesh2);
	
	computeUnion(mesh1, mesh2, &current_mesh);
	//current_mesh = &result;

	/*freeCorkTriMesh(&mesh1);
	freeCorkTriMesh(&mesh2);*/
	
	return true;
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