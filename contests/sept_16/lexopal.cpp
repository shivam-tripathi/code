#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--){
		string a;
		cin >> a;
		int begin = 0, end = a.length() -1, flag = 1;
		while(begin < end){
			if(a[end] == '.' && a[begin] == '.'){
				a[end] = a[begin] = 'a';
			}
			else if(a[end] == '.'){
				a[end] = a[begin];
			}
			else if(a[begin] == '.'){
				a[begin] = a[end];
			}
			else if(a[begin] != a[end]){
				flag = 0;
			}
			begin ++;
			end --;
		}
		if(end == begin && a[end] == '.')
			a[end] = 'a';
		if(flag == 1)
			cout << a << endl;
		else 
			cout << -1 << endl;
	}
	return 0;
}