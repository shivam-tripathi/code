#include <iostream>
#include <list>
using namespace std;


bool function(int index, int *a[], int size, int flag, int visited[]){
	// cout << "Visiting " <<  index << " " << visited[index] << endl;
	for(int i=0; i<size; i++){
		if(i == index)
			continue;
		if(a[index][i] == 0){
			if(!visited[i]){
				visited[i] = flag;
				int new_flag = (flag == 1) ? -1 : 1;
				if(!function(i, a, size, new_flag, visited)){
					// cout << "Err " << i << endl;
					return false;
				}
			}
			else{
				if(visited[i] == visited[index]){
					// cout << "Clash in " << index << " " << i <<  " " << visited[index] << " " << visited[i] << endl;
					return false;
				}
			}
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--){
		int n, m, p1, p2, j;
		cin >> n >> m;
		int **a = new int*[n];
		for(int i=0; i<n; i++){
			a[i] = new int[n];
		}
		for(int i=0; i<m; i++){
			cin >> p1 >> p2;
			a[p1-1][p2-1] = 1;
			a[p2-1][p1-1] = 1;
		}
		if(m == 0){
			if(n > 2)
				cout << "NO" << endl;
			else 
				cout << "YES" << endl;
			continue;
		}
		if(m == n*(n-1)/2){
			cout << "YES" << endl;
			continue;
		}
		int visited[n] = {0};
		bool result = true;
		for(int i=0; i<n; i++){
			if(!visited[i]){
				visited[i] = 1;
				if(!function(i, a, n, -1, visited)){
					result = false;
					break;
				}
			}
		}
		if(!result)
			cout << "NO" << endl;
		else 
			cout << "YES" << endl;
	}
	return 0;
}