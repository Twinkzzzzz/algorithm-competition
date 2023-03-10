#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
int n,e;
int graph[1001][1001][2];
int dis[1001],flag[1001],num[1001];

int prim(int st)
{
	memset(dis,0,sizeof(dis));
	memset(flag,0,sizeof(flag));
	flag[st]=1;
	for(int i=1;i<=num[st];++i) q.push(make_pair(graph[st][i][1],graph[st][i][0]));
	pair<int,int> tmp;
	int ans=0;
	int i,k;
	while(!q.empty())
	{
		tmp=q.top();
		q.pop();
		i=tmp.second;
		while(flag[i] && !q.empty())
		{
			tmp=q.top();
			q.pop();
			i=tmp.second;
		}
		if(flag[i]) break;
		//cout << i << " " << tmp.first << endl;
		ans+=tmp.first;
		flag[i]=1;
		for(int j=1;j<=num[i];++j)
		{
			k=graph[i][j][0];
			if(flag[k]) continue;
			if(!dis[k] || (dis[k] && dis[k]>graph[i][j][1]))
			{
				dis[k]=graph[i][j][1];
				q.push(make_pair(dis[k],k));
			}
		}
	}
	return ans;
}

int main()
{
	cin >> n >> e;
	int x,y,t;
	memset(graph,0,sizeof(graph));
	memset(num,0,sizeof(num));
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
	for(int i=1;i<=n;++i)
	{
		cout << prim(i) << endl;
	}
	return 0;
}
