/* This file is part of PyMesh. Copyright (c) 2015 by Qingnan Zhou */
#include "BooleanEngine.h"

#include "Cork/CorkEngine.h"



#include <sstream>
#include <iostream>

#include <Exception.h>
//#include <MeshUtils/DuplicatedVertexRemoval.h>
//#include <MeshUtils/IsolatedVertexRemoval.h>
//#include <MeshUtils/ShortEdgeRemoval.h>

//BooleanEngine::Ptr BooleanEngine::create() {
//    return Ptr(new CorkEngine()); 
//}

void BooleanEngine::clean_up() {
	return;
    /*remove_duplicated_vertices();
    remove_short_edges();
    remove_isolated_vertices();*/
}
//
//void BooleanEngine::remove_duplicated_vertices() {
//    DuplicatedVertexRemoval remover(m_vertices, m_faces);
//    size_t num_removed = remover.run(1e-6);
//    m_vertices = remover.get_vertices();
//    m_faces = remover.get_faces();
//}
//
//void BooleanEngine::remove_short_edges() {
//    ShortEdgeRemoval remover(m_vertices, m_faces);
//    size_t num_removed = remover.run(1e-6);
//    m_vertices = remover.get_vertices();
//    m_faces = remover.get_faces();
//}
//
//void BooleanEngine::remove_isolated_vertices() {
//    IsolatedVertexRemoval remover(m_vertices, m_faces);
//    size_t num_removed = remover.run();
//    m_vertices = remover.get_vertices();
//    m_faces = remover.get_faces();
//}
//
void BooleanEngine::serialize_xml(const std::string& filename) const {
    //throw NotImplementedError("Serialization is not supported");
	throw new std::invalid_argument("Serialization is not supported");
}
