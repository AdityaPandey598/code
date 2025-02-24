// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
vector<vector<int>> generate(int numRows)
     {
        vector<vector<int>> tri;
        vector<int> OgTemp;
        OgTemp.push_back(1);
        tri.push_back(OgTemp);
        for(int i=1;i<numRows;i++)
        {
            vector<int> temp;
            for(int j=0;j<i+1;j++)
            { 
             if(j==0||j==tri[i-1].size())
             {
                temp.push_back(1);
             }
              else
              {
                temp.push_back(tri[i-1][j-1]+tri[i-1][j]);
              }
            }
             tri.push_back(temp);
        }
        return tri;
     }

       
int main() {
   vector<vector<int>> a=generate(5);
   for(int i=0;i<a.size();i++)
   {
       for(int j=0;j<a[i].size();j++)
       {
           cout<<a[i][j]<<" ";
       }
       cout<<endl;
   }

    return 0;
}