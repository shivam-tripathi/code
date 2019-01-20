// http://www.spoj.com/problems/PCPC12E/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> adj[10000+10];
bool visited[10000+10];
int n, m, s, l, size;

struct Comp {
    bool operator() (pii a, pii b) const {
        if (a.second != b.second)
            return a.second > b.second;
        else
            return a.first > b.first;
    }
};

int bfs() {
    priority_queue<pii, vector<pii>, Comp> q;
    q.push(pii(0, 0));
    visited[0] = true;
    pii src;

    while(!q.empty()) {
        src = q.top();
        q.pop();
        if (src.first == size) {
            return src.second;
        }

        // cout << "\t" << src.first << " " << src.second << endl;

        for(int i=0; i<adj[src.first].size(); i++) {
            pii present_node_pair = adj[src.first][i];
            int present_node = present_node_pair.first;
            int chance_add = present_node_pair.second;
            if (!visited[present_node]) {
                visited[present_node] = true;
                q.push(pii(present_node, src.second+chance_add));
            }
        }
    }
    return -1;
}

int main() {
    while(scanf("%d %d %d %d", &n, &m, &s, &l) != EOF) {
        size = n*m;

        for(int i=0; i<10000+10; i++) {
            adj[i].clear();
            visited[i] = false;
        }

        for(int i=0; i<=size; i++) {
            // cout << "i = " << i << " : ";
            for(int j=1; (j<=6) && (j+i<=size); j++) {
                adj[i].push_back(pii(i+j, 1));
                // cout << adj[i][j-1].first << " ";
            }
            // cout << endl;
        }

        int a, b;
        bool flag = false;
        for(int i=0; i<(s+l); i++) {
            cin >> a >> b;
            if (a == size && b < size) {
                flag = true;
            }
            adj[a].clear();
            adj[a].push_back(pii(b, 0));
            // cout << "Modifying " << a << " : ";
            // for(auto i : adj[a]) cout << i.first << " ";
            // cout << endl;
        }

        if (flag) {
            cout << -1 << endl;
            continue;
        }

        int ans = bfs();
        cout << ans << endl;
    }
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// typedef pair<int, int> pii;

// short adj[10000+10][6];
// short adj_size[10000+10];
// bool visited[31];
// int n, m, s, l, size;

// int bfs() {
//     queue<pii> q;
//     q.push(pii(0, 0));
//     visited[0] = true;
//     pii src;

//     while(!q.empty()) {
//         src = q.front();
//         q.pop();
//         if (src.first == size) {
//             return src.second;
//         }

//         cout << src.first << " - " << src.second << endl;

//         for(int i=0; i<adj_size[src.first]; i++) {
//             int present_node = adj[src.first][i];
//             if (!visited[present_node]) {
//                 visited[present_node] = true;
//                 q.push(pii(present_node, src.second+1));
//             }
//         }
//     }
//     return -1;
// }

// int main() {

// 	while(scanf("%d %d %d %d", &n, &m, &s, &l) != EOF) {

//         size = n*m;

//         cout << n << " " << m << " " << s << " " << l << " SIZE= " << size << endl;

//         for(int i=0; i<size; i++)
//             adj_size[i] = 0;

//         for(int i=0; i<=size; i++) {
//             cout << "VISITING " << i << " less than " << size << " : ";
//             for(int j=1; (j<=6) && (j+i<=size); j++) {
//                 adj[i][adj_size[i]++] = i+j;
//                 cout << adj[i][adj_size[i]-1] << " " ;
//             }
//             cout << " | ENDING " << i << endl;

//             visited[i] = false;
//         }

//         int a, b;
//         // for(int i=0; i<s*l; i++) {
//         //     cin >> a >> b;
//         //     update_to[a] = b;
//         //     update[update_size++] = a;
//         //     updated[a] = false;
//         // }

//         // for(int i=0; i<update_size; i++) {

//         // }

//         for(int i=0; i<s; i++) {
//             cin >> a >> b;
//             adj_size[b] = 0;
//             for(int i=0; i<adj_size[a]; i++) {
//                 adj[b][adj_size[b]++] = adj[a][i];
//             }
//         }

//         for(int i=0; i<l; i++) {
//             cin >> a >> b;
//             adj_size[a] = 0;
//             for(int i=0; i<adj_size[b]; i++) {
//                 adj[a][adj_size[a]++] = adj[a][i];
//             }
//         }

//         cout << "SPECIAL PRINT " << endl;
//         if (size < 100) {
//             for(int i=0; i<size; i++) {
//                 cout << i << " : ";
//                 for(int j=0; j<adj_size[j]; j++) {
//                     cout << adj[i][j] << " ";
//                 }
//                 cout << endl;
//             }
//         }

//         int ans = bfs();
//         cout <<  "Ans : " << ans << endl;
// 	}
// 	return 0;
// }