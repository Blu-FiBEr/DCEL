//for splitting a face by taking the two edge indices from which split occurs as input.
#include "main.hpp"
using namespace std;
void dcel::split(int a, int b)
{
  //creating new vertex at edge index a 
  float x1 = ((float)(this->edges[a]->end_1->x) + this->edges[a]->end_2->x)/2;
  float y1 = ((float)(this->edges[a]->end_1->y) + this->edges[a]->end_2->y)/2;
  vertex * temp1 = new vertex(x1, y1);
  this->vertices.push_back(temp1);
  
  //creating a new vertex at edge index b
  float x2 = ((float)(this->edges[b]->end_1->x) + this->edges[b]->end_2->x)/2;
  float y2 = ((float)(this->edges[b]->end_1->y) + this->edges[b]->end_2->y)/2;
  vertex * temp2 = new vertex(x2, y2);
  this->vertices.push_back(temp2);
  
  //creating and populating the new split edge and it's halfedges
  pair<hedge*, hedge*> new_hedges;
  edge * temp3 = new edge(temp1, temp2, new_hedges);
  this->edges.push_back(temp3);
  this->hedges.push_back(new_hedges.first);
  this->hedges.push_back(new_hedges.second);
  hedge * temp4 = this->hedges.end()[-2];
  hedge * temp5 = this->hedges.end()[-1];
  
  //creating the 2 more edges that are required along with their 4 halfedges
  face* affected_face;  //the face that is being split
  edge* temp6; //The new edge formed at the edge a.
  hedge * temp7;   
  hedge * temp8;
  vertex * affected_vertex_a; //The vertex on edge a which is in the cyclic traversal of new face.
  hedge * affected_hedge_a; //the hedge starting from affected_vertex_a and in the edge a
  vertex * affected_vertex_b;
  hedge * affected_hedge_b;
  edge* temp9; //The new edge formed at the edge b.
  hedge * temp10;
  hedge * temp11;
  
  int orient_1 = orientation(temp1, this->edges[a]->end_1, temp2);  //find the affected vertices by checking which end of the edge is in the cyclic traversal
  int orient_2 = orientation(temp1, this->edges[b]->end_1, temp2);
  //-------------------------------------------------------------------------------------------------------------------------------------------------------
  /*For Edge a*/
  //if the end_1 of edge a is in cyclic traversal 
  if(orient_1 == 1){
    affected_vertex_a = this->edges[a]->end_1;
    this->edges[a]->end_1 = temp1;
  }
  //if the end 2 of edge a is in the cyclic traversal
  else{
    affected_vertex_a = this->edges[a]->end_2;
    this->edges[a]->end_2 = temp1;
  }
  //populating the newly formed edges and hedges at edge a.
  affected_hedge_a = (this->hedges[2*a]->start_vertex == affected_vertex_a)?(this->hedges[2*a]) : this->hedges[2*a + 1];
  affected_face = affected_hedge_a->twin_hedge->incident_face;
  affected_face->incident_hedge = temp4;
  temp6 = new edge(temp1, affected_vertex_a, new_hedges);
  this->edges.push_back(temp6);
  this->hedges.push_back(new_hedges.first);
  this->hedges.push_back(new_hedges.second);
  temp7 = this->hedges.end()[-2];
  temp8 = this->hedges.end()[-1];
  temp8->next_hedge = affected_hedge_a;
  temp8->previous_hedge = affected_hedge_a->find_previousedge();
  affected_hedge_a->find_previousedge()->next_hedge = temp8;
  affected_hedge_a->start_vertex = temp1;
  affected_hedge_a->previous_hedge = temp8;
  temp8->incident_face = affected_hedge_a->incident_face;
  temp7->next_hedge = affected_hedge_a->twin_hedge->find_nextedge();
  affected_hedge_a->twin_hedge->find_nextedge()->previous_hedge = temp7;
  temp7->previous_hedge = temp5;
  temp5->next_hedge = temp7;
  temp4->previous_hedge = affected_hedge_a->twin_hedge;
  affected_hedge_a->twin_hedge->next_hedge = temp4;
  //-----------------------------------------------------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------------------------------------------------------
  /*For edge b*/
  if(orient_2 == 1){
    affected_vertex_b = this->edges[b]->end_1;
    this->edges[b]->end_1 = temp2;
  }
  else{
    affected_vertex_b = this->edges[b]->end_2;
    this->edges[b]->end_2 = temp2;
  }
  //populating at edge_b
  affected_hedge_b = (this->hedges[2*b]->start_vertex == affected_vertex_b)?(this->hedges[2*b]) : this->hedges[2*b + 1];
  temp9 = new edge(temp2, affected_vertex_b, new_hedges);
  this->edges.push_back(temp9);
  this->hedges.push_back(new_hedges.first);
  this->hedges.push_back(new_hedges.second);
  temp10 = this->hedges.end()[-2];
  temp11 = this->hedges.end()[-1];
  temp11->next_hedge = temp5;
  temp5->previous_hedge = temp11;
  temp11->previous_hedge = affected_hedge_b->find_previousedge();
  affected_hedge_b->find_previousedge()->next_hedge = temp11;
  affected_hedge_b->start_vertex = temp2;
  affected_hedge_b->previous_hedge = temp4;
  temp4->next_hedge = affected_hedge_b;
  temp10->next_hedge = affected_hedge_b->twin_hedge->find_nextedge();
  affected_hedge_b->twin_hedge->find_nextedge()->previous_hedge = temp10;
  temp10->previous_hedge = affected_hedge_b->twin_hedge;
  affected_hedge_b->twin_hedge->next_hedge = temp10;
  temp10->incident_face = affected_hedge_b->twin_hedge->incident_face;
  //------------------------------------------------------------------------------------------------------------------------------------------------------
  
  //creating the newly formed face
  face* temp12 = new face(temp5);
  this->faces.push_back(temp12);

  //traversing the new face in order to set the incident_face for all the hedges of the face
  hedge* traverse_new = temp5;
  for(;;){
    traverse_new->incident_face = temp12;
    traverse_new = traverse_new->next_hedge;
    if(traverse_new == temp5) break;
  }
  
  //traversing the affected face to set incident_face
  hedge* traverse_old = temp4;
  for(;;){
    traverse_old->incident_face = affected_face;
    traverse_old = traverse_old->next_hedge;
    if(traverse_old == temp4) break;
  }
}