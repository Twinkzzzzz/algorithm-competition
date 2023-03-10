#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

unsigned long long m,k;

typedef struct sq
{
	long long a11,a12,a21,a22;
}sq;
sq ori;

sq mult(sq a)
{
	sq ans;
	ans.a11=((a.a11*a.a11)+(a.a12*a.a21))%k;
	ans.a12=((a.a11*a.a12)+(a.a12*a.a22))%k;
	ans.a21=((a.a21*a.a11)+(a.a22*a.a21))%k;
	ans.a22=((a.a21*a.a12)+(a.a22*a.a22))%k;
	//cout << "/\n";
	return ans;
}

sq mult2(sq a)
{
	sq ans;
	ans.a11=(a.a11+a.a12)%k;
	ans.a12=a.a11;
	ans.a21=(a.a21+a.a22)%k;
	ans.a22=a.a21;
	return ans;
}

void print(sq t)
{
	cout << t.a11 << " " << t.a12 << endl << t.a21 << " " << t.a22 << endl;
}

sq mpow(unsigned long long t)
{
	sq ans;
	if (!t)
	{
		ans.a11=1;
		ans.a12=0;
		ans.a21=0;
		ans.a22=1;
	}
	else
	{
		long long m=t/2;
		ans=mult(mpow(m));
		//cout << "t=" << t << endl;
		if(t%2) ans=mult2(ans);
		//print(ans);
	}
	return ans;
}

int main()
{

	cin >> m >> k;
	ori.a11=1;
	ori.a12=1;
	ori.a21=1;
	ori.a22=0;
	//print(mpow(8));
	if(m==1 || m==2)
	{
		cout << 2%k << endl;
		return 0;
	}
	sq tmp=mpow(m-2);
	cout << (((tmp.a11+tmp.a12)%k)*2)%k << endl;
	return 0;
} 
