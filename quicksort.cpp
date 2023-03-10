#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[100100];
int n;

void qsort(int t,int w)
{
	if (t>=w) return;
	int i=t,j=w;
	int mid=a[t];
	while(i<j)
	{
		while(mid<a[j] && i<j) j--;
		if (i<j)
		{
			a[i]=a[j];
			i++;
		}
		while(mid>a[i] && i<j) i++;
		if(i<j)
		{
			a[j]=a[i];
			j--;
		}
	}
	a[i]=mid;
	qsort(t,i-1);
	qsort(i+1,w);
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;++i) cin >>a[i];
	qsort(1,n);
	for(int i=1;i<=n-1;++i) cout << a[i] << " ";
	cout << a[n] << endl;
	cout << endl;
	return 0;
}
