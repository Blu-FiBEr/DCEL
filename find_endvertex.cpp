//function to find the end vertex of a halfedge
#include "main.hpp"
using namespace std;
vertex* hedge::find_endvertex(){
  return this->next_hedge->start_vertex ;  //the starting vertex of next halfedge would be the end vertex of this halfedge
}