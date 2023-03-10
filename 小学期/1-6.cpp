#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

long long a[40];
int n;
map<int,int>p;

int main()
{
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i];
	int sum;
	int t=n/2;
	for(int i=0;i<(1<<t);++i)
	{
		sum=0;
		for(int j=1;j<=t;++j)
		{
			if((1<<(j-1))&i) sum+=a[j];
		}
		p[sum]++;
	}
	int ans=0;
	for(int i=0;i<(1<<(n-t));++i)
	{
		sum=0;
		for(int j=1;j<=n-t;++j)
		{
			if((1<<(j-1))&i) sum+=a[j+t]; 
		}
		ans+=p[-sum];
	}
	cout << ans-1 << endl;
	return 0;
}
