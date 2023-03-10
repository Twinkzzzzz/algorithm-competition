#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;

priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
int n,e;
int graph[1001][1001];
int flag[1001],dis[1001];

int main()
{
	cin >> n >> e;
	memset(graph,0,sizeof(graph));
	memset(flag,0,sizeof(flag));
	memset(dis,0,sizeof(dis));
	int x,y,t;
	for(int i=1;i<=e;++i)
	{
		cin >> x >> y >>t;
		graph[x][y]=graph[y][x]=t;
	}
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;++i)
	{
		dis[i]=graph[i][1];
		if(dis[i]) q.push(make_pair(dis[i],i));
	}
	flag[1]=1;
	pair<int,int>tmp;
	int tjd,tdis;
	while(!q.empty())
	{
		tmp=q.top();
		q.pop();
		while(flag[tmp.second] && !q.empty())
		{
			tmp=q.top();
			q.pop();
		}
		if(flag[tmp.second]) break;
		tjd=tmp.second;
		tdis=tmp.first;
		dis[tjd]=tdis;
		flag[tjd]=1;
		for(int i=1;i<=n;++i)
		{
			if(flag[i]) continue;
			if(graph[tjd][i] && (tdis+graph[tjd][i]<dis[i] || !dis[i]))
			{
				dis[i]=tdis+graph[tjd][i];
				q.push(make_pair(dis[i],i));
			}
		}
	}
	for(int i=1;i<=n;++i) cout << dis[i] << endl;
	return 0;
}
