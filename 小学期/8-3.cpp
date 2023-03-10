#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

long long n;

int main()
{
	ios::sync_with_stdio(0);
	scanf("%lld",&n);
	long long k=n+1;
	long long sq=sqrt(n);
	long long i=0;
	long long t=n/(sq+1);
	cout << sq+t << endl;
	long long s1,s2;
	while(k>=2)
	{
		s1=n/(k-1);
		s2=n/k;
		printf("%lld %lld\n",k,s1-s2);
		k=n/(s1+1)+1;
	}
	return 0;
}
