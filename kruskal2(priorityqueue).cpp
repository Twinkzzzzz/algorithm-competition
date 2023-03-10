#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

typedef struct edge
{
	int x;
	int y;
	int dis;
}edge;

struct cmp
{
	bool operator()(const edge& p,const edge& q)
	{
		return p.dis>q.dis;
	}
};

int n,e;
priority_queue<edge,vector<edge>,cmp>q;
int fat[1001];

int getfat(int i)
{
	if(i==fat[i]) return i; else return fat[i]=getfat(fat[i]);
}

void link(int p,int q)
{
	int fp=getfat(p);
	int fq=getfat(q);
	fat[fp]=fq;
	return;
}

int check(int p,int q)
{
	int fp=getfat(p);
	int fq=getfat(q);
	if(fp==fq)
	{
		return 1;
	}
	else
	{
		fat[fp]=fq;
		return 0;
	}
}

int main()
{
	cin >> n >> e;
	int x,y,t;
	edge tmp;
	while(!q.empty()) q.pop();
	for(int i=1;i<=e;++i)
	{
		cin >> x >> y >> t;
		tmp.x=x;
		tmp.y=y;
		tmp.dis=t;
		q.push(tmp);
	}
	/*
	for(int i=1;i<=e;++i)
	{
		tmp=q.top();
		q.pop();
		cout << tmp.x << " " << tmp.y << " " << tmp.dis << endl;
	}
	*/
	for(int i=0;i<=n;++i) fat[i]=i;
	int ans=0;
	int flag;
	for(int i=1;i<n;++i)
	{
		tmp=q.top();
		q.pop();
		x=tmp.x;
		y=tmp.y;
		while(check(x,y) && !q.empty())
		{
			tmp=q.top();
			q.pop();
			x=tmp.x;
			y=tmp.y;
		}
		cout << x << " " << y << endl;
		ans+=tmp.dis;
	}
	cout << ans << endl;
	return 0;
} 
