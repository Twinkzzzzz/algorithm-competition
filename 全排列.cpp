#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[101],n;

int main()
{
	cin >> n;
	for(int i=0;i<=n;++i) a[i]=i;
	while(a[0]==0)
	{
		for(int i=1;i<=n;++i) cout << a[i] << " ";
		cout << endl;
		int i=n,j=n;
		while(a[i]<a[i-1]) i--;
		while(a[j]<a[i-1]) j--;
		swap(a[i-1],a[j]);
		for(int k=i;k<=(i+n)/2;++k) swap(a[k],a[i+n-k]);
	}
	return 0;
}
