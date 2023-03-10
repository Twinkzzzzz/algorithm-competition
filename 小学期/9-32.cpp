#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

string s,t;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> t;
	int lt=t.length();
	int ls=s.length();
	s+=s;
	int f;
	for(int i=0;i<ls;++i)
	{
		f=1;
		for(int j=0;j<lt && f;++j)
		{
			if(s[i+j]!=t[j]) f=0;
		}
		if(f)
		{
			cout << "Yes\n";
			return 0;
		}
		f=1;
		for(int j=0;j<lt && f;++j)
		{
			if(s[i+j]!=t[lt-1-j]) f=0;
		}
		if(f)
		{
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}
