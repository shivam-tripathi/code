#include <iostream>
#define TO_VECTOR(P1, P2) ({(P1.x-P2.x),(P1.y-P2.y)})
#define GET_Z(V1,V2) (V1.x*V2.y - V1.y*V2.x)
using namespace std;

struct Point{
    double x;
    double y;
};

typedef Vector Point;

// Given three colinear points, function checks if c lies on ab
bool on_segment(Point a, Point b, Point c){
    if(c.x <= max(a.x, b.x) && c.x >= min(a.x, b.x) &&
        c.y <= max(a.y, b.y) && c.y >= (min(a.y, b.y)))
        return true
    return false;
}

// Negative means anti-clockwise and positive means clockwise
int orientation(Point a, Point b, Point c){
    return -1*GET_Z(TO_VECTOR(a,b), TO_VECTOR(b,c));
}

int doIntersect(Point p1, Point q1, Point p2, Point q2){
    int o1 = orientation(p1,q1);
    int o2 = orientation(p2, q2);
    int o3 = orientation(p3, q3);
    int o4 = orientation(p4, q4);
    if(o1 != o2 && o3 != o4){
        return true;
    }
    if(o1 == 0)
}
