#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[101];

void qs(int t,int w)
{
	if (t>=w) return;
	int i=t,j=w,mid=a[t];
	while(i<j)
	{
		while(i<j && a[j]>mid) j--;
		if (i<j)
		{
			a[i]=a[j];
			i++;
		}
		while(i<j && a[i]<mid) i++;
		if (i<j)
		{
			a[j]=a[i];
			j--;
		}
	}
	a[i]=mid;
	qs(t,i-1);
	qs(i+1,w);
}

int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i];
	qs(1,n);
	for(int i=1;i<=n;++i) cout << a[i] << " ";
	return 0;
} 
