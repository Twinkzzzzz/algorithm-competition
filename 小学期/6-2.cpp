#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct cmp
{
	bool operator()(int a,int b)
	{
		return a>b;
	}
};

int n;
int a[1000010];
priority_queue<int,vector<int>,cmp>q;
long long ans;

int main()
{
	cin.sync_with_stdio(false); 
    cin.tie(0);
	int t=0;
	cin >> n;
	ans=0;
	for(int i=1;i<=n;++i) cin >> a[i];
	for(int i=n;i>=1;--i)
	{
		while(!q.empty() && q.top()<=a[i])
		{
			q.pop();
			t--;
		}
		ans+=t;
		q.push(a[i]);
		t++;
	}
	cout << ans << endl;
	return 0;
}
