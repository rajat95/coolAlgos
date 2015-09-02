/*author:rajat*/
/*concept:happy numbers*/
/*refer spoj ques acpc10b for prolem statement*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>
using namespace std;
inline int sqsum(int a)
{
    int ans = 0;

    while(a!=0)
    {
        ans = ans+(a%10)*(a%10);
        a= a/10;
    }
    return ans;
}
int main(void)
{
    unordered_map<int,int>map1;
    unordered_map<int,int>map2;
    int i,j,a,b,temp,cnt1,cnt2,sum,temp2,flag1,flag2,A,B;
    while(1)
    {
    	map1.clear();
    	map2.clear();
    	flag1 = 0;
    	flag2 = 0;
    	sum = -1;
        cnt1 = 1;
        cnt2 = 1;
        scanf("%d %d",&A,&B);
        a = A;
        b = B;
        if(a == 0||b == 0)
            break;
        if(a == b)
        {
            printf("%d %d 2\n",a,b);
            /*cout<<a<<" "<<b<<" 2"<<endl;*/
            continue;
        }
        map1[a] = 1;
        map2[b] = 1;
        while(1)
        {

            temp = a;
            if(flag1<8||a!=1){
            a = sqsum(a);
            if(temp != a)
            {
                cnt1++;
                if(map1.find(a) == map1.end())
                map1[a] = cnt1;

            }
            if(map2.find(a)!=map2.end())
            {
                if(map2[a]+map1[a]<sum||sum<0)
                {
                	
                    sum  = map2[a]+map1[a];
                }
            }}

            temp2 = b;
            if(flag2<8||b!=1){
            b = sqsum(b);
            /*cout<<'b'<<b<<endl;*/
            if(temp2 != b)
            {
                cnt2++;
		if(map2.find(b) == map2.end())
                map2[b] = cnt2;
            }
            if(map1.find(b)!=map1.end())
            {
                if(map1[b]+map2[b]<sum||sum<0)
                {
                	 /*cout<<map1[b]<<map2[b]<<b<<endl;*/
                    sum  = map2[b]+map1[b];
                }
            }}
            if(a == 1&&b == 1)
            {
                break;
            }
            if(a==4||a==16||a==37||a==58||a==89||a==145||a==42||a==20)
    	    {
        	flag1++;
        	if(b == 1)
        	{
        	break;
        	}
    	    }
    	    if(b==4||b==16||b==37||b==58||b==89||b==145||b==42||b==20)
    	    {
        	flag2++;
        	if(a== 1)
        	break;
    	    }
    	    if(flag1 >= 8&&flag2 >= 8)
    	    break;
    	    if(sum>0&&cnt1>sum&&cnt2>sum)
    	    break;
    	    
	}
	if(sum<=0)
	printf("%d %d 0\n",A,B);
	else
	printf("%d %d %d\n",A,B,sum);
    }
}
