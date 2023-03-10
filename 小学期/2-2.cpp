#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long n,m;
long long l[200010],r[200010];

void qsort(int t,int w)
{
	if(t>=w) return;
	int i=t;
	int j=w;
	int mid=l[(t+w)/2];
	while(i<j)
	{
		while(l[i]<mid) i++;
		while(l[j]>mid) j--;
		if(i<=j)
		{
			swap(l[i],l[j]);
			swap(r[i],r[j]);
			i++;
			j--;
		}
	}
	qsort(t,j);
	qsort(i,w);
}

long long getmax(long long a,long long b)
{
	if(a>b) return a; else return b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1;i<=m;++i) cin >> l[i] >> r[i];
	qsort(1,m);
	int lst=0,ans=0,maxn,i;
	maxn=0;
	for(i=1;i<=m;++i)
	{
		if(lst>=n) break;
		if(l[i]<=lst+1) maxn=getmax(maxn,r[i]);
		else
		{
			ans++;
			lst=maxn;
			maxn=getmax(maxn,r[i]);
			//cout << i << " " << lst << endl;
		}
	}
	if(lst<n) ans++;
	cout << ans << endl;
	return 0;
}
