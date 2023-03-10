#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int T;
int L,R;
bool f[10000010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(f,0,sizeof(f));
	for(int i=2;i<=4000;++i)
	{
		if(f[i]) continue;
		for(int j=2;j<=10000000/i;++j) f[i*j]=1;
	}
	cin >> T;
	int ans;
	for(int i=1;i<=T;++i)
	{
		cin >> L >> R;
		ans=0;
		for(int j=L;j<=R;++j) ans+=(1-f[j]);
		cout << ans << endl; 
	}
	return 0;
}
