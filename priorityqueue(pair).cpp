#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;

int main()
{
	while(!q.empty()) q.pop();
	q.push(make_pair(1,2));
	q.push(make_pair(3,4));
	q.push(make_pair(5,5));
	q.push(make_pair(1,6));
	q.push(make_pair(2,7));
	q.push(make_pair(6,2));
	q.push(make_pair(3,3));
	q.push(make_pair(4,5));
	q.push(make_pair(2,3));
	q.push(make_pair(2,5));
	pair<int,int>t;
	while(!q.empty())
	{
		t=q.top();
		cout << t.first << " " << t.second << endl;
		q.pop();
	}
	cout << endl;
	return 0;
}
