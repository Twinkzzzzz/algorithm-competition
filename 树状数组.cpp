#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int lowbit(int n)
{
	return n&(-n);
}

int a[1001],tr[1001],n;

int gets(int n)
{
	int p=n;
	int ans=0;
	while(p>0)
	{
		ans+=tr[p];
		p-=lowbit(p);
	}
	return ans;
}

int main()
{
	memset(tr,0,sizeof(tr));
	cin >> n;
	int p;
	for(int i=1;i<=n;++i)
	{
		cin >> a[i];
		p=i;
		while(p<=n)
		{
			tr[p]+=a[i];
			p+=lowbit(p);
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
		{
			cout << i << " " << j << " " << gets(j)-gets(i-1) << endl;
		}
	}
	return 0;
}
