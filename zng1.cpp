#include <bits/stdc++.h>
using namespace std;
const long long inf=1e9+7;

#include <bits/stdc++.h> 
using namespace std;


long long Maxcd(long long x,long long y)  
{
	if(x%y==0)	return y;
	return Maxcd(y,x%y);
}

long long Mincm(long long x,long long y)  
{
	return ((x%inf)*(y%inf)/Maxcd(x,y));
}

int main()
{
	int t;
	cin>>t;
	long long result;
	for(int i=0;i<t;i++)
	{
		int n;
		long long s;
		cin>>n;
		cin>>s;
		result=s;
		for(int j=0;j<n-1;j++)
		{
			cin>>s;
			result=Mincm(result,s)%inf;
			if(result==0)
				break;
		}
		cout<<result<<endl;
	}
	return 0;
}
