#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int MOD=998244353;

long long ans[1000010];
int d[1000010],d1[1000010];
int sq[1000010];
vector<int>head[1000010];
queue<int>q;
int n,m;

int main()
{
	cin >> n >> m;
	int x,y;
	memset(d,0,sizeof(d));
	memset(d1,0,sizeof(d1));
	for(int i=1;i<=m;++i)
	{
		cin >> x >> y;
		d[y]++;
		d1[y]++;
		head[x].push_back(y);
	}
	for(int i=1;i<=m;++i) if(!d[i]) q.push(i);
	int k=0,t,t1;
	while(!q.empty())
	{
		k++;
		t=q.front();
		q.pop();
		sq[k]=t;
		for(int i=0;i<head[t].size();++i)
		{
			t1=head[t][i];
			d[t1]--;
			if(!d[t1]) q.push(t1);
		}
	}
	long long sum=0;
	for(int i=1;i<=n;++i)
	{
		if(!d1[i]) ans[i]=1;
		if(!head[i].size())
		{
			sum=(sum+ans[i])%MOD;
		}
		else
		{
			for(int j=0;j<head[i].size();++j)
			{
				t=head[i][j];
				ans[t]=(ans[t]+ans[i])%MOD;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
