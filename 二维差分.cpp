#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[101][101],t[101][101],sum[101][101],n,m;

void ins(int x1,int y1,int x2,int y2,int s)
{
	t[x1][y1]+=s;
	t[x1][y2+1]-=s;
	t[x2+1][y1]-=s;
	t[x2+1][y2+1]+=s;
	return;
}

int main()
{
	memset(a,0,sizeof(a));
	memset(t,0,sizeof(t)); 
	cin >> n >> m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			cin >> a[i][j];
			t[i][j]=a[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1];
		}
	}
	int x1,x2,y1,y2,s;
	cin >> x1 >> y1 >> x2 >> y2 >> s;
	ins(x1,y1,x2,y2,s);
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+t[i][j];
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j) cout << sum[i][j] << " ";
		cout << endl;
	}
	return 0;
} 
