#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int lowbit(int n)
{
	return n&(-n);
}

int a[1001][1001],tr[1001][1001],n,m;

int gets(int p,int q)
{
	int ans=0;
	int pi=p,pj;
	while(pi>0)
	{
		pj=q;
		while(pj>0)
		{
			ans+=tr[pi][pj];
			pj-=lowbit(pj);
		}
		pi-=lowbit(pi);
	} 
	return ans;
}

int main()
{
	cin >> n >> m;
	int pi,pj;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin >> a[i][j];
			pi=i;
			while(pi<=n)
			{
				pj=j;
				while(pj<=m)
				{
					tr[pi][pj]+=a[i][j];
					pj+=lowbit(pj);
				}
				pi+=lowbit(pi);
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cout << lowbit(i) << " " << lowbit(j) << " " << tr[i][j] << endl;
		}
	}
	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << gets(x2,y2)-gets(x1-1,y2)-gets(x2,y1-1)+gets(x1-1,y1-1) << endl;
	return 0;
 } 
