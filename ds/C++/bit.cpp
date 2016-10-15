/*******************************************************************************
* Implementation of Binary index tree / Fenwick Tree
* The binary operation needed to be performed will have to be passed as a 
* function during the object call.
* If needed, to evaluate the index value, initial value maybe passed
*******************************************************************************/

#include <iostream>
#define PARENT(i, op) (i)op((i)&(-i))
using namespace std;

template<class T>
class BITree{
public:
	T* bitree;
	int size;
	T (*result)(T, T);
	BITree(T* arr, int _size, T (*_result)(T, T)){
		size = _size+1;
		result = _result;
		bitree = new T[size+1];
		this->construct(arr);
	}
	T evaluate(int index, T initial=0){
		T sum = initial;
		index += 1;
		while(index > 0){
			sum = (*result)(sum, bitree[index]);
			index = PARENT(index, -);
		}
		return sum;
	}
	void update(int index, T val){
		index += 1;
		while(index <= size){
			bitree[index] = (*result)(bitree[index],val);
			index = PARENT(index, +);
		}
	}
	void construct(int input[]){
		for(int i=0; i<size-1; i++){
			update(i, input[i]);
		}
	}
};

template<class T>
T __result(T a, T b){
	return a+b;
}

int main(){
	int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(freq)/sizeof(freq[0]);
    BITree<int> bit(freq, n, &__result);
    for(int i=0; i<n; i++){
    	cout << freq[i] << "  " << bit.evaluate(i) << endl;
    }
}