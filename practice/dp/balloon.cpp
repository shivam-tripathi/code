#include <bits/stdc++.h>
using namespace std;

struct product{
	int mult, left, index, right;
};

struct pd{
	int parent, child;
};

struct Comp{
    bool operator()(const product& a, const product& b){
        return a.mult < b.mult;
    }
};

int main(int argc, char const *argv[]){
	int n;
	scanf("%d", &n);
	
	int a[n];

	bool visited[n] = {0};
	pd pedigree[n];

	priority_queue <product, vector<product>, Comp> pq;

	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}

	for(int i=1; i<n-1; i++){
		product temp = { a[i-1] * a[i] * a[i+1], i-1, i, i+1};

		pq.push((product){.mult = a[i-1] * a[i] * a[i+1], .left = i-1, .index = i, .right = i+1});
		pedigree[i].parent = i-1;
		pedigree[i].child = i+1;
	}


	// Count stores successful pops and in stores total number of elements inside priority_queue
	int count = 0, in = n-2, sum=0;

	while(count < n-2 && in > 0){
		product temp = pq.top();
		pq.pop();
		in--;


		if(!visited[temp.left] && !visited[temp.index] && !visited[temp.right]){
			sum += temp.mult;

			cout << a[temp.left] << " * " << a[temp.index] << " * " << a[temp.right] << " = " << temp.mult << endl;

			visited[temp.index] = true;


			int parent = pedigree[temp.index].parent;
			int child = pedigree[temp.index].child;

			pedigree[parent].child = child;
			pedigree[child].parent = parent;


			if(parent){
				pq.push((product){.mult = a[pedigree[parent].parent] * a[parent] * a[pedigree[parent].child], 
					pedigree[parent].parent, 
					parent, 
					pedigree[parent].child
				});
			}


			// cout << pedigree[child].parent << " " << child << " " << pedigree[child].child << endl;
			
			if(child < n-1){
				pq.push((product){.mult = a[pedigree[child].parent] * a[child] * a[pedigree[child].child],
					pedigree[child].parent,
					child,
					pedigree[child].child
				});
			}

			in += 2;

			count++;
		}
	}

	cout << sum << endl;
	return 0;
}