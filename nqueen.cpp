#include <bits/stdc++.h>
void sol(int A,int r,vector<string>&temp,vector<vector<string> >&ans,vector<vector<int> >p)
{
    
    if(r == A)
    {
        ans.push_back(temp);
        return;
    }
    int l = temp.size();
    
    for(int i = 0;i<A;i++)
    {
        vector<vector<int> >pos = p;
        if(pos[r][i] == 0)
        {
            pos[r][i] = 1;
            for(int j = 0;j<A;j++)
            {
                pos[r][j] = 1;
                pos[j][i] = 1;
                if(i-j>=0&&r-j>=0)
                    pos[r-j][i-j] = 1;
                if(i+j<A&&r-j>=0)
                {
                    pos[r-j][i+j] = 1;
                }
                if(i+j<A&&r+j<A)
                {
                    pos[r+j][i+j] = 1;
                }
                if(i-j>=0&&r+j<A)
                {
                    pos[r+j][i-j] = 1;
                }
            }
            string s = "";
            for(int j = 0;j<A;j++)
            {
                if(j == i)
                s = s+"Q";
                else
                s = s+".";
            }
            temp.push_back(s);
            sol(A,r+1,temp,ans,pos);
            temp.erase(temp.begin()+l,temp.end());
        }
    }
    return;
}
vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<string>temp;
    vector<vector<string> > ans;
    vector<vector<int>>pos;
    for(int i = 0;i<A;i++)
    {
        vector<int>v;
        v.assign(A,0);
        pos.push_back(v);
    }
    sol(A,0,temp,ans,pos);
    return ans;
}
