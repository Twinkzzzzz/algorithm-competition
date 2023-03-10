#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n,m,t;
int a[1001];

bool check()
{
	int tmp=0;
	for(int i=1;i<=t;++i)
	{
		tmp=tmp*10+a[i];
		tmp=tmp%m;
	}
	if(tmp>0) return 0; else return 1;
}

int main()
{
	cin >> n >> m;
	t=log(1000000000)/log(n);
	memset(a,0,sizeof(a));
	a[t]++;
	while(!a[0])
	{
		if(check())
		{
			int i=1;
			while(!a[i]) i++;
			for(int j=i;j<=t;++j) cout << a[j];
			cout << endl;
			break;
		}
		int i=t;
		while(a[i]==n-1)
		{
			a[i]=0;
			i--;
		}
		a[i]++;
	}
	return 0;
}
