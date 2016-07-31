//codeforces 459C
//Good problem on changing number basis.
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main(void)
{
	int n,k,d;
	cin>>n>>k>>d;
	int f = 0;
	long long temp = 1;
	for(int i = 1;i<=d;i++)
	{
		temp = temp*k;
		if(temp>=n)
		{
			f = 1;
			break;
			
		}

	}
	if(!f)
	{
		cout<<-1<<endl;
		return 0;
	}
	int arr[1005][1005];
	for( int i =0;i<n;i++)
	{
		int temp = i;
		for(int j = 0;j<d;j++)
		{

			arr[j][i] = temp%k;
			temp = temp/k;
		}
	}
	for( int i =0;i<d;i++)
	{
		for(int j = 0;j<n;j++)
		{
			cout<<arr[i][j]+1<<' ';
		}
		cout<<""<<endl;
	}

}