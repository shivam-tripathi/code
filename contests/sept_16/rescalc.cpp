#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		int score = 0, winner = 0, pscore = 0, temp, tie = 0;

		int a[6] = {0};

		for(int i=0; i<n; i++){
		
			for(int j=0; j<6; j++){
				a[j] = 0;
			}

			int count = 0;

			cin >> pscore;

			// Input frequency
			for(int j=0; j<pscore; j++){
				cin >> temp;
				a[temp-1]++;
			}
			
			// Calculate the bonus score
			while(true){
				count = 0;
				int min=INT_MAX;

				for(int j=0; j<6; j++){
					if(a[j] == 0)
						continue;
					if(min > a[j]){
						min = a[j];
					}
					count++;
				}


				if(count < 4)
					break;

				pscore += min * ((count==4) ? 1 : ((count==5) ? 2 : 4));

				for(int j=0; j<6; j++){
					if(a[j] == 0)
						continue;
					else a[j] -= min;
				}

			}
			if(score == pscore){
				tie = 1;
			}

			if(score < pscore){
				score = pscore;
				winner = i;
				tie = 0;
			}

		}

		if(tie){
			cout << "tie" << endl;
		}

		else if(winner == 0)
			cout << "chef" << endl;

		else 
			cout << winner+1 << endl;
	}
	return 0;
}