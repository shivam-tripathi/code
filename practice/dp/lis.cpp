#include <bits/stdc++.h>

using namespace std;

// Dealing with binary search 
// Check the first and last element separately
// Then do the regular search in the array
// Just make sure you return the correct result in the end ;)

int bs(std::vector<int> tails, int elem, int size) {
	int low = 0, high = size-1, mid;

	while(low <= high) {
		mid = (high+low)/2;
		if (tails[mid] == elem)
			return mid;
		else if (tails[mid] > elem)
			high = mid-1;
		else if (tails[mid] < elem)
			low = mid+1;
	}

	if (tails[mid] < elem)
		mid++;
	return mid;
}

int CeilIndex(std::vector<int> &v, int l, int r, int key) {
    while (r-l > 1) {
    int m = l + (r-l)/2;
    if (v[m] >= key)
        r = m;
    else
        l = m;
    }
 
    return r;
}


int lis(vector<int> elements) {
	if (elements.size() == 0)
		return 0;

	vector<int> tails (elements.size(), 0);
	tails[0] = elements[0];

	int size = 0;

	for(int i=1; i<elements.size(); i++) {
		if (elements[i] < tails[0])
			tails[0] = elements[i];
		else if (elements[i] > tails[size]) 
			tails[++size] = elements[i];
		else {
			// int index = CeilIndex(tails, -1, size, elements[i]);
			int index = bs(tails, elements[i], size);
			/*
			Note this step very cautiously : As the search return the ceil index of the number, the new number will always 
			be inserted in the new position - as it increases the length of the previous size by one, and is smaller than 
			number already sitting on the index.
			*/
			tails[index] = elements[i];
		}
	}
	// cout << "Ends with " << tails[size] << endl;
	return size+1;
}


int main(int argc, char const *argv[])
{
	int size;
	cin >> size;
	vector<int> elements;
	int temp;
	for (int i=0; i<size; i++) {
		cin >> temp;
		elements.push_back(temp);
	}

	cout << lis(elements) << endl;

	return 0;
}