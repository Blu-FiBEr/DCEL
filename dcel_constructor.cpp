#include "main.hpp"
using namespace std;
//dcel constructor
dcel::dcel(vector<vertex*> &input_vertices){
  this->vertices = input_vertices;
  
  //initialized for a general closed polygon
  //number of edges in polygon is same as number of vertices
  int n = this->vertices.size();
  
  //initialization
  this->edges = vector<edge*>();
  this->hedges = vector<hedge*>();
  this->faces = vector<face*>();
  
  //creating required edges and hedges
  for(int i = 0; i < n; i++){
    pair<hedge*, hedge*> new_hedges;      //to access the newly formed hedges corresponding to the new edge
    edge* temp = new edge(this->vertices[i%n], this->vertices[(i + 1)%n], new_hedges);
    this->edges.push_back(temp);
    this->hedges.push_back(new_hedges.first);
    this->hedges.push_back(new_hedges.second);
    this->vertices[i]->going = this->hedges[2*i];
  }
  
  //populating the single face of the polygon
  face* temp_face = new face(this->hedges[0]);
  this->faces.push_back(temp_face);
  
  //populating the hedges.
  //the hedges that belong to the i'th edge are stored in indices [2*i] and [2*i + 1]
  for(int i = 0; i < 2*n - 1; i += 2){
    this->hedges[i]->next_hedge = this->hedges[(i + 2)%(2*n)];
    this->hedges[i + 1]->next_hedge = this->hedges[(i + 2*n - 1)%(2*n)];
    this->hedges[i]->incident_face = this->faces[0];
    this->hedges[i + 1]->incident_face = NULL;  //for the edges which belong to the infinite_face.
    this->hedges[i]->previous_hedge = this->hedges[i]->twin_hedge->find_nextedge()->twin_hedge;
    this->hedges[i + 1]->previous_hedge = this->hedges[i + 1]->twin_hedge->find_nextedge()->twin_hedge;
  }  
}