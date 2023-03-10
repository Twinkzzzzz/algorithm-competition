#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

long long gcd(long long a,long long b)
{
	long long t;
	while(a%b)
	{
		t=a;
		a=b;
		b=t%a;
	}
	return b;
}

long long get(long long n)
{
	long long ans=n;
	for(int i=2;i<=sqrt(n);++i)
    {
        if(!(n%i)) ans=ans/i*(i-1);
        while(!(n%i)) n/=i;
    }
    if(n>1) ans=ans/n*(n-1);
    return ans;
}

long long t,a,m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long tg,ans;
	cin >> t;
	for(int i=1;i<=t;++i)
	{
		cin >> a >> m;
		tg=gcd(a,m);
		ans=get(m/tg);
		cout << ans << endl;
	}
	return 0;
 }

