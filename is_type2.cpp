//check if the hedge is type2 w.r.t the point
#include "main.hpp"
using namespace std;
bool point::is_type2(vertex * v1, vertex * v2){
  float ray_source = this->x , height = this->y; 
  //if the horizontal line through the point intersects the hedge
  bool bool1 = (v1->y < height) && (v2->y >= height);
  if(!bool1) return bool1;
  
  float slope = (v2->y - v1->y)/(v2->x - v1->x);
  //if the horizontal ray intersects the edge
  bool bool2 = (((height - v2->y)/slope + v2->x) > ray_source ) && bool1;
  return bool2;
}