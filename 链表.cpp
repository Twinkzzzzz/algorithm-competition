#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;

typedef struct node
{
	node* next;
	node* prev;
	int num;
}node;

struct node* head;

void print(node* p)
{
	cout << p->num << " ";
	if (p->next!=NULL) print(p->next);
	else
	{
		cout << endl;
		return;
	} 
}

int main()
{
	head=new node;
	head->prev=NULL;
	head->num=-14444;
	node* p;
	node* q;
	node* r;
	int t,n;
	while(1)
	{
		cin >> t;
		if (t==(-1)) break;
		if (head->num==-14444)
		{
			head->num=t;
			head->next=NULL;
			p=head;
		}
		else
		{
			q=new node;
			p->next=q;
			q->prev=p;
			q->next=NULL;
			q->num=t;
			p=q;
		}
	}
	print(head); 
	p=head;
	//É¾³ý 
	cin >> t;
	while(--t) p=p->next;
	if (p==head)
	{
		head=head->next;
		head->prev=NULL;
	}
	else if (p->next==NULL)
	{
		r=p->prev;
		r->next=NULL; 
		delete p;
	}
	else
	{
		r=p->prev;
		q=p->next;
		r->next=q;
		q->prev=r;
	}
	delete p;
	print(head);
	p=head;
	//²åÈë 
	cin >> t >> n;
	while(--t && p->next!=NULL) p=p->next;
	q=new node;
	q->num=n;
	if (!t)
	{
		if (p==head)
		{

			q->prev=NULL;
			p->prev=q;
			q->next=p;
			head=q;
		}
		else
		{
			r=p->prev;
			r->next=q;
			q->next=p;
			p->prev=q;
			q->prev=r;
		}
	} 
	else
	{
		p->next=q;
		q->prev=p;
		q->next=NULL;
	}
	print(head);
	return 0;
}
