#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long n,m;
typedef struct node
{
	long long l,r;
}node;
node p[200010];

bool cmp(node a,node b)
{
	return a.l<b.l;
}

long long getmax(long long a,long long b)
{
	if(a>b) return a; else return b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=0;i<m;++i) cin >> p[i].l >> p[i].r;
	sort(p,p+m,cmp);
	long long lst=0,ans=0,maxn;
	maxn=0;
	//for(int i=0;i<m;++i) cout << p[i].l << " " << p[i].r << endl;
	for(int i=0;i<m;++i)
	{
		if(lst>=n) break;
		if(p[i].l<=lst+1) maxn=getmax(maxn,p[i].r);
		else
		{
			ans++;
			lst=maxn;
			maxn=getmax(maxn,p[i].r);
		}
	}
	if(lst<n) ans++;
	cout << ans << endl;
	return 0;
}
