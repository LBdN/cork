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


	void compute_union(float vertices_1[], int n_vertices1, uint faces_1[], int n_faces_1, 
							  float vertices_2[], int n_vertices2, uint faces_2[], int n_faces_2){
		//CorkTriMesh mesh1 = {
		//	n_faces_1,
		//	n_vertices1,
		//	faces_1,
		//	vertices_1
		//};
		//CorkTriMesh mesh2 = {
		//	n_faces_2,
		//	n_vertices2,
		//	faces_2,
		//	vertices_2
		//};
	
	/*CorkTriMesh result;	*/
	

	//computeUnion(mesh1, mesh2, &result);

	/*freeCorkTriMesh(&mesh1);
	freeCorkTriMesh(&mesh2);*/
	
	return;
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