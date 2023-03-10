#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dp[10010][10010];
int n,c;
int a[10010],b[10010],v[10010],Time[10010];

void qsort(int t,int w)
{
	if(t>=w) return;
	int i=t;
	int j=w;
	int mid=v[(t+w)/2];
	while(i<j)
	{
		while(v[i]>mid) i++;
		while(v[j]<mid) j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			swap(b[i],b[j]);
			swap(v[i],v[j]);
			swap(Time[i],Time[j]);
			i++;
			j--;
		}
	}
	qsort(t,j);
	qsort(i,w);
}

int getmax(int a,int b)
{
	if(a>b) return a; else return b;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c;
	for(int i=1;i<=n;++i)
	{
		cin >> a[i] >> b[i];
		v[i]=a[i]-b[i];
		Time[i]=getmax(a[i],b[i]);
	}
	qsort(1,n);
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=c;++j)
		{
			dp[i][j]=dp[i-1][j];
			if(j+v[i]<=c && j>=b[i]) dp[i][j]=getmax(dp[i][j],dp[i-1][j-b[i]]+1);
			if(j>=Time[i]) dp[i][j]=getmax(dp[i][j],dp[i-1][j-Time[i]]+1);
		}
	}
	/*
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=c;++j) cout << dp[i][j] << " ";
		cout << endl;
	}
	*/
	cout << dp[n][c] << endl;
	return 0;
}
