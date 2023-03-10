#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n;
int a[100];
int ans=0;
int count=0;

void search(int k)
{
	if (k==n)
	{
		ans++;
		if(count<3)
		{
			for (int i=0;i<n-1;i++) cout << a[i]+1 << " ";
			cout << a[n-1]+1 << endl;
			count++;
		}
		return;
	}
	int j;
	for (int i=0;i<n;i++)
	{	
		for (j=0;j<k;j++)
		{
			if (a[j]==i || abs(a[j]-i)==abs(k-j)) break;
		}
		if (j==k)
		{
			a[k]=i;
			search(k+1);
		}
	}
}

int main()
{
	cin >> n;
	search(0);
	cout << ans << endl;
	return 0;
}
