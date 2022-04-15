//calls all methods that print out the dcel details in the output_file
#include "main.hpp"
using namespace std;
void dcel::display_dcel(FILE * outfilepr){
  this->display_edges(outfilepr);
  this->display_hedges(outfilepr);
  this->display_faces(outfilepr);
}