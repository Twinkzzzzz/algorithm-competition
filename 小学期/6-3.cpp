#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

typedef struct node
{
	int num;
	int col;
}node;

struct cmp1
{
	bool operator()(node a,node b)
	{
		return (a.num>b.num || (a.num==b.num && a.col>b.col));
	}
};

struct cmp2
{
	bool operator()(node a,node b)
	{
		return (a.col>b.col);
	}
};

int getmax(int a,int b)
{
	if(a>b) return a; else return b;
}

priority_queue<node,vector<node>,cmp1> q;
priority_queue<node,vector<node>,cmp2> ans;
int n;

int main()
{
	cin >> n;
	node tmp,tmp2,tmp3;
	int t,sum=0;
	for(int i=1;i<=n;++i)
	{
		cin >> t;
		tmp.col=i;
		tmp.num=t;
		q.push(tmp);
	}
	while(!q.empty())
	{
		tmp=q.top();
		q.pop();
		if(q.empty())
		{
			ans.push(tmp);
			sum++;
			break;
		}
		else
		{
			tmp2=q.top();
			q.pop();
			while(tmp.num!=tmp2.num && !q.empty())
			{
				ans.push(tmp);
				sum++;
				tmp=tmp2;
				tmp2=q.top();
				q.pop();
			}
			if(tmp.num==tmp2.num)
			{
				tmp3.num=tmp.num*2;
				tmp3.col=getmax(tmp.col,tmp2.col);
				q.push(tmp3);
			}
			else
			{
				ans.push(tmp);
				ans.push(tmp2);
				sum+=2;
				break;
			}
		}
	}
	cout << sum << endl;
	tmp=ans.top();
	ans.pop();
	cout << tmp.num;
	while(!ans.empty())
	{
		tmp=ans.top();
		ans.pop();
		cout << " " << tmp.num;
	}
	cout << endl;
	return 0;
}
