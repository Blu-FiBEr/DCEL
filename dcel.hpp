//The dcel class containing references to all objects that are a part of the dcel structure
using namespace std;
class dcel{
public:
  //the arrays storing all information about the polygon.
  vector<vertex*> vertices; 
  vector<edge*> edges;
  vector<face*> faces;
  vector<hedge*> hedges;
  
  //constructor
  dcel(vector<vertex*> &input_vertices);

  //methods
  void display_dcel(FILE *outfilepr);
  void display_edges(FILE * outfilepr);
  void display_faces(FILE * outfilepr);
  void display_hedges(FILE * outfilepr);
  void split(int a, int b);
};