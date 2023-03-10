#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int a[2010][2010],vis[2010][2010],mem[2010][2010][2];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int n,m,stx,sty;
string ans;

void search(int x,int y,int x1,int y1)
{
	if(ans=="Yes") return;
	vis[x][y]=1;
	mem[x][y][0]=x1;
	mem[x][y][1]=y1;
	int tx,ty;
	for(int i=0;i<=3;++i)
	{
		tx=x+dir[i][0];
		ty=y+dir[i][1];
		if(tx<1) tx+=n;
		if(tx>n) tx-=n;
		if(ty<1) ty+=m;
		if(ty>m) ty-=m;
		if(!a[tx][ty])
		{
			if(vis[tx][ty] && !(x1+dir[i][0]==mem[tx][ty][0] && y1+dir[i][1]==mem[tx][ty][1]))
			{
				ans="Yes";
				return;
			}
			else if(!vis[tx][ty]) search(tx,ty,x1+dir[i][0],y1+dir[i][1]);
		}
		if(ans=="Yes") return;
	}
	//vis[x][y]=0;
	//mem[x][y][0]=0;
	//mem[x][y][1]=0;
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(mem,0,sizeof(mem));
	cin >> n >> m;
	char c;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin.get(c);
			while(!(c=='#' || c=='.' || c=='S')) cin.get(c);
			if(c=='#') a[i][j]=1; else a[i][j]=0;
			if(c=='S')
			{
				stx=i;
				sty=j;
			}
		}
	}
	/*
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j) cout << a[i][j] << " ";
		cout << endl;
	}
	*/ 
	ans="No";
	memset(vis,0,sizeof(vis));
	search(stx,sty,stx,sty);
	cout << ans << endl;
	return 0;
} 
