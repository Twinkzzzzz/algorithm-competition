#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

typedef struct student
{
	string name;
	string clas;
	string num;
	double score1;
	double score2;
	double score3;
	double totscore;
	student* prev;
	student* next;
}student;

student* head,* tail;
int tot;

void mswap(student* p,student* q)
{
	swap(p->score1,q->score1);
	swap(p->score2,q->score2);
	swap(p->score3,q->score3);
	swap(p->name,q->name);
	swap(p->clas,q->clas);
	swap(p->num,q->num);
	swap(p->totscore,q->totscore);
	return;
}

void mout(student p)
{
	cout << p.num << "," << p.clas << "," << p.name << "," << p.score1 << "," << p.score2 << "," << p.score3 << "," << p.totscore << endl;
	return;
}

void print()
{
	student* p=head;
	while(p->next!=NULL)
	{
		mout(*p);
		p=p->next; 
	}
	mout(*p);
	return;
}

void sort()
{
	int f=0;
	student* p;
	for(int i=1;i<tot;++i)
	{
		p=head;
		for(int j=1;j<=tot-i;++j)
		{
			if (p->clas>p->next->clas || (p->clas==p->next->clas && p->totscore<p->next->totscore))
			{
				mswap(p,p->next);
				f=1;
			}
			p=p->next;
		}
		if (!f) break;
	}
	return;
}

void insert(student t)
{
	if (head->totscore==-1)
	{
		head->clas=t.clas;
		head->num=t.num;
		head->name=t.name;
		head->score1=t.score1;
		head->score2=t.score2;
		head->score3=t.score3;
		head->totscore=t.totscore;
		return;
	}
	student* p;
	p=new student;
	p->clas=t.clas;
	p->num=t.num;
	p->name=t.name;
	p->score1=t.score1;
	p->score2=t.score2;
	p->score3=t.score3;
	p->totscore=t.totscore;
	tail->next=p;
	p->next=NULL;
	p->prev=tail;
	tail=p;
	return;
}

void del(student* t)
{
	if (t->prev==NULL)
	{
		head=t->next;
		head->prev=NULL; 
	}
	else if(t->next==NULL)
	{
		tail=t->prev;
		tail->next=NULL;
	}
	else
	{
		t->prev->next=t->next;
		t->next->prev=t->prev;
	}
	delete t;
	tot--;
	return;
}

void input()
{
	string ans="yes",tmp;
	student t;
	while(ans=="yes")
	{
		cout << "Id ";
		cin >> t.num;
		cout << "class ";
		cin >> t.clas;
		cout << "name ";
		cin >> t.name;
		cout << "score1 ";
		cin >> t.score1;
		cout << "score2 ";
		cin >> t.score2;
		cout << "score3 ";
		cin >> t.score3;
		t.totscore=t.score1+t.score2+t.score3;
		insert(t);
		tot++;
		cout << "continue?\n";
		cin >> ans; 
	}
	//cout << "tot=" << tot << endl;
	//print();
	return;
}

void dis()
{
	string ans="yes";
	string t;
	while(ans=="yes")
	{
		cin >> t;
		student* p=head;
		while(p->name!=t && p->num!=t && p->next!=NULL) p=p->next;
		if ((p->name==t || p->num==t) && tot>1) del(p);
		print();
		cout << "continue?\n";
		cin >> ans;
	}
	return;
}

void search()
{
	string t,ans="yes";
	int f=1;
	while(ans=="yes" && f)
	{
		cin >> t;
		student* p=head;
		f=0;
		while(p->next!=NULL)
		{
			if (p->num==t || p->clas==t)
			{
				mout(*p);
				f=1;
			}
			p=p->next; 
		}
		if (p->num==t || p->clas==t)
		{
			mout(*p);
			f=1;
		}
		if (!f) cout << "there is no eligible student\n";
		else
		{
			cout << "continue?\n";
			cin >> ans;
		}
	}
	return;
}

int main()
{
	cout.setf(ios::fixed);
	cout.precision(1);
	head=new student;
	head->totscore=-1;
	head->prev=NULL;
	head->next=NULL;
	tail=head;
	int c;
	cout << "1.input\n2.delete\n3.select\n4.order\n5.output\n6.quit\nplease input your option\n";
	cin >> c;
	while(c!=6)
	{
		if (c==1) input();
		else if(c==2) dis();
		else if(c==3) search();
		else if(c==4)
		{
			sort();
			print();
		}
		else if(c==5) print();
		cout << "1.input\n2.delete\n3.select\n4.order\n5.output\n6.quit\nplease input your option\n";
		cin >> c;
	}
	return 0;
}
