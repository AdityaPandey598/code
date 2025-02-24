#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &mat, int i, int j)
{
    mat[i][j] = 1;
    mat[j][i] = 1; 
}

void add(vector<vector<int>> &a, int u,int v)
{
    a[u].push_back(v);
    a[v].push_back(u);
}

void print(vector<int> &s)
{
    for(int i=0;i<s.size();i++)
      {
        cout<<s[i]<<" ";
      }
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

 vector<int> BFStraversal(vector<vector<int>> &m,int v)
 {
    queue<int> q;
     vector<int> ans;
        vector<bool> visited(5,0);
         visited[v]=1;
          q.push(v);
      int node;
        
         while(!q.empty())  
         {
            node=q.front();
             q.pop();
              ans.push_back(node);
    
               for(int i=0;i<m[node].size();i++)
               {
                if(!visited[m[node][i]])
                {
                    visited[m[node][i]]=1;
                      q.push(m[node][i]);
                }
               }
            
              
         }
         return ans;
 }

int detectCycle(int node,vector<vector<int>> &a,vector<int> &visited,/*vector<int> &ans,*/int parent)
{
    //ans.push_back(node);
    visited[node]=1;
     
      for(int i=0;i<a[node].size();i++)
      {
         
        if(!visited[a[node][i]])
        {
             return DFStraversal(a[node][i],a,visited,node);
        }
         if(visited[a[node][i]]==1 && visited[a[node][i]]!=parent)
         {
          return 1;
          cout<<"test";
         }
      }
           return 0;
}

int main()
{

    
    int V = 5;
    vector<vector<int>> mat(V, vector<int>(V, 0));

   
    addEdge(mat, 0, 1);
    addEdge(mat, 0, 2);
    addEdge(mat, 1, 2);
    addEdge(mat, 2, 3);


   // cout << "Adjacency Matrix Representation" << endl;
     //displayMatrix(mat);
     cout<<endl;

     vector<vector<int>> list(V);

    add(list, 0, 1);
    add(list, 1, 2);
    add(list, 2, 3);
    add(list, 3, 4);
    //add(list, 4, 1);
     displayMatrix(list);

     vector<int> tra=BFStraversal(list,2);
     //print(tra);
      
       vector<int> vis(V,0);
       vector<int> answer;

       if(DFStraversal(0,list,vis,-1))
       {
        cout<<"cycle";
       }
        else
        {
          cout<<"no cycle";
        }
        //print(answer);


    return 0;
}
