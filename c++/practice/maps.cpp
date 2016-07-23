#include <iostream>
#include <map>
using namespace std;

struct m1{
    int a;
    int b;
    m1(int _a, int _b){
        a = _a;
        b = _b;
    }
};

struct comp{
    bool operator()(const m1 &a, const m1& b) const {
        return a.a < b.a;
    }
};


int main(int argc, char const *argv[]) {
    m1 a = m1(12,23);
    m1 b = m1(23, 34);
    map<m1, int, comp> list;
    list[a] = 12;
    list[b] = 34;
    map<m1, int> :: iterator i;
    for(i=list.begin(); i!=list.end(); i++){
        cout << i->first.a << " " << i->second << endl;
    }
    map<string, int> map1;
    map1["hi"] = 12;
    if(map1.find("hi") != map1.end())
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    return 0;
    cout << map1.insert(pair<string, int>("hello", 12)).second;
    cout << map1.insert(pair<string, int>("hello", 12)).second;
}
