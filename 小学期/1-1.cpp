#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	long long a,b,p;
	cin >> a >> b >> p;
	a=a%p;
	b=b%p;
	a=a*b;
	a=a%p;
	cout << a << endl;
}
