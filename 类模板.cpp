#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

template <class T> class mst
{
	private:
		int size;
		T mem[1001];
	public:
		mst()
		{
			size=0;
		}
		void push(T newm)
		{
			size++;
			mem[size]=newm;
		}
		void pop()
		{
			size--;
		}
		int showsize()
		{
			return size;
		}
		T gettop()
		{
			return mem[size];
		}
};

template <typename T> T getb(T a,T b)
{
	if (a>b) return a; else return b;
}

int main()
{
	mst<string> q;
	string t;
	for(int i=1;i<=5;++i)
	{
		cin >> t;
		q.push(t);
	}
	string a,b;
	a=q.gettop();
	q.pop();
	q.pop();
	b=q.gettop();
	cout << a << endl << b << endl;
	cout << getb(a,b) << endl;
	return 0;
}
