#include <bits/stdc++.h>
using namespace std;

int nCrModpDP(int n, int r, int p){
    int c[n+1], temp, prev;
    memset(c,0,sizeof(c));
    c[0] = 1;
    for(int i=0; i<=n; i++){
        temp = 0;
        for(int j=0; j<=i; j++){
            // Here j must be till min(i,r), but as I am printing pascal's triangle I am doing it till i
            // I made this mistake of calculating all last time to get a TLE :P
            // To avoid using two temporary variable, process the array in reverse order
            // That way there will be no conflicts :)
            prev = c[j];
            c[j] = (temp%p+c[j]%p)%p;
            temp = prev;
        }
    }
    return c[r];
}

int nCrModpLucas(int n, int r, int p)
{
   // Base case
   if (r==0)
      return 1;

   // Compute last digits of n and r in base p
   int ni = n%p, ri = r%p;

   // Compute result for last digits computed above, and
   // for remaining digits.  Multiply the two results and
   // compute the result of multiplication in modulo p.
   return (nCrModpLucas(n/p, r/p, p) * // Last digits of n and r
           nCrModpDP(ni, ri, p)) % p;  // Remaining digits
}

int main(){
    for(int i=0; i<=10;i++){
        for(int j=0; j<=i; j++){
            cout << nCrModpLucas(i,j,10000) << "  ";
        }
        cout << endl;
    }
}
