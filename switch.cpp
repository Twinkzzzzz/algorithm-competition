#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n;
	cin >> n;
	switch(n)
	{
		case(1):    //ע��ð�Ų����� 
			cout << "a" << endl;
			break;    //��ü���break 
		case(2):
			cout << "b" << endl;
			cout << "w\n";
			break;
		default:
			cout << "c\n";
			cout << "q\n";
			break; 
	 } 
	 return 0;
} 
