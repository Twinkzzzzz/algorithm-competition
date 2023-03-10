#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int t=1;
	int w=1000000000;
	int m,f;
	while(t<=w)
	{
		m=(t+w)/2;
		cout << m << endl;
		cin >> f;
		if(!f) break;
		else if (f==1) w=m-1;
		else t=m+1;
		fflush(stdout);
	}
	return 0;
}
