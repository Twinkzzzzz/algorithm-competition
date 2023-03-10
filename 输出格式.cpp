#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	double a[5]={0,1.2345,2.2345,3.236456};
	cout << a[3] << endl;
	cin >> n;
	//for(int i=1;i<=3;++i) cin >> a[i];
	cout.setf(ios::fixed);
	cout << setprecision(n) << setw(6) << a[1];
	cout.width(6);
	cout << a[2];
	cout.precision(n-1);
	cout.width(8);
	cout << a[3] << endl;
	cout.unsetf(ios::fixed);
	cout << a[1];
	return 0;
}
