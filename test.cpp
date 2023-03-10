#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n;
	int a[10001];
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i];
	int ans=0;
	for(int i=1;i<n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			if(a[i]>a[j]) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
