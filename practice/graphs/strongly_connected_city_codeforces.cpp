#include <bits/stdc++.h>
using namespace std;

#define node_num(r, c, b) ((b)*(r) + (c))

class ConnectedComponent{
public:
	list<int> *li;
	list<int> *lir;
	int r;
	int c;
	int total_elements;
	ConnectedComponent(int r, int c){
		this->r = r;
		this->c = c;
		total_elements = r*c;
		li = new list<int>[r*c];
		lir = new list<int>[r*c];
	}
	void insert(int src, int target){
		// cout << "Inserting " << src << "  " <<  target << endl; 
		li[src].push_back(target);
		lir[target].push_back(src);
	}
	bool DFS(int op){
		bool visited[total_elements] = {false};
		int count = 0;
		// cout << "Total elements " << total_elements << endl;
		if(op == 1)	DFSUtilli(0, visited, count);
		else DFSUtillir(0, visited, count);
		if(count != total_elements)
			return false;
		else 
			return true;
	}
	void DFSUtilli(int src, bool visited[], int &count){
		count++;
		visited[src] = true;
		// cout << src << endl;
		list<int> :: iterator i;
		for(i=li[src].begin(); i!=li[src].end(); i++){
			// cout << "j " << *i << endl;
			if(!visited[*i]){
				DFSUtilli(*i, visited, count);
			}
		}
	}

	void DFSUtillir(int src, bool visited[], int &count){
		count++;
		visited[src] = true;
		// cout << src << endl;
		list<int> :: iterator i;
		for(i=lir[src].begin(); i!=lir[src].end(); i++){
			// cout << "j " << *i << endl;
			if(!visited[*i]){
				DFSUtillir(*i, visited, count);
			}
		}
	}
};

int main(int argc, char const *argv[]){
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	ConnectedComponent graph(n,m);
	for(int i=0; i<a.length(); i++){
		// cout << " ----- epoch : " << i << endl;
		if(a[i] == '<'){
			for(int j=m-1; j>0; j--){
				graph.insert(m*i + j, m*i + j - 1);
			}
		}
		if(a[i] == '>'){
			for(int j=0; j<m-1; j++){
				graph.insert(m*i + j, m*i + j + 1);
			}
		}
	}
	for(int i=0; i<b.length(); i++){
		// cout << "==== epoch " << i << endl;
		if(b[i] == '^'){
			for(int j=n-1; j>0; j--){
				graph.insert(m*j + i, m*(j -1) + i);
			}
		}
		if(b[i] == 'v'){
			for(int j=0; j<n-1; j++){
				graph.insert(m*j + i, m*(j+1) + i);
			}
		}
	}

	if(graph.DFS(1) && graph.DFS(2))
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;
	return 0;
}