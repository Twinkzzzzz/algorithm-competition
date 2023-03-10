#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,e;
int edge[1001][1001];
int px[1001],py[1001];
int vis[1001];

int match(int k)
{
	int tmp,t;
	for(int i=1;i<=edge[k][0];++i)
	{
		tmp=edge[k][i];
		if(vis[tmp]) continue;
		vis[tmp]=1;
		if(!py[tmp])
		{
			py[tmp]=k;
			return 1;
		}
		else
		{
			t=py[tmp];
			py[tmp]=k;
			return match(t);
		}
	}
	return 0;
}

int main()
{
	cin >> n >> m >> e;
	int x,y;
	memset(edge,0,sizeof(edge));
	for(int i=1;i<=e;++i)
	{
		cin >> x >> y;
		edge[x][0]++;
		edge[x][edge[x][0]]=y;
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		memset(vis,0,sizeof(vis));
		ans+=match(i);
	}
	cout << ans << endl;
	for(int i=1;i<=m;++i) cout << py[i] << " ";
	cout << endl;
}
