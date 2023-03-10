#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;
long long a[200020],b[200020];

long long getmax(long long p,long long q)
{
	if (p>q) return p; else return q;
}

void print()
{
	for(int i=1;i<=n;++i) cout << a[i] << " ";
	cout << endl;
	for(int i=1;i<=m;++i) cout << b[i] << " ";
	cout << endl;
	return;
}

int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;++i) cin >> a[i];
	for(int i=1;i<=m;++i) cin >> b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	//print();
	if(a[1]*b[1]>=0 || a[n]*b[m]>=0)
	{
		if(a[1]*b[1]>a[n]*b[m]) swap(a[1],a[n]);
	}
	else
	{
		if(a[1]>0) swap(a[1],a[n]);
	}
	cout << a[n] << " ";
	sort(a+1,a+n);
	//print();
	long long ans=a[1]*b[1];
	ans=getmax(ans,a[n-1]*b[m]);
	ans=getmax(ans,a[1]*b[m]);
	ans=getmax(ans,a[n-1]*b[1]);
	cout << ans << endl;
	return 0;
} 
