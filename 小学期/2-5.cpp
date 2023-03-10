#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
long long a[200020],b[200020];

long long getmax(long long p,long long q)
{
	if(p<q) return q; else return p;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	long long maxa1=0,maxa2=0,mina1=0,mina2=0,maxb1=0,maxb2=0,minb1=0,minb2=0;
	for(int i=1;i<=n;++i)
	{
		cin >> a[i];
		if(a[i]>maxa1)
		{
			maxa2=maxa1;
			maxa1=a[i];
		}
		else if(a[i]>maxa2)
		{
			maxa2=a[i];
		}
		if(a[i]<mina1)
		{
			mina2=mina1;
			mina1=a[i];
		}
		else if(a[i]<mina2)
		{
			mina2=a[i];
		}
	}
	for(int i=1;i<=m;++i)
	{
		cin >> b[i];
		if(b[i]>maxb1)
		{
			maxb2=maxb1;
			maxb1=b[i];
		}
		else if(b[i]>maxb2)
		{
			maxb2=b[i];
		}
		if(b[i]<minb1)
		{
			minb2=minb1;
			minb1=b[i];
		}
		else if(b[i]<minb2)
		{
			minb2=b[i];
		}
	}
	int ans;
	if(maxa1*maxb1<mina1*minb1)
	{
		cout << mina1 << " ";
		cout << getmax(mina2*minb1,maxa1*maxb1) << endl;
	}
	else
	{
		cout << maxa1 << " ";
		cout << getmax(mina1*minb1,maxa2*maxb1) << endl;
	}
	return 0;
}
