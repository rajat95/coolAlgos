#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
void compute_lcp(int arr[], string pattern)
{
    int i,j,t;
    i = 1;
    j = 0;
    arr[0] = 0;
    while(i<pattern.size())
    {
        if(pattern[i] == pattern[j])
        {
            j++;
            arr[i] = j;
            i++;

        }
        else
        {
            if(j == 0)
            {
                arr[i] = 0;
                i++;
            }
            else
            {
                j = arr[j-1];

            }
        }
    }
}
int kmp(string text, string pattern, int arr[])
{
    int i = 0;
    int j = 0;
    while(i<text.size())
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;
            if(j == pattern.size())
            {
                return(i-j);
            }
        }
        else
        {
            if(arr[j]!=0)
            {
                j = arr[j-1];
            }
            else
                i = i+1;
        }
    }
    return -1;
}
int main(void)
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    int arr[100];
    compute_lcp(arr,pattern);
    printf("%d\n",kmp(text,pattern,arr));
}
