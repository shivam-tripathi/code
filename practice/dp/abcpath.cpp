#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;

char grid[100][100];
int track[100][100];
int h;
int w;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool bounds_check(int, int);

int main(){
    int t=1;
    while(true){
        // cout << "Input numbers " << endl;
        cin >> h >> w;
        if(h == 0 && w == 0)
            break;
        std::vector<pii> v[26];

        // cout << "Running " << endl;

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> grid[i][j];
                track[i][j] = 1;
                int index = grid[i][j]-'A';
                // cout << i << " " << j << " " << grid[i][j] << " " << index << endl;
                v[index].push_back(pii(i,j));
            }
        }

        if(v[0].size() == 0){
            cout << "Case " << t++ << ": " << 0 << endl;            
            continue;
        }

        std::vector<pii> :: iterator iter;
        for(int i=0; i<26; i++){
            for(iter=v[i].begin(); iter!=v[i].end(); iter++){
                int x = (iter)->first;
                int y = (iter)->second;
                if(track[x][y] != i+1)
                    continue;
                for(int p=0; p<8; p++){
                    if(bounds_check(x+dx[p], y+dy[p])){
                        if(grid[x][y]+1 == grid[x+dx[p]][y+dy[p]]){
                            track[x+dx[p]][y+dy[p]] = max(track[x+dx[p]][y+dy[p]], track[x][y]+1);
                        }
                    }
                }
            }
        }
        int ans = 0;
        // for(int i=0; i<h; i++){
        //     for(int j=0; j<w; j++){
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                ans = max(ans, track[i][j]);
                // cout << track[i][j] << " | ";
            }
        }
        // cout << h << " " << w << endl;
        cout << "Case " << t++ << ": " << ans << endl;
    }
    return 0;
}

bool bounds_check(int x, int y){
    if(x < 0 || y < 0 || x >= h || y >= w)
        return false;
    else 
        return true;
}