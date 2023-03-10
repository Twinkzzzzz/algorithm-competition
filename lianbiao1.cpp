#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct node
{
	int num;
	node* pre;
	node* nex;
}node;

node* head;
int n;

void show(node* head)
{
	node* p=head;
	while(p!=NULL)
	{
		cout << p->num << " ";
		p=p->nex;
	}
	cout << endl;
	//cout << p->num << endl;
	return;
}

void insert(int pos,int t)
{
	node* p=head;
	while(p->num!=pos && p->nex!=NULL) p=p->nex;
	if (p->num!=pos)
	{
		cout << "no\n";
		return;
	}
	node* q=new node;
	q->num=t;
	if (p->nex==NULL)
	{
		p->nex=q;
		q->pre=p;
		q->nex=NULL;
	}
	else
	{
		node* r=p->nex;
		p->nex=q;
		q->nex=r;
		r->pre=q;
		q->pre=p;
	}
	return;
}

void dele(int pos)
{
	node* p=head;
	node* q;
	while(p->nex!=NULL)
	{
		if (p->num!=pos)
		{
			p=p->nex;
			continue;
		}
		if (p==head)
		{
			head=p->nex;
			p=p->nex;
			delete(p->pre);
			p->pre=NULL;
			continue;
		}
		q=p;
		p->pre->nex=p->nex;
		p->nex->pre=p->pre;
		p=p->nex;
		delete q;
	}
	if (p->num==pos)
	{
		p->pre->nex=NULL;
		delete p;
	}
	return;
}

int main()
{
	head=new node;
	head->num=14444;
	head->pre=NULL;
	head->nex=NULL;
	cin >> n;
	int t;
	node* p=head;
	node* q;
	for(int i=1;i<=n;++i)
	{
		cin >> t;
		p->num=t;
		q=new node;
		p->nex=q;
		q->pre=p;
		p=q;
	}
	q=p;
	p=p->pre;
	p->nex=NULL;
	delete q;
	show(head);
	int a,b;
	cin >> a >> b;
	insert(a,b);
	show(head);
	cin >>a;
	dele(a);
	show(head);
	return 0;
}

