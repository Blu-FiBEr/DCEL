//function to print all edge indices
#include "main.hpp"
using namespace std;
void dcel::display_edges(FILE * outfilepr){
  fprintf(outfilepr, "Edges:");
  for(int i = 0; i < this->edges.size(); i++){
    fprintf(outfilepr, "\n%d", this->edges[i]->edge_index);
  }
}