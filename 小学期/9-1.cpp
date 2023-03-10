#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
string a[100010];

string deal(string k)
{
	char c=k[0];
	int add=97+26-c;
	string ans="";
	int t;
	for(int i=0;i<k.length();++i)
	{
		t=k[i]-97;
		t=(t+add)%26+97;
		ans+=(char)(t);
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;++i)
	{
		cin >> a[i];
		a[i]=deal(a[i]);
	}
	//for(int i=0;i<n;++i) cout << a[i] << endl;
	sort(a,a+n);
	cout << a[0] << endl;
	return 0;
}
