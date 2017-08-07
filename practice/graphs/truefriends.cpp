#include <bits/stdc++.h>
using namespace std;

bool visited[100+10];
bool connection[110][110];
bool rev[110][110];
bool check;
int n;
stack<int> tack;

void DFS(int src) {

    for(int i=0; i<n; i++) {
        if (!visited[i] && i!=src) {
            if (check && connection[src][i]==false)
                continue;
            if (!check && rev[src][i] != true)
                continue;
            // cout << "\t\t Edge between " << src << " " << i << " = " << connection[src][i] << " " << rev[src][i] << endl;
            visited[i] = true;
            DFS(i);
        }
    }

    if (check) {
        // cout << "Pushing " << src << endl;
        tack.push(src);
    }
}

void print() {
    cout << "\t";
    for(int i=0; i<n; i++) {
        cout << i << ": " << visited[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;

        memset(visited, false, sizeof visited);

        char ch;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> ch;
                if (ch == 'Y') {
                    connection[i][j] = true;
                    rev[j][i] = true;
                }
                else {
                    connection[i][j] = false;
                    rev[j][i] = false;
                }
            }
        }

        check = true;
        while(!tack.empty()) tack.pop();

        for(int i=0; i<n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                DFS(i);
            }
        }

        memset(visited, false, sizeof visited);

        int ans = 0;
        check = false;
        while(!tack.empty()) {
           int k = tack.top();
           tack.pop();
           // cout << "Popped " << k << endl;
           if(!visited[k]) {
               ans++;
               DFS(k);
           }
        }

       cout << ans << endl;
    }
}