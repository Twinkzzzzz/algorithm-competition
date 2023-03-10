#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long a[1000100];
int n;

int main()
{
	cin >> n;
	a[0]=1;
	a[1]=0;
	a[2]=1;
	for(int i=3;i<=n;++i) a[i]=(a[i-2]+a[i-3])%998244353;
	cout << a[n] << endl;
	return 0;
}
