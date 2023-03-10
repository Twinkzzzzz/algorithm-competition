#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[500010];
int n;
int len[500010],ans,mem[500010];

void search(int num,int xb)
{
	int t=1,m;
	int w=ans;
	while(t<=w)
	{
		m=(t+w)/2;
		if(len[m]>num)
		{
			w=m-1;
		}
		else
		{
			t=m+1;
		}
	}
	if(t>ans) ans=t;
	len[t]=num;
	mem[xb]=t;
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;++i) cin>> a[i];
	ans=1;
	len[1]=a[1];
	mem[1]=1;
	for(int i=2;i<=n;++i)
	{
		search(a[i],i);
	}
	cout << ans << endl;
	int tmp[500010];
	int k=0;
	for(int i=n;i>=1;--i)
	{
		if(mem[i]==ans)
		{
			k++;
			tmp[k]=i;
			ans--;
			if(!ans) break;
		}
	}
	for(int i=k;i>1;--i) cout << tmp[i] << " ";
	cout << tmp[1] << endl;
	return 0;
}
