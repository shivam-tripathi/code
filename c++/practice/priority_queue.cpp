#include <queue>
#include <iostream>
using namespace std;

struct Structure{
    string a;
    Structure(string _a){
        a = _a;
    }
};

struct Comp{
    bool operator()(const Structure &a, const Structure &b){
        return a.a.length() > b.a.length(); //smaller will be on the top
    }
};

int main(int argc, char const *argv[]) {
    priority_queue< Structure, vector<Structure>, Comp> pq;
    pq.push(Structure("shivam"));
    pq.push(Structure("tripathi"));
    while(!pq.empty()){
        cout << pq.top().a << endl;
        pq.pop();
    }
    return 0;
}
