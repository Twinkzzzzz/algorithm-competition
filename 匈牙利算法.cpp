#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,e;
int map[501][501];
int vis[501],pp[501];

bool find(int x)
{
	for(int i=1;i<=m;++i)
	{
		if (map[x][i] && !vis[i])
		{
			vis[i]=1;
			if (!pp[i] || find(pp[i]))
			{
				pp[i]=x;
				return 1;
			} 
		}
	}
	return 0;
}

int main()
{
	cin >> n >> m >> e;
	memset(map,0,sizeof(map));
	int p,q;
	for(int i=1;i<=e;++i)
	{
		cin >> p >> q;
		map[p][q]=1;
	}
	int ans=0;
	memset(pp,0,sizeof(pp));
	for(int i=1;i<=n;++i)
	{
		memset(vis,0,sizeof(vis));
		ans+=find(i);
	}
	cout << ans << endl;
	return 0;
}
