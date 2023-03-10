#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct node
{
	int st,to,len;
}node;

int n,e;
int map[100][100],father[101];
node edge[1001]; 

void qsort(int t,int w)
{
	if (t>=w) return;
	int i=t;
	int j=w;
	int midl=edge[t].len;
	int midst=edge[t].st;
	int midto=edge[t].to;
	while(i<j)
	{
		while(edge[j].len>midl && i<j) j--;
		if (i<j)
		{
			edge[i].st=edge[j].st;
			edge[i].to=edge[j].to;
			edge[i].len=edge[j].len;
			i++;
		}
		while(edge[i].len<midl && i<j) i++;
		if (i<j)
		{
			edge[j].st=edge[i].st;
			edge[j].to=edge[i].to;
			edge[j].len=edge[i].len;
			j--;
		}
	}
	edge[i].len=midl;
	edge[i].to=midto;
	edge[i].st=midst;
	qsort(t,i-1);
	qsort(i+1,w);
	return;
	
}

int getfather(int i)
{
	int p=i;
	while(father[p]!=p) p=father[p];
	father[i]=p;
	return p;
}

void link(int p,int q)
{
	p=getfather(p);
	q=getfather(q);
	if (p!=q) father[p]=q;
	return;
}

int main()
{
	memset(map,0,sizeof(map));
	cin >> n >> e;
	int p,q,l;
	for(int i=1;i<=e;++i)
	{
		cin >> p >> q >> l;
		map[p][q]=map[q][p]=l;
		edge[i].st=p;
		edge[i].to=q;
		edge[i].len=l;
	}
	for(int i=1;i<=n;++i) father[i]=i;
	qsort(1,e);
	int j=1,ans=0;
	for(int i=1;i<n;++i)
	{
		while(getfather(edge[j].st)==getfather(edge[j].to)) j++;
		ans+=edge[j].len;
		link(edge[j].st,edge[j].to);
	}
	cout << ans << endl;
	return 0;
} 
