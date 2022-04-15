using namespace std;
//face
class face{
public:
  hedge * incident_hedge; //one of the halfedges that belong to this face
  static int count;       //for assigning indices automatically; Initaialized in "main.cpp" 
  int face_index;
  
  //constructor
  face(hedge* incident_hedge){
    this->incident_hedge = incident_hedge;
    this->face_index = this->count;
    this->count++;
  }
};