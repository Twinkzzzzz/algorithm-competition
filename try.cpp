#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[11];

int main()
{
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=10;++i) cout << a[i] << " ";
	cout << endl;
	memset(a,-1,sizeof(a));
	for(int i=1;i<=10;++i) cout << a[i] << " ";
	cout << endl;
	return 0;
} 
