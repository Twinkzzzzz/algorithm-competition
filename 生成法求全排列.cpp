#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[100];

int main()
{
	int n;
	cin >> n;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;++i) a[i]=i;
	int i,j,s=0;
	while(!a[0])
	{
		s++;
		//for(i=1;i<=n;++i) cout << a[i] << " ";
		//cout << endl;
		i=n;
		while(a[i]<a[i-1]) i--;
		j=n;
		while(a[j]<a[i-1]) j--;
		swap(a[i-1],a[j]);
		for(int j=i;j<=i+(n-i)/2;++j)
		{
			swap(a[j],a[n+i-j]);
		}
	}
	cout << "s=" << s << endl;
	return 0;
}
