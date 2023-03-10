#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

string s,t;
int Next[1001];
 
void getNext()
{
	int i=0;
	int j=-1;
	Next[0]=-1;
	while(i<t.length())
	{
		if (j==-1 || t[i]==t[j])
		{
			i++;
			j++;
			if (t[i]==t[j]) Next[i]=Next[j]; else Next[i]=j;
		}
		else j=Next[j];
	}
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> t;
	memset(Next,0,sizeof(Next));
	s=s+s;
	getNext();
	int i=0,j=0,f=0;
	while(i<s.length() && j<t.length())
	{
		while((j==-1 || s[i]==t[j]) && i<s.length() && j<t.length())
		{
			i++;
			j++;
		}
		if (j==t.length())
		{
			f=1;
			break;
		}
		j=Next[j];
		if (j==-1)
		{
			i++;
			j++;
		}
	}
	if(f) cout << "Yes\n";
	else
	{
		string s1="";
		for(i=0;i<s.length();++i) s1=s[i]+s1;
		i=0;
		j=0;
		while(i<s1.length() && j<t.length())
		{
			while((j==-1 || s1[i]==t[j]) && i<s1.length() && j<t.length())
			{
				i++;
				j++;
			}
			if (j==t.length())
			{
				f=1;
				break;
			}
			j=Next[j];
			if (j==-1)
			{
				i++;
				j++;
			}
		}
	}
	if(f) cout << "Yes\n"; else cout << "No\n";
	return 0; 
}
