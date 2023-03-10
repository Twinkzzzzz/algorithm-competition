#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

long long a[2010][2010],mem[2010][2010],ans,tmp;
int dir[8][2]={1,2,2,1,1,-2,2,-1,-1,2,-2,1,-1,-2,-2,-1};
int n,m;

long long getmax(long long a,long long b)
{
	if(a>b) return a; else return b;
}

long long search(int k,int p)
{
	if(mem[k][p]) return mem[k][p];
	int nk,np;
	long long tmp=0;
	for(int i=0;i<8;++i)
	{
		nk=k+dir[i][0];
		np=p+dir[i][1];
		if(nk>=1 && nk<=n && np>=1 && np<=m && a[nk][np]<a[k][p])
		{
			tmp=getmax(tmp,search(nk,np));
		}
	}
	mem[k][p]=tmp+a[k][p];
	return mem[k][p];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin >> a[i][j];
		}
	}
	memset(mem,0,sizeof(mem));
	ans=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(a[i][j]<a[i+dir[0][0]][j+dir[0][1]] || a[i][j]<a[i+dir[1][0]][j+dir[1][1]] || a[i][j]<a[i+dir[2][0]][j+dir[2][1]] || a[i][j]<a[i+dir[3][0]][j+dir[3][1]] || a[i][j]<a[i+dir[4][0]][j+dir[4][1]] || a[i][j]<a[i+dir[5][0]][j+dir[5][1]] || a[i][j]<a[i+dir[6][0]][j+dir[6][1]] || a[i][j]<a[i+dir[7][0]][j+dir[7][1]]) continue;
			ans=getmax(ans,search(i,j));
		}
	}
	/*
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cout << mem[i][j] << " ";
		}
		cout << endl;
	}
	*/
	cout << ans << endl;
	return 0;
}
