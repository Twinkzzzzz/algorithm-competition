#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int map[100][100];
int t[100],vis[100];
int n,e,flag;

int main()
{
	memset(map,0x3f,sizeof(map));
	memset(vis,0,sizeof(vis));
	cin >> n >> e;
	int p,q,l;
	for(int i=1;i<=e;++i)
	{
		cin >> p >> q >> l;
		map[p][q]=map[q][p]=l;
	}
	for(int i=1;i<=n;++i) t[i]=map[1][i];
	t[1]=0;
	vis[1]=1;
	flag=1;
	int minn,tmp;
	while(flag)
	{
		minn=99999999;
		flag=0;
		for(int i=2;i<=n;++i)
		{
			if (!vis[i] && t[i]<minn)
			{
				flag=1;
				tmp=i;
				minn=t[i];
			}
			vis[tmp]=1;
			{
				for(int j=1;j<=n;++j)
				{
					if (map[tmp][j]+t[tmp]<t[j]) t[j]=map[tmp][j]+t[tmp];
				}
			}
		}
	}
	for(int i=1;i<=n;++i) cout << t[i] << " ";
	cout << endl;
	return 0; 
}
