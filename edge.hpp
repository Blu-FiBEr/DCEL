using namespace std;
//edge(non-directional)
class edge{
public:
  int edge_index;
  //vertices of the edge in any order
  vertex * end_1;
  vertex * end_2;
  static int count;     //for assigning edge and halfedge indices automatically; Initaialized in "main.cpp"
  
  //constructor
  edge(vertex* end_1, vertex* end_2, pair<hedge*, hedge*> &new_hedges);
}; 