#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char a[20],c,q;
string p;

int main()
{
	//c=cin.get();               //cin.get()接收空格和\n
	//q=cin.get();
	//cout << c << "/" << q << endl;
	
	
	q=cin.get();
	cin.get(a,5);               //cin.get()输入字符数组时,一旦遇到\n便结束，并且不接收\n（保留在输入队列中） 
	c=cin.get();
	cout << q << "/" << a << "/" << c;
	
	
	/*
	getline(cin,p);               //getline输入string时把\n也读取了 ，这种比较好用 
	cin >> c;
	cout << p << endl << c;
	*/
	
	/*
	q=cin.get();
	cin.getline(a,5);               //这种情况要注意,右边数字尽量大于可能输入的长度,长度超出时保留\n在输入队列中 
	cin.getline(c,2);
	cout << a << '/' << c << '/' << q << endl;
	*/
	
	return 0;
} 
