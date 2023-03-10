#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

typedef struct node
{
	int x,y;
};

struct cmp1
{
	bool operator()(node a,node b)
	{
		return a.x<b.x;
	}
};

priority_queue<node,vector<node>,cmp1> q;

int main()
{
	int n;
	cin >> n;
	node p;
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;++i)
	{
		cin >> p.x >> p.y;
		q.push(p);
	}
	while(!q.empty())
	{
		cout << q.top().x << q.top().y << endl;
		q.pop();
	}
	return 0;
}
