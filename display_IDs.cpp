//function to print all point_in_face tasks
#include "main.hpp"
using namespace std;
void point::display_IDs(FILE* outfilepr, unordered_map<int, int> &bounds, vector<int> &IDs){
  fprintf(outfilepr, "\n");
  unordered_map<int, int>:: iterator itr;
  //print IDs and faces in the same order as input
  for (int i = 0; i < IDs.size(); i++)
  {
    itr = bounds.find(IDs[i]);
    if(itr != bounds.end()) fprintf(outfilepr, "\nID:%d %d", itr->first, itr->second);
  }
}