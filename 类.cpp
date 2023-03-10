#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;

class node
{
	public:
		void print();
		int mult();
		void get();
		node(int p,int q);
	private:
		int a;
		int b;	
};

node::node(int p,int q)
{
	a=p;
	b=q;
}

void node::print()
{
	cout << "a=" << a << " " << "b=" << b << endl;
	return;
}

int node::mult()
{
	return a*b;
}

void node::get()
{
	cin >> a >> b;
}

int main()
{
	node p(2,4);
	cout << p.mult() << endl;
	p.print();
	p.get();
	cout << p.mult() << endl;
	p.print();
	return 0;
} 
