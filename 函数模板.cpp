#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

template<class T> void swapp(T* a,T* b)
{
	T temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return;
}

int main()
{
	string p,q;
	cin >> p >> q;
	swapp(&p,&q);
	cout << p << endl << q << endl;
	return 0; 
}
