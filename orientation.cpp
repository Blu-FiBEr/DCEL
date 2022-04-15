//checks the orientation of three points: p, q, r; Returns 0 if collinear, 1 if clockwise and 2 if counter-clockwise
#include "main.hpp"
using namespace std;
int orientation(vertex * p, vertex * q, vertex * r)
{
  float orient = ((float)q->y - p->y) * ((float)r->x - q->x) - ((float)q->x - p->x) * ((float)r->y - q->y); //derived using slopes of lines pq and qr.
  if (orient == 0) return 0; // colinear 
	return (orient > 0)? 1: 2; // clock or counterclock wise  
}