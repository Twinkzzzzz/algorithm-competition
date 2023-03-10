#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int map[100][100];
int t[100],vis[100];
int n,e;
queue<int>q;

int main()
{
	memset(map,0x3f,sizeof(map));
	memset(vis,0,sizeof(vis));
	cin >> n >> e;
	int p,r,l;
	for(int i=1;i<=e;++i)
	{
		cin >> p >> r >> l;
		map[p][r]=map[r][p]=l;
	}
	memset(t,0x3f,sizeof(t));//初始化和dijkstra不一样 
	t[1]=0;
	while(!q.empty()) q.pop();
	q.push(1);
	int tmp;
	while(!q.empty())
	{
		tmp=q.front();
		vis[tmp]++;
		if (vis[tmp]>n) break;
		q.pop();
		for(int i=1;i<=n;++i)
		{
			if (i==tmp) continue;
			if (t[tmp]+map[tmp][i]<t[i])
			{
				t[i]=t[tmp]+map[tmp][i];
				q.push(i);
			}
		}
	}
	if (vis[tmp]>n)
	{
		cout << "none\n"; 
	}
	else
	{
		for(int i=1;i<=n;++i) cout << t[i] << " ";
	}
	return 0;
}
