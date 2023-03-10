#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int map[100][100],lowcost[100],path[100],vis[100];
int n,e;

int prim(int head)
{
	int minn,tp,ans=0;
	for(int i=1;i<=n;++i) lowcost[i]=map[head][i];
	for(int i=1;i<=n;++i) path[i]=head;
	//cout << "head=" << head << endl;
	memset(vis,0,sizeof(vis));
	vis[head]=1;
	for(int i=1;i<n;++i)
	{
		//for(int j=1;j<=n;++j) cout << lowcost[j] << " ";
		tp=0;
		minn=99999999;
		for(int j=1;j<=n;++j)
		{
			if (lowcost[j]!=0 && lowcost[j]<minn && !vis[j])
			{
				minn=lowcost[j];
				tp=j;
			}
		}
		//cout << tp << " ";
		ans+=minn;
		vis[tp]=1;
		for(int j=1;j<=n;++j)
		{
			if (vis[j]) continue;
			if ((map[tp][j]<lowcost[j]||lowcost[j]==0) && map[tp][j]!=0)
			{
				lowcost[j]=map[tp][j];
				path[j]=tp;
			}
		}
		lowcost[tp]=0;
	}
	return ans;
}

int main()
{
	cin >> n >> e;
	memset(map,0,sizeof(map));
	int p,q,l;
	for(int i=1;i<=e;++i)
	{
		cin >> p >> q >> l;
		map[p][q]=map[q][p]=l;
	}
	for(int i=1;i<=n;++i) cout << prim(i) << " ";
	return 0;
}
