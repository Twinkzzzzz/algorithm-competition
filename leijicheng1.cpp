#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

class base
{
	private:
		int num1;
	public:
		base(int n1=0)
		{
			num1=n1;
		}
		base(const base& bs)
		{
			num1=bs.num1;
		}
		friend istream& operator>>(istream& is,base& bs)
		{
			is >> bs.num1;
			return is;
		}
		friend ostream& operator<<(ostream& os,const base& bs)
		{
			os << bs.num1;
			return os;
		}
};

class upper:public base
{
	private:
		string num2;
		
	public:
		static int tot;
		upper(int n1=0,string n2="0"):base(n1)
		{
			num2=n2;
			tot++;
		}
		upper(const upper& up):base(up)
		{
			num2=up.num2;
			tot++;
		}
		upper(const base& bs):base(bs)
		{
			num2="00";
			tot++;
		}
		friend istream& operator>>(istream& is,upper& up)
		{
			is >> (base&)(up);
			is >> up.num2;
			return is;
		} 
		friend ostream& operator<<(ostream& os,const upper& up)
		{
			os << (base&)(up);
			os << " " << up.num2;
			return os;
		}
		static int gettot()
		{
			return tot;
		}
};

int upper::tot=0;

int main()
{
	cout << upper::gettot() << endl;
	cout << upper::tot << endl;
	upper a(1,"abc");
	base c(3);
	upper b(c);
	cout << b << endl;
	cout << a << endl;
	cin >> b;
	cout << b << endl;
	cout << upper::gettot() << endl;
	return 0;
}
