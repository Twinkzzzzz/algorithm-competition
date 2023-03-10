#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[10001],b[10001];

void copy(int t,int w)
{
	for(int i=t;i<=w;++i) a[i]=b[i];
	return;
}

void gbsort(int t,int w)
{
	//cout << t << " " << w << endl;
	if (t>=w) return;
	if (w==t+1)
	{
		if (a[t]>a[w]) swap(a[t],a[w]);
		return;
	}
	int mid=(t+w)/2;
	gbsort(t,mid);
	gbsort(mid+1,w);
	int i=t,j=mid+1,k=t;
	while(i<=mid && j<=w)
	{
		if (a[i]>a[j])
		{
			b[k]=a[j];
			j++;
		}
		else
		{
			b[k]=a[i];
			i++;
		}
		k++;
	}
	for(int p=i;p<=mid;p++)
	{
		b[k]=a[p];
		k++;
	}
	for(int p=j;p<=w;p++)
	{
		b[k]=a[p];
		k++;
	}
	copy(t,w);
	return;
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i];
	gbsort(1,n);
	for(int i=1;i<=n;++i) cout << a[i] << " ";
	cout << endl;
	return 0;
}
