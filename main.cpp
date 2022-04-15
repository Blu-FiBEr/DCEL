//main function to initialize the dcel and populate it, Call other functions to make changes to dcel or to print it.
#include "main.hpp"
using namespace std;

//initializing all static data members
int vertex::count = 0;
int edge::count = 0;
int face::count = 0;

int main(int argc, char* argv[])
{
  char* infile = argv[1];
  char* splitfile = argv[2];
  char* outfile = argv[3]; 
  FILE * infilepr = fopen(infile, "r"); //opening the input file to read
  FILE * outfilepr = fopen(outfile, "w"); //opening the output file to write
  FILE * splitpr = fopen(splitfile, "r"); //opening the input file to read
  
  //The array containing pointers to vertex objects.
  vector<vertex*> input_vertices;
  
  //taking input from the input file and filling vertices structures.
  float p1, p2;
  for(;;){
    if(feof(infilepr)) break;
    fscanf(infilepr , "%f %f", &p1, &p2);
    vertex* temp = new vertex(p1, p2);
    input_vertices.push_back(temp);
  }
  fclose(infilepr);
  
  //create new dcel object from given vertices
  dcel * DCEL = new dcel(input_vertices);
  
  //calling to print the final dcel structure after initialization
  //before split
  DCEL->display_dcel(outfilepr);
  
  
  unordered_map<int, int> bounds; //mapping the point IDs to their corresponding faces for the point_in_face task
  vector<int> IDs;  //storing the pointIDs in the same order as they appear in input
  //reading split.txt for the split tasks and point_in_face tasks
  int s1, s2;
  for(;;){
    if(feof(splitpr)) break;
    char s[6];
    
    //read first word in the line
    fscanf(splitpr, "%s", s);
    //convert C string to C++ string
    string str(s);
    
    //split task
    if(str == "Split") {
      fscanf(splitpr, "%d %d", &s1, &s2);
      DCEL->split(s1, s2);
      fprintf(outfilepr,"\n\n");
      //after split
      DCEL->display_dcel(outfilepr);
    }
    //point_in_face task
    else if(str.front() == 'I'){
      float a1, a2;
      //get the ID of the given point. The ID will appear after "ID:"
      str = str.substr(3);
      
      //convert to stringstream and parsing to integer and storing in "point_ID"
      stringstream number(str);
      int point_ID;
      number >> point_ID;
      
      IDs.push_back(point_ID);
      fscanf(splitpr, "%f %f", &a1, &a2);
      
      //create point object and find the corresponding face
      point * temp = new point(a1, a2, point_ID);
      temp->is_inside(bounds, DCEL->hedges, DCEL->faces);
    }
  }
  
  //Displaying faces that enclose given points
  point::display_IDs(outfilepr, bounds, IDs);
  
  fclose(splitpr);
  fclose(outfilepr);
  return 0;
}