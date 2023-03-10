#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int a[1000100];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;++i) cin>> a[i];
	int tmp=0;
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		tmp+=a[i];
		if(tmp<0) tmp=0;
		if(tmp>ans) ans=tmp;
	}
	cout << ans << endl;
	return 0;
}
