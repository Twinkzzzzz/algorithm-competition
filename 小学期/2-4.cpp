#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
double a[100020];

int main()
{
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i];
	sort(a+1,a+n+1);
	double tot=a[n],count=1;
	double ans=tot*tot,tmp;
	for(int i=n-1;i>=1;--i)
	{
		tot+=a[i];
		count++;
		tmp=tot*tot/count;
		if(tmp>ans) ans=tmp; else break;
	}
	printf("%.7lf\n",ans);
	return 0;
} 
