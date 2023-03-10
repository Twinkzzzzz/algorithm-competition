#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

string s,t;
int next[1001];

void getnext()
{
	int i=0;
	int j=-1;
	next[0]=-1;
	while(i<t.length())
	{
		if (j==-1 || t[i]==t[j])
		{
			i++;
			j++;
			if (t[i]==t[j]) next[i]=next[j]; else next[i]=j;  //*重要 
		}
		else j=next[j];
	}
	return;
}

int main()
{
	cin >> s >> t;
	memset(next,0,sizeof(next));
	getnext();
	int i=0,j=0,f=0;
	
	//for(int i=0;i<=t.length();++i) cout << next[i] << " ";
	//cout << endl;
	
	while(i<s.length() && j<t.length())
	{
		//cout << i << "-" << j << endl;
		while((j==-1 || s[i]==t[j]) && i<s.length() && j<t.length())
		{
			i++;
			j++;
		}
		//cout << i << " " << j << endl;
		if (j==t.length())
		{
			cout << i-j << endl;
			f=1;
		}
		j=next[j];
		if (j==-1)     //为什么?
		{
			i++;
			j++;
		}
		//cout << i << " " << j << endl;
	}
	if (!f) cout << "-1\n";
	return 0;
}
