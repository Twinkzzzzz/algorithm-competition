#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n,q;
int c[100010];
vector<int>head[100010];
int sq[100010],vis[100010];
long long ans;

void dfs(int s,int k,long long tans,int bos)
{
	vis[s]=1;
	sq[k]=s;
	int tmp;
	int flag=0;
	for(int i=0;i<head[s].size();++i)
	{
		tmp=head[s][i];
		if(!vis[tmp])
		{
			flag=1;
			if(bos && c[tmp]<c[s])
			{
				tans+=c[s];
				bos=0;
			}
			else if(!bos && c[tmp]>c[s])
			{
				tans-=c[s];
				bos=1;
			}
			dfs(tmp,k+1,tans,bos);
		}
	}
	if(!flag)
	{
		if(bos) tans+=c[s];
		if(tans>ans) ans=tans;
	}
	vis[s]=0;
	sq[k]=0;
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;++i)
	{
		cin >> c[i];
	}
	int x,y;
	for(int i=1;i<n;++i)
	{
		cin >> x >> y;
		head[x].push_back(y);
		head[y].push_back(x);
	}
	int t;
	sq[0]=0;
	c[0]=0;
	for(int i=1;i<=q;++i)
	{
		cin >> t;
		memset(vis,0,sizeof(vis));
		ans=-1999999999;
		dfs(t,1,0,0);
		cout << ans << endl;
	}
	return 0;
}
