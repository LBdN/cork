/* This file is part of PyMesh. Copyright (c) 2015 by Qingnan Zhou */
#pragma once

#include <memory>
#include <string>
#include <EigenTypedef.h>

class BooleanEngine {
    public:
        /*typedef std::shared_ptr<BooleanEngine> Ptr;
        static Ptr create();*/
		//virtual BooleanEngine() {}

    public:
        virtual ~BooleanEngine() {}

    public:

		MatrixFr convert_to_eigenF(double vertices[], int nb_vertices, int vertex_length) {
			MatrixFr eigenM (nb_vertices, vertex_length);
			std::copy(vertices, vertices + nb_vertices*vertex_length, eigenM.data());
			return eigenM;
		}

		MatrixIr convert_to_eigenI(int faces[], int nb_faces, int face_length) {
			MatrixIr eigenM(nb_faces, face_length);
			std::copy(faces, faces + nb_faces*face_length, eigenM.data());
			return eigenM;
		}

		void set_mesh(double vertices[], int nb_vertices, int vertex_length,
							  int faces[], int nb_faces, int face_length,
							  int target) {
			MatrixFr verticesM = convert_to_eigenF(vertices, nb_vertices, vertex_length);
			MatrixIr facesM = convert_to_eigenI(faces, nb_faces, face_length);
			if (target == 1) {
				set_mesh_1(verticesM, facesM);
			}
			else {
				set_mesh_2(verticesM, facesM);
			}
		}


        void set_mesh_1(const MatrixFr& vertices, const MatrixIr& faces) {
            m_vertices_1 = vertices;
            m_faces_1 = faces;
        }

        void set_mesh_2(const MatrixFr& vertices, const MatrixIr& faces) {
            m_vertices_2 = vertices;
            m_faces_2 = faces;
        }

		void extract_mesh(MatrixFr& vertices, MatrixIr& faces, double* out_vertices, int* out_triangles) {
			out_vertices  = vertices.data();
			out_triangles = faces.data();
		}

        const MatrixFr get_vertices() const { return m_vertices; }
        const MatrixIr get_faces() const { return m_faces; }
        void clean_up();

    public:
        virtual void compute_union() =0;
        virtual void compute_intersection() =0;
        virtual void compute_difference() =0;
        virtual void compute_symmetric_difference() =0;
        virtual VectorI get_face_sources() const {
            return VectorI::Zero(0);
        };

        virtual void serialize_xml(const std::string& filename) const;

    //protected:
    //    void remove_duplicated_vertices();
    //    void remove_short_edges();
    //    void remove_isolated_vertices();

    protected:
        MatrixFr m_vertices_1;
        MatrixIr m_faces_1;

        MatrixFr m_vertices_2;
        MatrixIr m_faces_2;

        MatrixFr m_vertices;
        MatrixIr m_faces;
};
