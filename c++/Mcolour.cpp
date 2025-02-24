#include <bits/stdc++.h>
using namespace std;

void add(vector<vector<int>> &a, int u,int v)
{
    a[u].push_back(v);
    a[v].push_back(u);
}

void displayMatrix(vector<vector<int>> &mat)
{
    int V = mat.size();
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

bool IsSafe(vector<vector<int>> &a,int node,int col,vector<int> &colour)
{
    for(int i=0;i<a[node].size();i++)
    {
        if(colour[a[node][i]]==col)
         return false;
    }
    return true;
}

bool Mcolour(vector<vector<int>> &a,int node,vector<int> &colour)
{
    if(node==a.size()) return true;

    for(int col=1;col<=3;col++)
    {
        if(IsSafe(a,node,col,colour))
        {
            colour[node]=col;
            if(Mcolour(a,node+1,colour))
            {
                return true;
            }
            colour[node]=0;
        }
    }
    return false;
}

int main()
{

    vector<vector<int>> mat(3);
    vector<int> colour(3,0);
    add(mat,0,1);
    add(mat,1,2);
    add(mat,0,2);
    

   if(Mcolour(mat,0,colour))
   {
    cout<<"True";
   }
    else
    {
        cout<<"false";
    }
    

   
    



    return 0;
}