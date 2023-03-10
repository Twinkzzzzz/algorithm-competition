#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

class vector
{
	private:
		double z;
		double x;
		double y;
		char* name;
	public:
		vector()
		{
			x=y=z=0;
			name=new char[5];
			strcpy(name,"none");
		}
		vector(const vector& vec)
		{
			x=vec.x;
			y=vec.y;
			z=vec.z;
			name=new char[strlen(vec.name)+1];
			strcpy(name,vec.name);
		}
		vector(const double x1,const double y1,const double z1,const char* nname="none")
		{
			x=x1;
			y=y1;
			z=z1;
			name=new char[strlen(nname)+1];
			strcpy(name,nname);
		}
		~vector()
		{
			delete [] name;
		}
		vector operator=(const vector& vec)
		{
			if (this==&vec) return *this;
			x=vec.x;
			y=vec.y;
			z=vec.z;
			delete [] name;
			name=new char[strlen(vec.name)+1];
			strcpy(name,vec.name);
			return *this;
		}
		double fs()
		{
			return sqrt(x*x+y*x+z*z);
		}
		vector operator*(const double p)
		{
			return vector(x*p,y*p,z*p,name);
		}
		friend vector operator*(const double p,const vector& vec)
		{
			return vector(vec.x*p,vec.y*p,vec.z*p,vec.name);
		}
		double operator*(const vector& vec)
		{
			return x*vec.x+y*vec.y+z*vec.z;
		}
		vector operator+(const vector& vec)
		{
			return vector(x+vec.x,y+vec.y,z+vec.z,name);
		}
		friend istream& operator>>(istream& is,vector& vec)
		{
			is >> vec.x >> vec.y >> vec.z;
			char nname[100];
			cin >> nname;
			delete [] vec.name;
			vec.name=new char[strlen(nname)+1];
			strcpy(vec.name,nname);
			return is;
		}
		friend ostream& operator<<(ostream& os,const vector vec)
		{
			os << vec.name << ":(" << vec.x << "," << vec.y << "," << vec.z << ")";
			return os;
		}
};

int main()
{
	vector v(1,1,1);
	vector tmp;
	cout << v << endl;
	cin >> v;
	cout << v << endl;
	tmp=v;
	cout << 3*tmp << endl;
	cout << tmp*v << endl;
	return 0;
	
}
