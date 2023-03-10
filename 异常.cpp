#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void act(int p)
{
	if (p==0) throw "asdf";
	if (p==1) throw 1;
	if (p==2) throw 2.3;
	return;
}

int main()
{
	int n;
	cin >> n; 
	try
	{
		act(n);
	}
	catch(const char* msg)
	{
		cout << msg << endl;
	}
	catch(const int s)
	{
		cout << "s=" << s << endl;
	}
	catch(const double p)
	{
		cout << "p=" << p << endl;
	}
	return 0;
}
