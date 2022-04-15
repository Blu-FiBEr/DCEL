//function to find the previous halfedge
#include "main.hpp"
using namespace std;
hedge* hedge::find_previousedge(){
  return (this->previous_hedge) ;  
}
