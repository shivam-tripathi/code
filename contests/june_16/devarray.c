#include <stdio.h>
#include <stdlib.h>
#define found 100002

int compare(const void *a, const void *b){
    return *(long long*)a - *(long long*)b;
}

int find(long long arr[], int size, long long key){
    int begin = 0, end = size-1, mid = 0;
    while(begin <= end){
        mid = (begin+end)/2;
        if(key == arr[mid]){
            return found;
        }
        else if (key < arr[mid]){
            end = mid-1;
        }
        else {
            begin = mid+1;
        }
    }
    if(arr[begin] > key){
        return begin-1;
    }
    else if(begin >= size){
        return size-1;
    }
    else {
        return begin;
    }
}

int main(){
    int n, q;
    scanf("%d %d\n", &n, &q);
    long long arr[n], test;
    int i;
    for(i=0; i<n; i++) {
        scanf("%lld",&arr[i]);
    }
    qsort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), compare);
    while(q--){
        scanf("%lld",&test);
        int index = find(arr, n, test);
        if(index == found)
            printf("Yes\n");
        else if(index < 0 || index >= n-1)
            printf("No\n");
        else{
            printf("Yes\n");
        }
    }
}
