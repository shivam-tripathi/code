#include <bits/stdc++.h>
using namespace std;

int grid[1100][1100];

void dfs(int x, int y) {

	// cout << x << " " << y << endl;

	grid[x][y] = 1;
	int tempx = x, tempy = y;
	do {
		x++;
		// cout << "\t" << x << " " << y << endl;
 	}
	while (x < 1000 && y < 1000 && grid[x][y] != -1);
	if (x < 1000 && y < 1000 && grid[x][y] == -1) dfs(x, y);

	// cout << endl << endl;

	x = tempx;
	y = tempy;
	do {
		x--;
		// cout << "\t" << x << " " << y << endl;

	}
	while (x >= 0 && y >= 0 && grid[x][y] != -1);
	if (x >=0 && y >= 0 && grid[x][y] == -1) dfs(x, y);
	// cout << endl << endl;

	x = tempx;
	y = tempy;
	do {
		y++;
		// cout << "\t" << x << " " << y << endl;

	}
	while (x < 1000 && y < 1000 && grid[x][y] != -1);
	if (x < 1000 && y < 1000 && grid[x][y] == -1) dfs(x, y);
	// cout << endl << endl;

	x = tempx;
	y = tempy;
	do {
		y--;
		// cout << "\t" << x << " " << y << endl;
	}
	while (x >= 0 && y >= 0 && grid[x][y] != -1);
	if (x >= 0 && y >= 0 && grid[x][y] == -1) dfs(x, y);
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	memset(grid, 0, sizeof grid);

	pair<int, int> arr[n];
	int x, y;
	for(int i=0; i<n; i++) {
		cin >> x >> y;
		arr[i].first = x;
		arr[i].second = y;
		grid[x][y] = -1;
	}

	int count = 0;
	for(int i=0; i<n; i++) {
		x = arr[i].first;
		y = arr[i].second;
		if(grid[x][y] == -1) {
			dfs(x, y);
			count++;
		}
	}

	cout << count-1 << endl;

	return 0;
}