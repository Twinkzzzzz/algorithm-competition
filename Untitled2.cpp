#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip> 
using namespace std;

int s(int a,int b)
{
	return a+b;
}

string s(string a,string b)
{
	return a+b;
}

int main()
{
	string p,q;
	p="1";
	q="22";
	cout << s(p,q);
	return 0;
}
