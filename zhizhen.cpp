#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void s(int* a,int* b)
{
	swap(*a,*b);
	return;
}

void sort(int a[]) //用int *a也可以 
{
	swap(a[1],a[2]);
}

void add(int& a)
{
	a++;
}

int main()
{
	int i,j;
	i=1;
	j=2;
	int *ii=&i;
	int *jj=&j;
	s(&i,&j); 
	cout << i << " " << j << endl;
	int p[3];
	p[1]=1;
	p[2]=2;
	sort(p);
	cout << p[1] << p[2] << endl;
	int q=1;
	add(q);
	cout << q << endl;
	return 0;
} 
