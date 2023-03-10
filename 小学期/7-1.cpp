#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct cmp
{
	bool operator()(int a,int b)
	{
		return a>b;
	}
};

int n,s;
priority_queue<int,vector<int>,cmp>head[1000010];
int vis[1000010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	int x,y,flag=1;
	for(int i=1;i<n;++i)
	{
		cin >> x >> y;
		head[x].push(y);
		head[y].push(x);
	}	
	memset(vis,0,sizeof(vis));
	while(flag)
	{
		//cout << s << endl;
		vis[s]=1;
		while(!head[s].empty() && vis[head[s].top()])
		{
			head[s].pop();
		}
		if(head[s].empty()) flag=0; 
		else
		{
			s=head[s].top();
			//head[s].pop();
		}
	}
	cout << s << endl;
	return 0;
}
