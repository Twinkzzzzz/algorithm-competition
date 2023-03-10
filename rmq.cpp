#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[100001];
int t[100001][18];
int mi[20];
int n,q;

int getq(int n)
{
	int ans=1;
	while(mi[ans]<n) ans++;
	return ans-1;
}

int maxn(int A,int B)
{
	if(A>B) return A; else return B; 
}

void getrmq()
{
	for(int j=1;j<=q;++j)
	{
		for(int i=1;i<=n-mi[j]+1;++i)
		{
			t[i][j]=maxn(t[i][j-1],t[i+mi[j-1]][j-1]);
		}
	}
	return;
}

int main()
{
	mi[0]=1;
	for(int i=1;i<=19;++i) mi[i]=mi[i-1]*2;
	cin >> n;
	for(int i=1;i<=n;++i)
	{
		cin >> a[i];
		t[i][0]=a[i]; 
	}
	q=getq(n);
	getrmq();
	int to,we;
	cin >> to >> we;
	int q1=getq(we-to);
	cout << maxn(t[to][q1],t[we-mi[q1]+1][q1]) << endl;
	return 0;
}

