#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n,e;
queue<int>q;
int graph[1001][1001][2];
int cnt[1001],dis[1001],num[1001];

int main()
{
	cin >> n >> e;
	int x,y,t;
	memset(graph,0,sizeof(graph));
	for(int i=1;i<=e;++i)
	{
		cin >> x >> y >> t;
		num[x]++;
		graph[x][num[x]][0]=y;
		graph[x][num[x]][1]=t;
		num[y]++;
		graph[y][num[y]][0]=x;
		graph[y][num[y]][1]=t;
	}
	memset(cnt,0,sizeof(cnt));
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	q.push(1);
	cnt[1]=1;
	int flag=0;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(int i=1;i<=num[x];++i)
		{
			y=graph[x][i][0];
			t=graph[x][i][1];
			if(dis[y]>dis[x]+t)
			{
				dis[y]=dis[x]+t;
				cnt[y]=cnt[x]+1; //判断是否成环将cnt置于if外面 
				if(cnt[y]>n)
				{
					flag=1;
					break;
				}
				q.push(y);
			}
		}
		if(flag) break;
	}
	if(flag) cout << "true\n";
	else
	{
		for(int i=1;i<=n;++i) cout << dis[i] << " ";
	}
	cout << endl;
	
} 
