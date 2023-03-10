#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool bigger(long long x1,long long y1,long long x2,long long y2)
{
	if(x1*y2>x2*y1) return 1; else return 0;
}

long long a[100010],b[100010];
int n;

void qsort(int t,int w)
{
	if (t>=w) return;
	int i=t,j=w;
	long long m1=a[t];
	long long m2=b[t];
	while(i<j)
	{
		while(i<j && bigger(m1,m2,a[j],b[j])) j--;
		if(i<j)
		{
			a[i]=a[j];
			b[i]=b[j];
			i++;
		}
		while(i<j && bigger(a[i],b[i],m1,m2)) i++;
		if(i<j)
		{
			a[j]=a[i];
			b[j]=b[i];
			j--;
		}
	}
	a[i]=m1;
	b[i]=m2;
	qsort(t,i-1);
	qsort(i+1,w);
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i] >> b[i];
	qsort(1,n);
	for(int i=1;i<=n;++i) cout << a[i] << "/" << b[i] << endl;
	return 0;
}
