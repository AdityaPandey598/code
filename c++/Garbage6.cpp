#include <iostream>
#include <vector>
#include<map>
using namespace std;
bool IsSafe(int r,int c,vector<vector<int>> &maze,int M)
{
    if(r>=0 && r<M && c>=0 && c<M)
    {
        if(maze[r][c]==1)
        {
            return true;
        }
    }
    return false;
}

void solve(int row,int column,int max,vector<vector<int>> &b,string s,int r_dest,int c_dest)
{
    if(row==r_dest && column==c_dest)
    {
        cout<<s;
        return;
    }
    //down
    if(IsSafe(row+1,column,b,max))
    {
        s.push_back('D');
        b[row][column]=0;
        solve(row+1,column,max,b,s,r_dest,c_dest);
        b[row][column]=1;
    }
    //Up
      if(IsSafe(row-1,column,b,max))
    {
        s.push_back('U');
        b[row][column]=0;
        solve(row-1,column,max,b,s,r_dest,c_dest);
        b[row][column]=1;
    }
    //left
      if(IsSafe(row,column-1,b,max))
    {
        s.push_back('L');
        b[row][column]=0;
        solve(row,column-1,max,b,s,r_dest,c_dest);
        b[row][column]=1;
    }
    //right
      if(IsSafe(row,column+1,b,max))
    {
        s.push_back('R');
        b[row][column]=0;
        solve(row,column+1,max,b,s,r_dest,c_dest);
        b[row][column]=1;
    }
}

void RatInMaze(vector<vector<int>> &a)
{
    string ans=" ";
    solve(0,0,4,a,ans,3,3);
}
int main()
{

    vector<vector<int>> maze={{1,0,0,0},
                              {1,1,0,1},
                              {1,1,0,0},
                              {0,1,1,1}
                            };
    RatInMaze(maze);
    return 0;
}
