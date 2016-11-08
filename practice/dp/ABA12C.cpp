/* http://www.spoj.com/problems/ABA12C/ */
#include <stdio.h>
#include <iostream>
#include <climits>
using namespace std;

int main(int argc, char const *argv[]){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, k;
		scanf("%d %d", &n, &k);
		int cost[k+1], temp, ans[k+1];

		for(int i=1; i<=k; i++){
			scanf("%d", &temp);
			if(temp == -1)
				temp = INT_MAX;
			cost[i] = temp;
			ans[i] = INT_MAX;
		}

		int build = 3;
		ans[1] = cost[1]; 
		if(k>1){
			ans[2] = cost[2]; 
		}

		while(build <= k){
			int ans_temp = cost[build];
			for(int i=build-1; i>build/2; i--){
				if(cost[i] == INT_MAX || cost[build-i] == INT_MAX)
					continue;
				ans_temp = min(ans_temp, cost[i] + cost[build-i]);
			}
			ans[build] = ans_temp;
			build++;
		}

		for(int i=1; i<=k; i++){
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}