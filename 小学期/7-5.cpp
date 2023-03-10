#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef struct node
{
	int x;
	int dis;
	int num;
}node;

struct cmp
{
	bool operator()(node a,node b)
	{
		return a.dis>b.dis;
	}
};

int n,m,w,b,S,T;
int dis[10010][10010],color[10010],vis[10010][10010];
vector<int>head[10010];
map<int,long long>low[10010];
priority_queue<node,vector<node>,cmp>q;

void dij()
{
	cout << "/";
	memset(vis,0,sizeof(vis));
	if(color[S]==1) low[S][1]=0; else low[S][-1]=0;
	node tmp;
	tmp.x=S;
	tmp.dis=0;
	if(color[S]==1) tmp.num=1; else tmp.num=-1;
	q.push(tmp);
	int nt,ndis,nnum;
	cout << "/"; 
	while(!q.empty())
	{
		nt=q.top().x;
		ndis=q.top().dis;
		nnum=q.top().num;
		cout << nt << " " << ndis << " " << nnum << endl;
		q.pop();
		vis[nt][nnum]=1;
		int ndp=low[nt][nnum];
		for(int i=0;i<head[nt].size();++i)
		{
			if(color[head[nt][i]]==1) nnum++; else nnum--;
			
			if(vis[head[nt][i]][nnum]) continue;
			?
			if(!low[head[nt][i]][nnum] || (ndp+dis[nt][head[nt][i]]<low[head[nt][i]][nnum]))
			{
				low[head[nt][i]][nnum]=ndp+dis[nt][head[nt][i]];
				tmp.num=nnum;
				tmp.x=head[nt][i];
				tmp.dis=low[head[nt][i]][nnum];
				q.push(tmp);
			}
		}
	}
	return;
}

int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	cin >> n >> m >> w >> b;
	for(int i=1;i<=n;++i) cin >> color[i];
	int u,v,d;
	memset(dis,0,sizeof(dis));
	for(int i=1;i<=m;++i)
	{
		cin >> u >> v >> d;
		head[u].push_back(v);
		head[v].push_back(u);
		dis[u][v]=dis[v][u]=d;
	}
	cin >> S >> T;
	dij();
	long long ans=9999999977;
	for(int i=-b;i<=w;++i)
	{
		if(low[T][i] && low[T][i]<ans) ans=low[T][i];
	}
	if(ans==9999999977) cout << "-1\n"; else cout << ans << endl;
	return 0;
}
