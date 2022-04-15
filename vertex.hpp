using namespace std;
//vertex
typedef class vertex{
public:
  float x, y;
  int vertex_index;
  static int count;      //for assigning indices automatically; Initaialized in "main.cpp"
  hedge * going;         //one of the halfedges that have this vertex as source
  
  //constructor
  vertex(float x, float y){
    this->x = x;
    this->y = y;
    this->vertex_index = this->count;
    this->count++;
  }
}vertex;