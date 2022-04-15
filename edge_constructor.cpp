#include "main.hpp"
using namespace std;
//edge constructor
//The pair helps the caller to access newly formed hedge objects
edge::edge(vertex* end_1, vertex* end_2, pair<hedge*, hedge*> &new_hedges){
  this->end_1 = end_1;
  this->end_2 = end_2;
  this->edge_index = this->count;
  this->count++;
  
  //creating the corresponding hedges
  hedge* temp1 = new hedge(this->end_1, this->edge_index);
  hedge* temp2 = new hedge(this->end_2, this->edge_index);
  temp1->twin_hedge = temp2;
  temp2->twin_hedge = temp1;
  
  //the hedge references are filled in a "pair".
  //This is done because constructor cannot return a non-void value.
  new_hedges = make_pair(temp1, temp2);
}