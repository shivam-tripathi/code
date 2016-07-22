#include <iostream>
#include <stdlib.h>
#include <string.h>

/*******************************************************************************
*																			   *
*   --------------------------Sorting Algorithms----------------------------   *
* 																               *
*******************************************************************************/

#define heapsort(type, arr, size) \
{HeapSort<type> __hs(arr, size); __hs.heapSort();}

#define mergesort(type, arr, size) \
{MergeSort<type> __ms(arr, size); __ms.mergeSort();}

#define quicksort(type, arr, size) \
{QuickSort<type> __qs(arr, size); __qs.quickSort();}

#define shellsort(type, arr, size) \
{ShellSort<type> __ss(arr, size); __ss.shellSort();}

#define radixsort(type, arr, size) \
{RadixSort<type> __rs(arr, size); __ss.radixSort();}

#define bubblesort(type, arr, size) \
{ BubbleSort<type> __bs(arr, size); __bs.bubbleSort();}

#define insertionsort(type, arr, size) \
{ InsertionSort<type> __is(arr, size); __is.insertionSort();}

using namespace std;

template<class T>
int comp(T a, T b){
	return a<b;
}


/*******************************************************************************
*																			   *
*   -----------------------------Merge Sort---------------------------------   *
*																               *
*******************************************************************************/


template<class T>
class MergeSort{
public:
	T* arr;
	int size;
	MergeSort(T* arr, int size){
		this->arr = arr;
		this->size = size;
	}
	void merge(int l, int m, int r){
		int n1 = m-l+1;
		int n2 = r-m;
		int L[n1], R[n2];
		for(int i=0; i<n1; i++) L[i] = arr[l+i];
		for(int i=1; i<=n2; i++) R[i-1] = arr[m+i];
		int i=0, j=0, k=l;
		while(i<n1 && j<n2){
			if(L[i] <= R[j]){
				arr[k++] = L[i++];
			}
			else{
				arr[k++] = R[j++];
			}
		}
		while(i<n1) arr[k++] = L[i++];
		while(j<n2)	arr[k++] = R[j++];
	}

	void mergeSort(){
		_mergeSort(0, size-1);
	}

	void _mergeSort(int l, int r){
		if(l<r){
			int m = l+(r-l)/2;
			_mergeSort(l, m);
			_mergeSort(m+1, r);
			merge(l,m,r);
		}
	}
};


/*******************************************************************************
*																			   *
*   ---------------------------  Heap Sort ---------------------------------   *
*																               *
*******************************************************************************/


template<class T>
class HeapSort{
public:
	T* arr;
	int size;
	HeapSort(T* _arr, int _size){
		arr = _arr;
		size = _size;
	}
	void heapify(int index, int n){
		int min=index;
		int l=2*index+1;
		int r=2*index+2;
		if(l<n && hcomp(arr[min],arr[l])){
			min=l;
		}
		if(r<n && hcomp(arr[min], arr[r])){
			min=r;
		}
		if(min!=index){
			swap(arr[min], arr[index]);
			heapify(min, n);
		}
	}
	void heapSort(){
		for(int i=size/2-1; i>=0; i--){
			heapify(i, size);
		}
		for(int i=size-1; i>=0; i--){
			swap(arr[0], arr[i]);
			heapify(0, i);
		}
	}
};


/*******************************************************************************
*																			   *
*   -------------------------- Insertion Sort ------------------------------   *
*																               *
*******************************************************************************/

template<class T>
class InsertionSort{
public:
	T* arr;
	int size;
	int (*compare)(T a, T b);
	InsertionSort(T* _arr, int _size){
		arr = _arr;
		size = _size;
	}
	void insertionSort(){
		for(int i=1; i<size; i++){
			T temp = arr[i];
			while(i>0 && temp < arr[i-1]){
				arr[i] = arr[i-1];
				i--;
			}
			arr[i] = temp;
		}
	}
};

/*******************************************************************************
*																			   *
*   --------------------------- Bubble Sort --------------------------------   *
*																               *
*******************************************************************************/

template<class T>
class BubbleSort{
public:
	T* arr;
	int size;
	int (*compare)(T a, T b);
	BubbleSort(T* _arr, int _size, int (*_compare)(T a, T b) = NULL){
		arr = _arr;
		size = _size;
		compare = _compare;
	}
	void bubbleSort(){
		for(int i=0; i<size-1; i++){
			for(int j=0; j<size-i-1; j++){
				if(arr[j+1] > arr[j]){
					swap(arr[j], arr[j+1]);
				}
			}
		}
	}
};

/*******************************************************************************
*																			   *
*   --------------------------- Quick Sort --------------------------------   *
*																               *
*******************************************************************************/

template<class T>
class QuickSort{
public:
	T* arr;
	int size;
	QuickSort(T* _arr, int _size){
		arr = _arr;
		size = _size;
	}
	int partition(int l, int r){
		int index=l;
		for(int i=l+1; i<=r; i++){
			if(arr[i]<arr[index]){
				swap(arr[i], arr[index]);
				index++;
				if(arr[i]<arr[index])
					swap(arr[i], arr[index]);
			}
		}
		return index;
	}

	void quickSort(){
		_quickSort(0, size-1);
	}

	void _quickSort(int l, int r){
		if(l==r || l>r)
			return;
		int q=partition(l, r);
		_quickSort(l, q-1);
		_quickSort(q+1, r);
	}
};


/*******************************************************************************
*																			   *
*   ---------------------------- Shell Sort --------------------------------   *
*																               *
*******************************************************************************/

template<class T>
class ShellSort{
public:
	int size;
	T* arr;
	ShellSort(T* _arr, int _size){
		size = _size;
		arr = _arr;
	}
	void shellSort(){
		int gap = ((size/2)%2 == 0) ? (size/2 - 1) : (size/2), j;
		while(gap>0){
			for(int i = gap; i < size; i++){
				int temp = arr[i];
				for(j=i; j>=gap && arr[j-gap] > temp; j -= gap){
					arr[j] = arr[j-gap];
				}
				arr[j] = temp;
			}
			gap = ((gap/2)%2 == 0) ? (gap/2 - 1) : (gap/2);
		}
	}
};

/*******************************************************************************
*																			   *
*   ---------------------------Utility print--------------------------------   *
*																               *
*******************************************************************************/

template<class T>
void print(T* arr, int size){
	for(int i=0; i<size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

template<class T>
void comparePerformance(T arr[], int size, int compare(void*a, void*b));

int main(){
	int size = 5;
	int arr[size], dup[size];
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]);i++)
		arr[i] = (rand()) * 0.0000001;
	//memcpy(dup, arr, size*sizeof(arr[0]));
	//cout << "Heap sort" << endl;
	//heapsort(int, arr, size);
	//print(arr, size);

	//memcpy(arr, dup, size*sizeof(dup[0]));
	//shellsort(int, arr, size);
	insertionsort(int, arr, size);
	print(arr, size);
	//cout << "Merge sort" << endl;
	//mergesort(int, arr, size);
	//print(arr, size);

	//initialize(arr, dup, size);
	//cout << "Quick sort" << endl;
	//quicksort(int, arr, size);
	//print(arr, size);
}
