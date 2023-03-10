#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n,e;
int graph[1001][1001][2];
int num[1001],dis[1001],cnt[1001];
queue<int>q;

int main()
{
	//求最大值 
	cout << "a-b<=c\n";
	cin >> n >> e;
	int x,y,t;
	memset(graph,0,sizeof(graph));
	memset(num,0,sizeof(num));
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=e;++i)
	{
		cin >> x >> y >> t;
		num[y]++;
		graph[y][num[y]][0]=x;
		graph[y][num[y]][1]=t;	
	}
	int x0,sta;
	cin >> x0 >> sta;
	dis[x0]=0;
	cnt[x0]=1;
	q.push(x0);
	int flag=0;
	while(!q.empty() && !flag)
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
				cnt[y]=cnt[x]+1;
				if(cnt[y]>n)
				{
					flag=1;
					break;
				}
				q.push(y);
			}
			if(flag) break;
		}
	}
	if(flag) cout << "null";
	else
	{
		for(int i=1;i<=n;++i) cout << dis[i] << " ";
	}
	cout << endl;
	return 0;
}
