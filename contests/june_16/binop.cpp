#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    string a, b;
    cin >> t;
    while(t--){
        cin >> a;
        cin >> b;
        int num_1 = 0, num_0 = 0, mis_1 = 0, mis_0 = 0;
        for(int i=0; i<a.length(); i++){
            if(a[i] != b[i]){
                // cout << "Mis " << a[i] << " " << b[i] << endl;
                if(a[i] == '1'){
                    mis_1 += 1;
                    // cout << "Updating 1 " << mis_1 <<  endl;
                }
                else{
                    mis_0 += 1;
                    // cout << "Updating 0 " << mis_0 << endl;
                }
            }
            if(!num_1 && a[i] == '1'){
                num_1 = 1;
            }
            else if(!num_0 && a[i] == '0'){
                num_0 = 1;
            }
        }
        // cout << a << " " << b << endl;
        // cout << mis_1 << " " << mis_0 << " " << num_1 << " " << num_0 << endl;
        if(mis_0 == mis_1){
            cout << "Lucky Chef" << endl << mis_1 << endl;
        }
        else if(mis_0 > mis_1 && num_1 != 0){
            cout << "Lucky Chef" << endl << mis_0 << endl;
        }
        else if(mis_1 > mis_0 && num_0 != 0){
            cout << "Lucky Chef" << endl << mis_1 << endl;
        }
        else{
            cout << "Unlucky Chef" << endl;
        }
    }
}
