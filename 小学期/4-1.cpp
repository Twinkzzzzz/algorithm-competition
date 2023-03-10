#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int ss[40000100];
int n;
int a[30];
map<int,int>q;

int main()
{
	memset(ss,0,sizeof(ss));
	ss[1]=1;
	ss[0]=1;
	for(int i=2;i<=7000;++i)
	{
		if(!ss[i])
		{
			for(int j=2;j<=40000000/i;++j) ss[i*j]=1;
		}
	}
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i];
	int tmp=0;
	int ans1=0,ans2=0;
	for(int i=1;i<(1<<n);++i)
	{
		tmp=0;
		for(int j=1;j<=n;++j)
		{
			//cout << ((1<<(j-1)) & i);
			if((1<<(j-1)) & i) tmp+=a[j];
		}
		//cout << endl;
		if(!ss[tmp])
		{
			ans1++;
			if(!q[tmp])
			{
				ans2++;
				q[tmp]=1;
			}
		}
	}
	cout << ans1 << endl << ans2 << endl;
	return 0;
}
