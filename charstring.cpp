#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char a[20],c,q;
string p;

int main()
{
	//c=cin.get();               //cin.get()���տո��\n
	//q=cin.get();
	//cout << c << "/" << q << endl;
	
	
	q=cin.get();
	cin.get(a,5);               //cin.get()�����ַ�����ʱ,һ������\n����������Ҳ�����\n����������������У� 
	c=cin.get();
	cout << q << "/" << a << "/" << c;
	
	
	/*
	getline(cin,p);               //getline����stringʱ��\nҲ��ȡ�� �����ֱȽϺ��� 
	cin >> c;
	cout << p << endl << c;
	*/
	
	/*
	q=cin.get();
	cin.getline(a,5);               //�������Ҫע��,�ұ����־������ڿ�������ĳ���,���ȳ���ʱ����\n����������� 
	cin.getline(c,2);
	cout << a << '/' << c << '/' << q << endl;
	*/
	
	return 0;
} 
