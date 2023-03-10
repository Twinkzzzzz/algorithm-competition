#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;
long long a[200010],b[200010];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1;i<=n;++i) cin >> a[i];
	for(int i=1;i<=m;++i) cin >> b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	//for(int i=1;i<=n;++i) cout << a[i] << " ";
	//cout << endl;
	int j,i=1;
	long long ans=0;
	for(j=1;j<=m;++j)
	{
		while(a[i]<b[j] && i<=n) i++;
		if(i>n) break; 
		else
		{
			ans+=a[i];
			i++;
		}
	} 
	if(j<=m) cout << "GG\n"; else cout << ans << endl;
	return 0;
} 
