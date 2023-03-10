#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int a[10000];

int getsum(int l,int r)
{
	int sum=0;
	for(int i=l;i<=r;++i)
	{
		sum+=a[i]*a[i];
	}
	return sum;
}

int main()
{
	int n,e;
	cin >> n >> e;
	for(int i=1;i<=n;++i) cin >> a[i];
	int l,r,v,tmp;
	for(int i=1;i<=e;++i)
	{
		cin >> tmp;
		if(tmp==1)
		{
			cin >> l >> r >> v;
			for(int j=l;j<=r;++j) a[j]+=v;
		}
		else if(tmp==2)
		{
			cin >> l >> r;
			cout << getsum(l,r) << endl;
		}
	}
	return 0;
}
 
