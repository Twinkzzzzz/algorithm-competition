#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct node
{
	int x,y,num;
}node;

int n,m;
int c[1000010];
int fat[1000010];
node e[2000010];

struct cmp
{
	bool operator()(node a,node b)
	{
		return a.num<b.num;
	}
};

int getf(int k)
{
	if(k==fat[k]) return k; else return fat[k]=getf(fat[k]);
}

void link(int p,int q)
{
	int fp=getf(p);
	int fq=getf(q);
	if(fp!=fq) fat[fp]=fq;
	return;
}

int getmax(int a,int b)
{
	if(a>b) return a; else return b;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	long long ans=0;
	int k=0;
	int a,b,d;
	for(int i=1;i<=n;++i)
	{
		cin >> c[i];
		e[i-1].x=0;
		e[i-1].y=i;
		e[i-1].num=c[i];
	}
	for(int i=0;i<m;++i)
	{
		cin >> a >> b >> d;
		e[n+i].x=a;
		e[n+i].y=b;
		e[n+i].num=d;
	}
	sort(e,e+n+m,cmp());
	int tp,tq;
	for(int i=0;i<=n;++i) fat[i]=i;
	for(int i=0;i<n+m;++i)
	{
		tp=getf(e[i].x);
		tq=getf(e[i].y);
		if(tq!=tp)
		{
			k++;
			ans+=e[i].num;
			link(tp,tq);
			if(k==n) break;
		}
	}
	cout << ans << endl;
	return 0;
}
