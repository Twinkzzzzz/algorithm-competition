#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct node
{
	int a;
	int b;
	int c;
}node;

node t[1001];

struct cmp
{
	bool operator()(const node& p,const node& q)
	{
		return(p.a<q.a || (p.a==q.a && p.b<q.b) || (p.a==q.a && p.b==q.b && p.c<q.c));
	}
};

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;++i) cin >> t[i].a >> t[i].b >> t[i].c;
	sort(t,t+n,cmp());
	for(int i=0;i<n;++i)
	{
		cout << t[i].a << " " << t[i].b << " " << t[i].c << endl;
	}
	return 0;
}
