#include <bits/stdc++.h>
using namespace std;

#define MAX INT_MAX
#define abs_int_min abs(INT_MIN)

 
void printPairs(int arr[], int arr_size, int sum)
{
  int i, temp;
  bool binMap[MAX] = {0}; /*initialize hash map as 0*/
 
  for (i = 0; i < arr_size; i++)
  {
      temp = sum - arr[i];
      cout << temp << " " << arr[i] << " " << sum << endl;
      if (temp >= 0 && binMap[temp] == 1){
         printf("Pair with given sum %d is (%d, %d) \n", 
                 sum, arr[i], temp);
      }
      if(temp < 0 && binMap[temp+abs_int_min] == 1){
                 printf("Pair with given sum %d is (%d, %d) \n", 
                 sum, arr[i], temp);
      }
      if(arr[i] > 0)
        binMap[arr[i]] = 1;
      else 
        binMap[abs_int_min + arr[i]] = 1;
      cout << arr[i] << "added to binMap" << endl;
  }
}
 
/* Driver program to test above function */
int main()
{
    int A[] = {-1 , 4 , 17 , 4 , 1 , 8};
    int n = 16;
    int arr_size = sizeof(A)/sizeof(A[0]);
 
    printPairs(A, arr_size, n);
 
    return 0;
}
