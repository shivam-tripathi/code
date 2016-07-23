#include <bits/stdc++.h>
using namespace std;

#define NUM_OF_CHAR ((int)pow(2,sizeof(char)*8))
int main(int argc, char const *argv[])
{
	string str;
	cin >> str;

	int ch[NUM_OF_CHAR] = {0}, i;

	for(i=0; i<str.size(); i++){
		ch[str[i]]++;
	}

	for(i=0; i<str.size(); i++){
		if(ch[str[i]] == 1){
			break;
		}
	}

	if(i < str.size())
		cout << str[i] << endl;
	else 
		cout << "No non-repeating character\n";
	return 0;
}
