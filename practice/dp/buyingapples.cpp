#include <bits/stdc++.h>
using namespace std;

int n, k;

int calculate(int i, bool visited[], int cost[], int price[], int c=n){	
	// Base case 
	if(i == 0){
		if(price[i] != -1)
			cost[i] = price[i];
		return cost[i];
	}

	// Cannot purchase more than n bags
	if(c <= 0)
		return INT_MAX;

	// If already visited, return cost for it
	if(visited[i])
		return cost[i];

	// Value for the result for this kg
	int result;

	if(price[i] != -1)
		result = price[i];
	else 
		result = INT_MAX;

	cout << i << endl;

	// Compute cost for this kg
	for(int j=i-1; j>=0; i--){
		if(i-j > i)
			break;
		if(price[j] != -1)
			result = min(price[j] + calculate(i-j, visited, cost, price, c-1), result);
	}

	// Finalize cost for this kg
	cost[i] = result;

	return result;
}

int main(int argc, char const *argv[]){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &k);

		int price[n];
		int cost[k];
		bool visited[k] = {0};
		int result = INT_MAX;

		for(int i=0; i<n; i++){
			scanf("%d", &price[i]);
		}

		for(int i=0; i<k; i++){
			cost[i] = INT_MAX;
		}

		calculate()

		cout << cost[k-1] << endl;
	}
	return 0;
}