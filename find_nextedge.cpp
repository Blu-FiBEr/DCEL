//function to find next halfedge
#include "main.hpp"
using namespace std;
hedge* hedge::find_nextedge(){
  return this->next_hedge ;
}