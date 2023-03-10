#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[100100];
int n;

void qsort(int t,int w)
{
	if(t>=w) return;
	int i=t,j=w;
	int mid=a[(t+w)/2];
	while(i<j)
	{
		while(a[i]<mid) i++;
		while(a[j]>mid) j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	//swap(a[t],a[i]);
	qsort(t,j);
	qsort(i,w);
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
