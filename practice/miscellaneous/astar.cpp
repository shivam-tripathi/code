#include <bits/stdc++.h>
using namespace std;

// Generate the other user's turn value
// 2->1 and 1->2
#define OTHER(x) ((x)%2+1)

// Utility function to create and return a new matrix pointer
int **new_matrix(int **mat=NULL) {
    int **matrix = new int*[3];
    int n = 3;
    for(int i=0; i<n; i++) {
        matrix[i] = new int[3];
        for(int j=0; j<n; j++) {
            matrix[i][j] = 0;
        }
    }
    if (mat == NULL) {
        return matrix;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            matrix[i][j] = mat[i][j];
        }
    }
    return matrix;
}

void render_matrix(int **mat) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            char a = (mat[i][j] == 2) ? 'X' : ((mat[i][j] == 1) ? 'O' : '_');
            cout << a << " ";
        }
        cout << endl;
    }
}


// Verify if it is the goal state?
bool goal_state(int **mat, int x, int y, int val) {
    if (x == 0) if (mat[x+1][y] == val && mat[x+2][y] == val) return true;
    if (x == 1) if (mat[x-1][y] == val && mat[x+1][y] == val) return true;
    if (x == 2) if (mat[x-1][y] == val && mat[x-2][y] == val) return true;

    // Check for column
    if (y == 0) if (mat[x][y+1] == val && mat[x][y+2] == val) return true;
    if (y == 1) if (mat[x][y-1] == val && mat[x][y+1] == val) return true;
    if (y == 2) if (mat[x][y-1] == val && mat[x][y-2] == val) return true;

    // Check for diagonal (middle element)
    if (x == 1 && y == 1) {
        if ((mat[x-1][y-1] == val && mat[x+1][y+1] == val) && ((mat[x-1][y+1] == val && mat[x-1][y+1] == val))) {
            return true;
        }
    }

    if (mat[1][1] == val) {
        if (x == 0 && y == 0 && mat[2][2] == val) return true;
        if (x == 0 && y == 0 && mat[2][0] == val) return true;
        if (x == 2 && y == 0 && mat[0][2] == val) return true;
        if (x == 2 && y == 2 && mat[0][0] == val) return true;
    }
    return false;
}


// struct to store state of the matrix
struct State {
    short state[3][3];
    state(int **st) {
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                state[i][j] = st[i][j];
            }
        }
    }
};


// Elem for selecting next <node, state>
struct elem {
    int id, x, y, myturn, otherturn;
    State state;
    elem(int _id, int _x, int _y, int _score, state _s) {
        id = _id;
        x = _x;
        y = _y;
        state = s;
        myturn = 1;
        otherturn = 1;
};


// struct to
struct branch {
    int id, parent_x, parent_y;
};


// Comparator to sort values in ascending order in the priority queue
class Cmp{
public:
    bool operator() (const elem &a, const elem &b) {
        if (b.score < a.score) return true;
        if (b.score > a.score) return false;
        if (a.score == b.score) {
            if (a.x == 1 && a.y == 1) return true;
            if (b.x == 1 && b.y == 1) return false;
            return true;
    }
};


int heuristic(int x, int y, State state) {

}

pair<int, int> next_move(int **mat, int val) {

    // key: {bit masked position of X, bit masked position of O, bit masked value of _} => score
    map<State, int> visited;
    // Keep track of minimum score <point, states>
    priority_queue<elem, vector<elem>, Cmp> pq;

    vector<branch> branches;
    State s(mat);

    bool flag_other = false;
    int flag_other_x, flag_other_y;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if (mat[i][j] == 0) {

                branch b;
                b.parent_x = i;
                b.parent_y = j;
                b.id = branches.size();
                branches.push_back(b);

                if (goal_state(mat, i, j, val)) {
                    return make_pair(i, j);
                }

                if (goal_state(mat, i, j, OTHER(val))) {
                    flag_other=true;
                    flag_other_x = i;
                    flag_other_y = j;
                }

                score = heuristic(i, j, s);
                elem e(b.id, i, j, state.update_state(i, j, val));
                pq.push(e);
            }
        }
    }

    int check = OTHER(val);

    while(true) {
        elem e = pq.top();
        pq.pop();

        if (visited.find(e.state) != visited.end() && visited[e.state] < e.score) {
            continue;
        }

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if (e.state[i][j] == 0) {
                    if (check == OTHER(val)) {
                        State ns(e.state);
                        ns.state[i][j] = check;
                        elem ne(e.id, i, j,)
                    }
                }
            }
        }




        // Flip to next turn
        check = OTHER(check);
    }

    if(flag) {
        return make_pair(flag_x, flag_y);
    }
}


int main() {
    // memset(matrix, sizeof matrix, 0);
    int **mat = new_matrix(NULL);
    print(mat);

    mat[0][1] = 2;
    mat[2][2] = 1;
    mat[1][2] = 2;

    render_matrix(mat);

    return 0;
}


/*
_ X _
_ _ X
_ _ O
*/