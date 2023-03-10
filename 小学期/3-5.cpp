#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
long long t[100100];
long long c[100100];

void qsort(int h,int w)
{
	if(h>=w) return;
	int i=h;
	int j=w;
	int m1=t[(h+w)/2];
	int m2=c[(h+w)/2];
	while(i<j)
	{
		while(t[j]>m1 || (t[j]==m1 && c[j]>m2)) j--;
		while(t[i]<m1 || (t[i]==m1 && c[i]<m2)) i++;
		if(i<=j)
		{
			swap(t[i],t[j]);
			swap(c[i],c[j]);
			i++;
			j--;
		}
	}
	qsort(h,j);
	qsort(i,w);
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;++i)
	{
		cin >> t[i];
		c[i]=i;
	}
	qsort(1,n);
	//for(int i=1;i<=n;++i) cout << t[i] << " " << c[i] << endl;
	long long count=1;
	long long ans=0;
	long long tans=0;
	for(int i=2;i<=n;++i)
	{
		if(t[i]==t[i-1])
		{
			tans=tans+count*(c[i]-c[i-1]);
			count++;
			ans+=tans;
		}
		else
		{
			tans=0;
			count=1;
		}
	}
	cout << ans << endl;
	return 0;
}
