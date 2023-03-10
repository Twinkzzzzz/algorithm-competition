#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
int a[10100];

int main()
{
	cin >> n >> m;
	if((1+n)*n/2<m)
	{
		cout << "It is raining!\n";
		return 0;
	}
	else
	{
		int s=0;
		memset(a,0,sizeof(a));
		for(int i=n;i>=1 && m;--i)
		{
			if(m>=i)
			{
				s++;
				m-=i;
				a[i]=1;
			}
		}
		cout << s << endl;
		for(int i=1;i<=n;++i) if(a[i]) cout << i << " ";
		cout << endl;
	}
} 
