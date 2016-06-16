#include <bits/stdc++.h>
using namespace std;

bool check(int i){
    while(i!=0){
        int temp = i%10;
        if(temp%2 == 1)
            return false;
        i /= 10;
    }
    return true;
}

long long ans(long long number){
    vector<char> v;
    while(number != 0){
        v.push_back(2*(number%5) + '0');
        number /= 5;
    }
    long long temp = 0;
    for(long long i = v.size()-1; i>=0; i--){
        temp = temp*10 + (v[i]-'0');
    }
    return temp;
}

 int main(){
     vector<int> magical;
     for(int i=0; i<610000; i++){
         if(check(i)){
             magical.push_back(i);
         }
     }
    long long t, k;
    cin >> t;
    while(t--){
        cin >> k;
        if(k<=10000)
            cout << magical[k-1] << endl;
        else
            cout << ans(k-1) << endl;
    }
}
