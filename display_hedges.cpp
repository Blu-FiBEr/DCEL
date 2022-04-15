//function to display all halfedges and required information
#include "main.hpp"
using namespace std;
void dcel::display_hedges(FILE * outfilepr){
  fprintf(outfilepr, "\nHalfedges:");
  
  //iterate through all faces thus making sure that all hedges that are not in "infinite_face" are printed.
  for(int i = 0; i < this->faces.size(); i++){
    //traverse each face to print all hedges of that face
    hedge* traverse = this->faces[i]->incident_hedge;
    do{
      fprintf(outfilepr, "\nstartVertexIndex=%d endVertexIndex=%d nextEdge=%d previousEdge=%d faceIndex=%d edgeIndex=%d", traverse->start_vertex->vertex_index, traverse->find_endvertex()->vertex_index, traverse->find_nextedge()->hedge_index, traverse->find_previousedge()->hedge_index, traverse->incident_face->face_index, traverse->hedge_index);
      traverse = traverse->find_nextedge();
    } while((traverse != this->faces[i]->incident_hedge)) ;
  }
}