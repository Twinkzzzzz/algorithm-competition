#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int t[10000][15];
int a[10001],n;

int maxn(int a,int b)
{
	if (a>b) return a; else return b;
}

int find(int x)
{
	int p=1,ans=0;
	while(p<=x)
	{
		ans++;
		p*=2;
	}
	return ans-1;
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;++i)
	{
		cin >> a[i];
		t[i][0]=a[i];
	}
	for(int i=1;i<=find(n);++i)
	{
		for(int j=1;j<=n-(1<<i)+1;++j)
		{
			t[j][i]=maxn(t[j][i-1],t[j+(1<<(i-1))][i-1]);
		}
	}
	for(int i=0;i<=find(n);++i)
	{
		for(int j=1;j<=n-(1<<i)+1;++j)
		{
			cout << t[j][i] << " ";
		}
		cout << endl;
	}
	return 0;
}
