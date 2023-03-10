#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[100001],t[100005],p[1000005];
int n;

int lowbit(int n)
{
	return n&(-n);
}

void add(int k,int sum)
{
	while(k<=n)
	{
		p[k]+=sum;
		k+=lowbit(k);
	}
	return;
}

int getsum(int k)
{
	int ans=0;
	while(k>0)
	{
		ans+=p[k];
		k-=lowbit(k);
	}
	return ans;
}

int main()
{
	memset(a,0,sizeof(a));
	memset(t,0,sizeof(t));
	memset(p,0,sizeof(p));
	cin >> n;
	for(int i=1;i<=n;++i)
	{
		cin >> a[i];
		t[i]=a[i]-a[i-1];
		add(i,t[i]);
	}
	int e,to,we,s,ask;
	cin >> e;
	for(int i=1;i<=e;++i)
	{
		cin >> to >> we >> s;
		t[to]+=s;
		add(to,s);
		if (we>=n) continue;
		t[we+1]-=s;
		add(we+1,-s);
	}
	cin >> ask;
	cout << getsum(ask) << endl;
	return 0;	
}
