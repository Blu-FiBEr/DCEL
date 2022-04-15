//representing a point that will be used in the "Points Inside The face" task
using namespace std;
typedef class point{
public:
  float x, y; //coordinates
  int point_ID;
  
  //methods
  void is_inside(unordered_map<int, int> &bounds, vector<hedge*> &hedges, vector<face *> &faces); //finds the bounding face
  bool is_type1(vertex * v1, vertex * v2);  //checks if given hedge is type-1 w.r.t given point
  bool is_type2(vertex * v1, vertex * v2);  //checks if given hedge is type-2 w.r.t given point
  static void display_IDs(FILE* outfilepr, unordered_map<int, int> &bounds, vector<int> &IDs);  //print the results to file
  
  //constructor
  point(float x, float y, int point_ID){
    this->x = x;
    this->y = y;
    this->point_ID = point_ID;
  }
}point;