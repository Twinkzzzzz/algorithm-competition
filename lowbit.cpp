#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int t[100001],n;

int lowbit(int q)
{
	return q&(-q);
}

void add(int p,int sum)
{
	while(p<=n)
	{
		t[p]+=sum;
		p+=lowbit(p);
	}
	return;
}

int Ask(int p)
{
	int sum=0;
	while(p>0)
	{
		sum+=t[p];
		p-=lowbit(p);
	}
	return sum;
}

int ask(int to,int we)
{
	return Ask(we)-Ask(to-1);
}

int main()
{
	cin >> n;
	memset(t,0,sizeof(t));
	int tmp,to,we;
	for(int i=1;i<=n;++i)
	{
		cin >> tmp;
		add(i,tmp);
	}
	cin >> to >> we;
	cout << ask(to,we) << endl;
	return 0;
}
