#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:

  void helper(int i,int j,int n,string move,vector<vector<int>> & initial,vector <string> & ans,vector<vector<int>> & vis)
  {
    if(i==n-1 && j==n-1)
    {
      ans.push_back(move);
      return;
    }
//down
    if(i+1<n && !vis[i+1][j] && initial[i+1][j]==1)
    {
      vis[i][j]=1;
      helper(i+1,j,n,move+'D',initial,ans,vis);
      vis[i][j]=0;
    }

//right
    if(j+1<n && !vis[i][j+1] && initial[i][j+1]==1)
    {
      vis[i][j]=1;
      helper(i,j+1,n,move+'R',initial,ans,vis);
      vis[i][j]=0;
    }    

//left
    if(j-1>=0 && !vis[i][j-1] && initial[i][j-1]==0)  
    {
      vis[i][j]=1;
      helper(i,j-1,n,move+'L',initial,ans,vis);
      vis[i][j]=0;
    }

//up
    if(i-1>=0 && !vis[i-1][j] && initial[i-1][j]==1)
    {
        vis[i][j]=1;
      helper(i-1,j,n,move+'U',initial,ans,vis);
      vis[i][j]=0;
    }
  }
      
      vector < string > findPath(vector < vector < int >> & m, int n)
      {
        vector<vector<int>> visited(n,vector<int> (n,0));
         vector <string> final;
          if(m[0][0]==1)
          {
            helper(0,0,n," ",m,final,visited);
          }
           return final;
      }
  
  
};

int main() {
  int n = 4;

   vector < vector < int >> m = {{1,0,0,0},
                                {1,1,0,1},
                                {1,1,0,0},
                                {0,1,1,1}};

  Solution obj;
  vector < string > result = obj.findPath(m, n);
  if (result.size() == 0)
    cout << -1;
  else
    for (int i = 0; i < result.size(); i++) 
    cout << result[i] << " ";

    cout<<endl;

  return 0;
}