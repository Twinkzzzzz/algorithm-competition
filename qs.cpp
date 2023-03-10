#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[10001],n;
int q;

void qsort(int t,int w)
{
	if (t>=w) return;
	//cout << endl;
	//cout << t << " " << w << endl;
	int m,i,j;
	m=a[t];i=t;j=w;
	//cout << a[m] << endl;
	while(i<j)
	{
		while(i<j && a[i]<=m) i++;
		while(i<j && m<=a[j]) j--;
		if (i<j)
		{
			swap(a[i],a[j]);
		}
	}
	/*cout << i << " "<<j << endl;
	
	for(int k=1;k<=n ;++k)
	{
		cout << a[k] << " ";
	}
	cout << endl;*/
	
	//cin >> q;
	a[t]=a[i];
	a[i]=m;
	qsort(i+1,w);
	qsort(t,i-1);
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;++i)
	{
		cin >> a[i];
	} 
	qsort(1,n);
	for(int i=1;i<=n;++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
