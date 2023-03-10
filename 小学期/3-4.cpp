#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,k;
int d[100100];

bool check(int t)
{
	int s=0;
	int lst=0;
	for(int i=1;i<=n;++i)
	{
		if(d[i]-lst>=t)
		{
			s++;
			lst=d[i];
		}
	}
	if(k-lst<t) s--;
	if(s>=n-m) return 1; else return 0;
}

int main()
{
	cin >> n >> m >> k;
	for(int i=1;i<=n;++i) cin >> d[i];
	sort(d+1,d+n+1);
	d[0]=0;
	d[n+1]=k;
	int t=1,w=k/(n-m+1);
	int mid;
	while(t<=w)
	{
		mid=(t+w)/2;
		if(check(mid)) t=mid+1; else w=mid-1;
	}
	cout << t-1 << endl;
	return 0;
}
