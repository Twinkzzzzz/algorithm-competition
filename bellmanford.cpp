#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,e;
int graph[1001][1001],edge[1001][3];
int dis[1001];

int main()
{
	memset(dis,0x3f,sizeof(dis));
	memset(graph,0,sizeof(graph));
	cin >> n >> e;
	int x,y,t;
	for(int i=1;i<=e;++i)
	{
		cin >> x >> y >> t;
		graph[x][y]=graph[y][x]=t;
		edge[i][0]=x;
		edge[i][1]=y;
		edge[i][2]=t;
	}
	dis[1]=0;
	int flag;
	for(int i=1;i<n;++i)
	{
		flag=0;
		for(int j=1;j<=e;++j)
		{
			x=edge[j][0];
			y=edge[j][1];
			t=edge[j][2];
			if(dis[x]+t<dis[y])
			{
				dis[y]=dis[x]+t;
				flag=1;
			}
			else if(dis[y]+t<dis[x])
			{
				dis[x]=dis[y]+t;
				flag=1;
			}
		}
		if(!flag) break;
	}
	flag=0;
	for(int j=1;j<=e;++j)
	{
		x=edge[j][0];
		y=edge[j][1];
		t=edge[j][2];
		if(dis[x]+t<dis[y])
		{
			dis[y]=dis[x]+t;
			flag=1;
			break;
		}
		else if(dis[y]+t<dis[x])
		{
			dis[x]=dis[y]+t;
			flag=1;
			break;
		}
	}
	if(flag) cout << "true\n"; else cout << "flase\n";
	for(int i=1;i<=n;++i) cout << dis[i] << " ";
	cout << endl;
}
