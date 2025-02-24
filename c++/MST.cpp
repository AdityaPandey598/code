#include <bits/stdc++.h>
using namespace std;
int SPT(int V,vecotr<vector,int>> adj[])
{
  priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

   vector<int> IsMst(V,0);
   vector<int> parent(V);

    int cost=0;
      pq.push({0,{0,-1}});

       while(!pq.empty())
       {
        int wt=pq.top().first;
        int node=pq.top().second.first;
        int par=pq.top().second.second;

         pq.pop();
          if(!IsMst[node])
          {
            IsMst[node]=1;
            cost+=wt;
            parent[node]=par;

             for(int i=0;j<adj[node].size();i++)
             {
                if(!IsMst[node][i][0])
                {
                    pq.push({adj[node][i][1],{adj[node][i][0],node}});
                } 
             }
          }
       }
      return cost;
}

int main()
{



    return 0;
}