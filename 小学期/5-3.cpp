#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int L,R;
int a[10100],b[10100],v[10100];
int dp[10100][10100];

int getmin(int a,int b)
{
	if(a<b) return a; else return b;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	cin >> L >> R;
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;++i)
	{
		cin >> a[i] >> b[i];
		v[i]=a[i]-b[i];
	}
	for(int i=0;i<=n;++i) dp[i][0]=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=R;++j)
		{
			dp[i][j]=dp[i-1][j];
			if(j>=b[i]) dp[i][j]=getmin(dp[i][j],dp[i-1][j-b[i]]+v[i]);
		}
	}
	int ans=1000000000;
	for(int i=L;i<=R;++i)
	{
		ans=getmin(ans,dp[n][i]);
	}
	if(ans<=100000000) cout << ans << endl; else cout << "-1\n";
	return 0;
}
