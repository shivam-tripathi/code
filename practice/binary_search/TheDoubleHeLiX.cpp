#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int binsearch(vector<int> &a, int val) {
    int low = 0, high = a.size()-1, mid;
    while(low <= high) {
        mid = (low+high)/2;
        // cout << "\t" << mid << " : " << a[mid] << endl;
        if (a[mid] == val) {
            return mid;
        }
        if (a[mid] < val) {
            low = mid+1;
        }
        if (a[mid] > val) {
            high = mid-1;
        }
    }
    return -1;
}

int main() {
    while(true) {
        int n1, n2;
        cin >> n1;
        if (n1 == 0) break;
        vector<int> a(n1);
        vector<pii> match;

        for(int i=0; i<n1; i++) {
            cin >> a[i];
        }

        cin >> n2;
        vector<int> b(n2);

        for(int i=0; i<n2; i++) {
            cin >> b[i];
            int index = binsearch(a, b[i]);
            if (index != -1) {
                // cout << b[i] << " matches " << a[index] << endl;
                match.push_back(make_pair(index, i));
            }
        }

        // cout << "Last " << a[n1-1] << " " << b[n2-1] << endl;
        match.push_back(make_pair(n1-1, n2-1));

        vector<long long> sum_a(n1+1);

        sum_a[n1] = 0;
        for(int i=n1-1; i>=0; i--) {
            sum_a[i] = sum_a[i+1] + a[i];
        }

        vector<long> sum_b(n2+1);
        sum_b[n2] = 0;
        for(int i=n2-1; i>=0; i--) {
            sum_b[i] = sum_b[i+1] + b[i];
        }

        long long ans = 0;

        int preva = -1, prevb = -1;
        for(int i=0; i<match.size(); i++) {
            int ia = match[i].first;
            int ib = match[i].second;

            // cout << a[ia] << " and " << b[ib] << endl;

            int suma = sum_a[preva+1] - sum_a[ia+1];
            int sumb = sum_b[prevb+1] - sum_b[ib+1];

            // cout << suma << " " << sumb << endl;

            ans += max(suma, sumb);
            preva = ia;
            prevb = ib;
        }
        cout << ans << endl;
    }
	return 0;
}
