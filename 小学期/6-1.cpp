#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int x[5010],y[5010],z[5010],r[5010];
int fat[5010],flag[5010];

int getf(int n)
{
	if(n==fat[n]) return n; else return fat[n]=getf(fat[n]);
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;++i) fat[i]=i;
	for(int i=1;i<=n;++i)
	{
		cin >> x[i] >> y[i] >> z[i] >> r[i];
		for(int j=1;j<i;++j)
		{
			if((r[i]+r[j])*(r[i]+r[j])>=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]))
			{	
				fat[getf(i)]=getf(j);
			}
		}
	}
	memset(flag,0,sizeof(flag));
	int ans=0,t;
	for(int i=1;i<=n;++i)
	{
		t=getf(i);
		if(!flag[t])
		{
			ans++;
			flag[t]=1;
		}
	}
	cout << ans-1 << endl;
	return 0;
}
