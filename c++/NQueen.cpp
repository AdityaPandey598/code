#include <bits/stdc++.h>
using namespace std;

void disp(vector<vector<int>> &ans)
{
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans.size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool IsSafe(int col,int row,vector<vector<int>> &b,int n)
{
    int i=row;
    int j=col;
    while(j>=0)
    {
        if(b[i][j]==1)
         return false;
        else
        {
         j--;
        }
    }
    i=row;
    j=col;
    while(i>=0 && j>=0)
    {
        if(b[i][j]==1)
         return false;
         else
         {
            i--;
            j--;
         }
          
    }
    i=row;
    j=col;
     while(i<n && j>=0)
    {
        if(b[i][j]==1)
         return false;
        else
        {
            i++;
            j--;
        }
    }
    return true;
}
void solve(int columns,vector<vector<int>> &a,int Queens)
{
    if(Queens==columns)
    {
        disp(a);
        cout<<endl;
        return;
    }
     
    for(int row=0;row<Queens;row++)
    {
        if(IsSafe(columns,row,a,Queens))
        {
            a[row][columns]=1;
            solve(columns+1,a,Queens);
            a[row][columns]=0;
        }
    }
}
void NQueen(int n)
{
    vector<vector<int>> ans(n,vector<int>(n,0));
    solve(0,ans,n);
    return ans;
}
int main()
{

 NQueen(4);

    return 0;
}