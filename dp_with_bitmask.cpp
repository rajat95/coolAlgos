/*this is algo when you need to perform dp on very large sets*/


#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
long long dp[(1<<20)+10];
int arr[21][21];
int count_bits(int num)
{
	int ans = 0;
	for(int i = 21;i>=0;i--)
	{
		if(num&(1<<i))
			ans++;
	}
	
	return ans;
}
int main(void)
{
	int i,j,t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		/*memset(dp,0,sizeof(dp));*/
		scanf("%d",&n);
		for(i = 0;i<n;i++)
		{
			for(j= 0;j<n;j++)
			{
				scanf("%d",&arr[i][j]);
			}
		}

		dp[0] = 1;
		for(i = 1;i<(1<<n);i++)
		{
			dp[i] = 0;
			/*the set bits represent subjects already assigned*/
			j = count_bits(i);
			for(k = 0;k<n;k++)
			{
				/*sum of all sequences where the bit being considered wasnt set*/
				if(i&(1<<(k))&&arr[j-1][k] == 1)
				{
					dp[i] = dp[i]+dp[i&~(1<<(k))];
				}
			}
		}
		printf("%lld\n",dp[(1<<n)-1]);
	}
}

