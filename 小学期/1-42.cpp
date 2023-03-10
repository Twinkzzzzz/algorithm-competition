#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[5000020],b[5000020];
int m,n,k;

int main()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	ios::sync_with_stdio(false);
    cin>>m>>n>>k;
    int i,j;
    for(i=1;i<=m;i++) cin >> a[i];
    for(i=1;i<=n;i++) cin >> b[i];
    i=1;
	j=1;
    while(i+j<=k)
    {
        if(a[i]<=b[j])
        {
            while(a[i]<=b[j] && i+j<=k) i++;
        }
        else if(a[i]>b[j])
        {
            while(a[i]>b[j] && i+j<=k) j++;
        }
    }
    if (a[i]<=b[j]) cout << a[i] << endl; else cout << b[j] << endl;
    return 0;
}
