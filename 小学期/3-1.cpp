#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[100100],ans[100100];
int n;

int main()
{
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i];
	int tmp;
	int t,w,m;
	for(int i=1;i<=n;++i)
	{
		cin >> tmp;
		t=1;
		w=n;
		while(t<=w)
		{
			m=(t+w)/2;
			if(a[m]==tmp) break;
			else if(a[m]<tmp) w=m-1;
			else t=m+1;
		}
		ans[i]=m;
	}
	for(int i=1;i<=n;++i) cout << ans[i] << " ";
	cout << endl;
	return 0;
}
