#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    long long n;
    cin >> t;
    while(t--){
        cin >> n;
        if(n%6==0){
            cout << "Misha" << endl;
        }
        else{
            cout << "Chef" << endl;
        }
    }
}
