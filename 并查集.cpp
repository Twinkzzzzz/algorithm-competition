#include <iostream>
#include <cstdio> 
#include <cstring>
using namespace std;

int father[1000];
int n,e;

int getfather(int p)
{
	if (p==father[p]) return p;
	else return father[p]=getfather(father[p]);
}

void link(int p,int q)
{
	p=getfather(p);
	q=getfather(q);
	if (p!=q) father[p]=q;
	return;
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;++i) father[i]=i;
	cin >> e;
	int p,q;
	for(int i=1;i<=e;++i)
	{
		cin >> p >> q;
		link(p,q);
	}
	//Вщев
	return 0; 
}
