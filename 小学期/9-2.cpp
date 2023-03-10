#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

string n;
map<string,int> mp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	string t;
	int ans=0;
	for(int i=1;i<=n.length();++i)
	{
		for(int j=0;j<n.length()-i+1;++j)
		{
			string t=n.substr(j,i);
			if(!mp[t])
			{
				mp[t]=1;
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
