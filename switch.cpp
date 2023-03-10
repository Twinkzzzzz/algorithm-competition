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
		case(1):    //注意冒号不能少 
			cout << "a" << endl;
			break;    //最好加上break 
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
