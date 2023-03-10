#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[5000020],b[5000020];
int n,m,k;

int main()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	int i,j,ans;
	for(i=1;i<=n;++i) cin >> a[i];
	for(i=1;i<=m;++i) cin >> b[i];
	i=1;
	j=1;
	while(k)
	{
		//cout << k << " " << i <<  " " << j << endl;
		if(k && i<=n)
		{
			while(((j<=m && a[i]<b[j]) || j>m) && i<=n && k)
			{
				i++;
				k--;
			}
			ans=a[i-1];
		}
		//cout << k << " " << i <<  " " << j << endl;
		if(k && j<=m)
		{
			while(((i<=n && a[i]>=b[j]) || i>n) && j<=m && k)
			{
				j++;
				k--;
			}
			ans=b[j-1];
		}
		//cout << k << " " << i <<  " " << j << endl;
	}
	cout << ans << endl;
	return 0;
}
