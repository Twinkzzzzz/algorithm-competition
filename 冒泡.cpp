#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int a[10]={1,3,2,4,2,5,3,2,4,2};
	bool f;
	for(int i=8;i>=0;--i)
	{
		f=0;
		for(int j=0;j<=i;++j)
		{
			if (a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				f=1;
			}
		}
		if (!f) break;
	}
	for(int i=0;i<=9;++i) cout << a[i] << " ";
	return 0;
} 
