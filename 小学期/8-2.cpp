#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

long long X,Y;
bool f[1000010];
long long s[110],hih[110],p[110];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> X >> Y;
	memset(f,0,sizeof(f));
	f[0]=f[1]=1;
	for(long long i=2;i<=1000;++i)
	{
		if(f[i]) continue;
		for(long long j=2;j<=1000000/i;++j) f[i*j]=1;
	}
	long long tmp=1;
	long long k=0;
	memset(hih,0,sizeof(hih));
	for(unsigned long long i=2;i<=1000000;++i)
	{
		if(X==1 && Y==1) break;
		if(f[i]) continue;
		if((!(X%i))||(!(Y%i)))
		{
			//cout << "i=" << i << endl;
			k++;
			s[k]=i;
			hih[k]=0;
			while(!(Y%i) && Y>1)
			{
				hih[k]++;
				Y/=i;
			}
			while(!(X%i) && X>1)
			{
				hih[k]--;
				tmp*=i;
				X/=i;
			}
			//cout << i << " " << k << " " << hih[k] << " " << X << " " << Y << endl;
			if(hih[k]<0)
			{
				cout << 0 << endl;
				return 0;
			}
			else if(!hih[k]) k--;
		}
	}
	if(X>1 || Y>1)
	{
		if(X==Y) tmp*=X;
		else if(X==1)
		{
			k++;
			s[k]=Y;
			hih[k]=1;
		}
		else
		{
			cout << 0 << endl;
			return 0;
		}
	}
	//for(int i=1;i<=k;++i) cout << s[i] << " " << low[i] << " " << hih[i] << endl;
	memset(p,0,sizeof(p));
	long long tmp1,tmp2;
	long long i;
	cout << pow(2,k) << endl;
	while(!p[0])
	{
		tmp1=1;
		tmp2=1;
		for(i=1;i<=k;++i)
		{
			if(p[i]) tmp2*=pow(s[i],hih[i]); else tmp1*=pow(s[i],hih[i]);
		}
		cout << tmp1*tmp << " " << tmp2*tmp << endl;
		i=k;
		while(p[i])
		{
			p[i]=0;
			i--;
		}
		p[i]=1;
	}
	return 0;
}
