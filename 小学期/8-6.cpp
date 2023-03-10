#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n,t;
	cin >> n >> t;
	int q;
	for(int i=1;i<=t;++i)
	{
		q=n/2;
		n=n^t;
	}
	cout << n << endl;
	return 0;
}
