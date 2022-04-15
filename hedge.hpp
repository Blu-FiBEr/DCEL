using namespace std;
//halfedge(directional)
class hedge{
public:
  vertex * start_vertex;  //start vertex of the halfedge
  int hedge_index;
  hedge * next_hedge;
  hedge * previous_hedge;
  face * incident_face;   //the face to which this hedge belongs
  hedge * twin_hedge;     //the opposite halfedge of this halfedge
  
  //methods
  vertex* find_endvertex();
  hedge* find_previousedge();
  hedge* find_nextedge();
  
  //constructor
  hedge(vertex* start_vertex, int hedge_index){
    this->start_vertex = start_vertex;
    this->hedge_index = hedge_index;
  }
};