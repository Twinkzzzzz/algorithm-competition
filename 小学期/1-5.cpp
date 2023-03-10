#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long a[30];
	for(int i=1;i<=n;++i) cin >> a[i];
	long long sum;
	int count,ans=0;
	for(int i=1;i<(1<<n);++i)
	{
		sum=0;
		count=0;
		for(int j=1;j<=n;++j)
		{
			if((1<<(j-1)) & i)
			{
				sum+=a[j];
				count++;
			}
		}
		if((!sum) && (!(count%2))) ans++; 
	}
	cout << ans << endl;
	return 0;
}
