#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const unsigned long long MOD=1000000007;

unsigned long long str[500010],lazy[500010],str2[500010],a[100010];
unsigned long long n,e;

void pushup(unsigned long long k)
{
	str[k]=((str[k*2]%MOD)+(str[k*2+1]%MOD))%MOD;
	str2[k]=((str2[k*2]%MOD)+(str2[k*2+1]%MOD))%MOD;
	return;
}

void pushdown(unsigned long long k,unsigned long long l,unsigned long long r)
{
	lazy[k*2]+=lazy[k];
	lazy[k*2+1]+=lazy[k];
	lazy[k*2]%=MOD;
	lazy[k*2+1]%=MOD;
	int m=(l+r)/2;
	str2[k*2]+=(((m-l+1)*(lazy[k]*lazy[k])%MOD)%MOD+(2*((lazy[k]%MOD)*(str[k*2]%MOD)%MOD)%MOD)%MOD)%MOD;
	str2[k*2+1]+=(((r-m)*(lazy[k]*lazy[k])%MOD)%MOD+(2*((lazy[k]%MOD)*(str[k*2+1]%MOD)%MOD)%MOD)%MOD)%MOD;
	str[k*2]+=((lazy[k]%MOD)*(m-l+1))%MOD;
	str[k*2+1]+=((lazy[k]%MOD)*(r-m))%MOD;
	lazy[k]=0;
	str2[k*2]%=MOD;
	str2[k*2+1]%=MOD;
	str[k*2]%=MOD;
	str[k*2+1]%=MOD;
	return;
}

void build(unsigned long long k,unsigned long long l,unsigned long long r)
{
	if(l==r)
	{
		str[l]=a[l];
		str2[l]=(a[l]*a[l])%MOD;
	}
	else
	{
		unsigned long long m=(l+r)/2;
		build(k*2,l,m);
		build(k*2+1,m+1,r);
		pushup(k);
	}
	return;
}

void update(unsigned long long k,unsigned long long l,unsigned long long r,unsigned long long L,unsigned long long R,unsigned long long NUM)
{
	if(l>=L && r<=R)
	{
		lazy[k]+=NUM;
		str2[k]+=(((r-l+1)*(NUM*NUM%MOD))%MOD+(2*NUM*(str[k]%MOD))%MOD)%MOD;
		str[k]+=(NUM*(r-l+1))%MOD;
		lazy[k]%=MOD;
		str2[k]%=MOD;
		str[k]%=MOD;
	}
	else
	{
		pushdown(k,l,r);
		unsigned long long m=(l+r)/2;
		if(m>=L) update(k*2,l,m,L,R,NUM);
		if(m<R) update(k*2+1,m+1,r,L,R,NUM);
		pushup(k);
	}
	return;
}

void add(unsigned long long k,unsigned long long l,unsigned long long r,unsigned long long Ks,unsigned long long NUM)
{
	//cout << "add" << k << " " << l << " " << r << " " << Ks << " " << NUM << endl;
	if(l==r)
	{
		str2[k]+=((NUM*NUM)%MOD+(2*(str[k]%MOD)*NUM)%MOD)%MOD;
		str[k]+=NUM;
		str[k]%=MOD;
		str2[k]%=MOD;
	}
	else
	{
		unsigned long long m=(l+r)/2;
		if(Ks<=m) add(k*2,l,m,Ks,NUM); else add(k*2+1,m+1,r,Ks,NUM);
		pushup(k);
	}
	return;
}

unsigned long long query(unsigned long long k,unsigned long long l,unsigned long long r,unsigned long long L,unsigned long long R)
{
	//cout << k << " " << l << " " << r << endl;
	if(l>=L && r<=R)
	{
		return str2[k]%MOD;
	}
	else
	{
		pushdown(k,l,r);
		unsigned long long ans=0;
		unsigned long long m=(l+r)/2;
		if(L<=m) ans+=query(k*2,l,m,L,R);
		ans%=MOD;
		if(R>m) ans+=query(k*2+1,m+1,r,L,R);
		return ans%MOD;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> e;
	memset(str,0,sizeof(str));
	memset(str2,0,sizeof(str2));
	memset(lazy,0,sizeof(lazy));
	for(unsigned long long i=1;i<=n;++i)
	{
		cin >> a[i];
		add(1,1,n,i,a[i]);
	}
	//prunsigned long long(1,1,n);
	unsigned long long tmp,l,r,num;
	for(unsigned long long i=1;i<=e;++i)
	{
		cin >> tmp;
		if(tmp==1)
		{
			cin >> l >> r >> num;
			update(1,1,n,l,r,num);
		}
		else if(tmp==2)
		{
			cin >> l >> r;
			cout << query(1,1,n,l,r) << endl;
		}
	}
	return 0;
}
