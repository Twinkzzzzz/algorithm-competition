#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class base
{
	private:
		char* c;
	public:
		base()
		{
			c=new char[2];
			strcpy(c,"0");
		}
		base(const char* str)
		{
			c=new char[strlen(str)+1];
			strcpy(c,str);
		}
		base(const base& b)
		{
			c=new char[strlen(b.c)+1];
			strcpy(c,b.c);
		}
		void operator=(const base& b)
		{
			delete[]c;
			c=new char[strlen(b.c)+1];
			strcpy(c,b.c);
		}
		friend ostream& operator<<(ostream& os,const base& b)
		{
			for(int i=0;i<strlen(b.c);++i) os << b.c[i];
			return os;
		}
		virtual ~base()
		{
			delete [] c;
		}
		virtual void show()
		{
			cout << c;
		}
};

class upper:public base
{
	private:
		char* q;
	public:
		upper():base()
		{
			q=new char[2];
			strcpy(q,"0");
		}
		upper(const char* str1,const char* str2):base(str1)
		{
			q=new char[strlen(str2)+1];
			strcpy(q,str2);
		}
		upper(const upper& up):base(up)
		{
			q=new char[strlen(up.q)+1];
			strcpy(q,up.q);
		}
		void operator=(const upper& up)
		{
			base::operator=(up);
			delete [] q;
			q=new char[strlen(up.q)+1];
			strcpy(q,up.q);
		}
		~upper()
		{
			delete [] q;
		}
		friend ostream& operator<<(ostream& os,const upper& up)
		{
			os << (base&)(up);
			os << endl;
			for(int i=0;i<strlen(up.q);++i) os << up.q[i];
			return os;
		}
		void show()
		{
			base::show();
			cout << q; 
		}
};

int main()
{
	upper a("123","456");
	upper b("abc","def");
	b.show();
	cout << endl;
	base* p=&a;
	*p=b;
	p->show();
	cout << endl;
	a.show();
	return 0;
}
