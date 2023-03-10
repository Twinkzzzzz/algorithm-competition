#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[100];

int main()
{
	memset(a,0x3f,sizeof(a));
	cout << a[0] << endl;
	memset(a,192,sizeof(a));
	cout << a[0] << endl;
	memset(a,0xff,sizeof(a));
	cout << a[0] << endl;
	return 0;
}
