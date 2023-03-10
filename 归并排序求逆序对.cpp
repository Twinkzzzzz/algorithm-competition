#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int a[10001],b[10001];
int ans;

void gb(int t,int w)
{
	//cout << "// " << t << " " << w << endl;
	if(t==w) return;
	if(w-t==1)
	{
		if(a[t]>a[w])
		{
			ans++;
			swap(a[t],a[w]);
		}
		return;
	}
	int m=(t+w)/2;
	gb(t,m);
	gb(m+1,w);
	int k=t,i=t,j=m+1;
	//cout << t << " " << w << endl;
	//cout << "------\n";
	while(i<=m && j<=w)
	{
		//cout << ": " << i << " " << j << endl;
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			i++;
			k++;
		}
		else
		{
			b[k]=a[j];
			//ans+=(j-m);
			ans+=(m-i+1);
			j++;
			k++;
		}
	}
	for(int p=i;p<=m;p++)
	{
		b[k]=a[p];
		//ans+=(w-m);
		k++;
	}
	for(int p=j;p<=w;p++)
	{
		b[k]=a[p];
		k++;
	}
	for(i=t;i<=w;++i) a[i]=b[i];
	return;
}

int main()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i];
	ans=0;
	gb(1,n);
	//for(int i=1;i<=n;++i) cout << a[i] << " ";
	cout << ans << endl;
	return 0;
}
