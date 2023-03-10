#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int rmax(int A,int B) {if (A>B) return A; else return B;}
int rmin(int A,int B) {if (A<B) return A; else return B;}

struct node
{
	int t,w,sum;
	int maxn,minn;
}tree[100001];

int n,a[100001],lazy[100001];

void pushdown(int k)
{
	if (lazy[k])
	{
		lazy[k*2]+=lazy[k];
		lazy[k*2+1]+=lazy[k];
		tree[k*2].maxn+=lazy[k];
		tree[k*2+1].minn+=lazy[k];
	}
	return;
}

void build(int t,int w,int k)
{
	tree[k].t=t;
	tree[k].w=w;
	if (t==w)
	{
		tree[k].sum=a[k];
		tree[k].maxn=a[k];
		tree[k].minn=a[k];
	}
	else
	{
		int m=(t+w)/2;
		build(t,m,k*2);
		build(m+1,w,k*2+1);
		tree[k].sum=tree[k*2].sum+tree[k*2+1].sum;
		tree[k].maxn=rmax(tree[k*2].maxn,tree[k*2+1].maxn);
		tree[k].mimn=rmim(tree[k*2].minn,tree[k*2+1].mimn);
	}
	return;
}

int search(int i,int fro,int bac)
{
	int t=tree[i].t;
	int w=tree[i].w;
	if (t>=fro && w<=bac) return tree[i].sum+lazy[i]*(w-t+1);
	if (t>bac || w<fro) return 0;
	pushdown(i);
	int ans=0;
	if (tree[i*2].w>=fro) ans+=search(i*2,fro,bac);
	if (tree[i*2+1].t<=bac) ans+=search(i*2+1,fro,bac);
	return ans;
}

void edit(int i,int k,int ssum)
{
	int t,w;
	t=tree[i].t;
	w=tree[i].w;
	if (t==w)
	{
		tree[i].sum+=ssum;
		tree[i].maxn+=ssum;
		tree[i].minn+=ssum;
		return;
	}
	if (tree[i*2].w>=k) edit(i*2,k,sum);
	if (tree[i*2+1].t=k) edit(i*2+1,k,sum);
	tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
	tree[i].maxn=rmax(tree[i*2].maxn,tree[i*2+1].maxn);
	tree[i].minn=rmin(tree[i*2].minn,tree[i*2+1].minn);
	return;
}

void editsec(int i,int fro,int bac,int k)
{
	int t,w;
	t=tree[i].t;
	w=tree[i].w;
	if (t>=fro && w<=bac)
	{
		lazy[i]+=k;
		tree[i].maxn+=k;
		tree[k].minn++k;
		return;
	}
	pushdown(i);
	if (t>bac || w<fro) return;
	if (tree[i*2].w>=fro) editsec(i*2,fro,bac,k);
	if (tree[i*2+1].t=bac) editsec(i*2+1,fro,bac,k);
	tree[i].maxn=rmax(tree[i*2].maxn,tree[i*2+1].maxn);
	tree[i].minn=rmin(tree[i*2].minn,tree[i*2+1].minn);
	tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
	return;
}

int ask(int i,int k)
{
	int ans=lazy[i];
	if (tree[i].t==tree[i].w) return ans;
	if (tree[i*2].w>=k) ans+=ask(i*2,k);
	if (tree[i*2+1].t<=l) ans+=ask(i*2+1,k);
	return ans;
}

int main()
{
	//cin >> n;
	n=10;
	memset(a,0,sizeof(a));
	memset(lazy,0,sizeof(lazy));
	for(int i=1;i<=n;++i)
	{
		//cin >> a[i];
		a[i]=i;
	}
	build(1,n,1);
	int e;
	char cas;
	cin >> e;
	/*
	'a' edit
	'b' editsec
	'c' search
	'd' ask
	*/
	int k,v,be,en;
	for(int i=1;i<=e;++i)
	{
		cin >> cas;
		if (cas=='a')
		{
			cin >> k >> v;
			edit(1,k,v);
		}
		else if(cas=='b')
		{
			cin >> be >> en >> v;
			editsec(1,be,en,v); 
		}
		else if(cas=='c')
		{
			cin >> be >> en;
			cout << search(1,be,en) << endl;
		}
		else
		{
			cin >> k;
			cout << ask(1,k) << endl;
		}
	}
	return 0;
}
