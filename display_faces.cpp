//function to print all faces with their required information
#include "main.hpp"
using namespace std;
void dcel::display_faces(FILE * outfilepr){
  fprintf(outfilepr, "\nFaces:");
  for(int i = 0; i < this->faces.size(); i++){
    vector<int> face_hedges; //stores all the halfedge indices that belong to the current face
    face_hedges.push_back(this->faces[i]->incident_hedge->hedge_index);
    hedge * temp;
    temp = this->faces[i]->incident_hedge;
    for(; ; ){
      temp = temp->find_nextedge();
      if(temp != this->faces[i]->incident_hedge) face_hedges.push_back(temp->hedge_index); 
      else break;
    }
    fprintf(outfilepr, "\nFaceIndex:%d Edges ", this->faces[i]->face_index);
    for(int i = 0; i < face_hedges.size(); i++){
      fprintf(outfilepr, "%d", face_hedges[i]);
      if(i != (face_hedges.size() - 1)) fprintf(outfilepr, "->");
    }
  }
}