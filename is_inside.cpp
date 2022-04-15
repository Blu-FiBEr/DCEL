//For finding bounding face of a point, and adding the data to unordered-map
#include "main.hpp"
using namespace std;
void point::is_inside(unordered_map<int, int> &bounds, vector<hedge*> &hedges, vector<face *> &faces){
  unordered_map<float, int> probable;   //maps (the distance of type-1 hedges from given point) and (face index of the type-1 hedge)
  priority_queue<float> closest;    //negative values of distance is stored as key in order to act as minimum priority_queue
  float height = this->y;
  
  //iterate over all edges to find type-1 hedges and their distances
  for(int i = 0; i < hedges.size(); i++){
    hedge * temp = hedges[i];
    vertex * v1 = temp->start_vertex;
    vertex * v2 = temp->find_endvertex();
    
    //the ">=" takes care of the boundary case when horizontal passes through vertex
    //If the hedge intersects the horizontal line through given point
    if((v1->y >= height) && (v2->y < height)){
      float slope = (v2->y - v1->y)/(v2->x - v1->x);      //slope of line through hedge
      float abscissa = ((height - v2->y)/slope + v2->x);  //the abscissa of intersection point
      
      //if the hedge intersects the ray through the point(hedge is on the right of the point); thus hedge is type1
      if(abscissa > this->x) {
        float delta = this->x - abscissa;
        closest.push(delta);
        probable[delta] = temp->incident_face->face_index;
      }
      //we know that i'th and (i+1)th hedges are twins when i is even. 
      //Thus, if i'th hedge intersects the horizontal , it is clear that its twin won't.
      //We need not check the twin.
      if(i % 2 == 0) i++;
    }
  }
  
  //checking the face through ray casting
  int x = 0;  // x == 0 means that no boundary has been found
  for(; !closest.empty();){
    face * current = faces[probable[closest.top()]];
    int type1_count = 0, type2_count = 0;
    hedge * temp = current->incident_hedge;
    for(;;){
      vertex * v1 = temp->start_vertex;
      vertex * v2 = temp->find_endvertex();
      if(this->is_type1(v1, v2)) type1_count++;
      else if(this->is_type2(v1, v2)) type2_count++;
      temp = temp->find_nextedge();
      if(temp->hedge_index == current->incident_hedge->hedge_index) break;
    }
    if(type1_count > type2_count) {
      bounds[this->point_ID] = probable[closest.top()];
      x = 1;
      break;
    }
    closest.pop();
  }
  if(x == 0) printf("No Face");
  return;
}
