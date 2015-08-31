/*author rajat*/
/*heirholzer algorithm*/
/*pre condition: graph has euler circuit or path*/
/*output: one of many possible eulerian trails*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> graph[10];
void heirholzer()
{
	int temp,temp2;
	stack<int>path1;
	stack<int>path2;
	path1.push(0);
	while(!path1.empty())
	{
		temp = path1.top();
		if(!graph[temp].empty()){
			temp2 = graph[temp].back();
			path1.push(temp2);
			graph[temp].pop_back();
			/* erase remove idiom 'https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom' for more details*/
			graph[temp2].erase(std::remove(graph[temp2].begin(), graph[temp2].end(), temp), graph[temp2].end());
		}
		else{
			path2.push(temp);
			path1.pop();
				
		}
	
	}
	while(!path2.empty())
	{
		cout<<path2.top()<<"->";
		path2.pop();
	}
}
int main(void)
{
	
	int n,a,b;
	cin>>n; /*no of edges*/
	for(int i = 0;i<n;i++)
	{
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	heirholzer();
	
}



