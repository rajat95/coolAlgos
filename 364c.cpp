/* nice problem on double pointer 
http://codeforces.com/contest/701/problem/C */
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <climits>
#include <map>
using namespace std;
int main(void)
{
	map<char,int>m;
	int i,j,n,cnt = 0,temp,ans = INT_MAX;
	string s;
	cin>>n>>s;
	for(i = 0;i<s.size();i++)
	{
		if(m.find(s[i]) == m.end())
		{
			cnt++;
		}
		m[s[i]] = -1;
	}
	for(i = 0;i<n;i++)
	{
		temp = INT_MAX;
		m[s[i]] = i;
		for (std::map<char,int>::iterator it=m.begin(); it!=m.end(); ++it)
		{
			temp = (temp<(it->second))?temp:it->second;
		}
		if(temp!=-1)
			ans = (ans<(i-temp+1))?ans:(i-temp+1);
	}
	cout<<ans<<endl;
	return 0;
}