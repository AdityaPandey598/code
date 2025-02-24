#include <bits/stdc++.h>
using namespace std;
bool solve(vector<vector<char>> &b,string word,string ans,int check,int row,int col,int n_length,int n_width)
{
    if(ans==word) 
    {
        return true;
    }

    if(b[row][col+1]==word[check+1] && col+1<n_length)
    {
        ans.push_back(b[row][col+1]);
        if(solve(b,word,ans,check+1,row,col+1,n_length,n_width))
        {
            return true;
        }
        ans.pop_back();
    }

    if(b[row+1][col]==word[check+1] && row+1<n_width)
    {
        ans.push_back(b[row+1][col]);
        if(solve(b,word,ans,check+1,row+1,col,n_length,n_width))
        {
            return true;
        }
        ans.pop_back();
    }

    if(b[row][col-1]==word[check+1] && col-1>=0)
    {
        ans.push_back(b[row][col+1]);
        if(solve(b,word,ans,check+1,row,col+1,n_length,n_width))
        {
            return true;
        }
        ans.pop_back();

    }

    if(b[row-1][col]==word[check+1] && row-1>=0)
    {
        ans.push_back(b[row+1][col]);
        if(solve(b,word,ans,check+1,row+1,col,n_length,n_width))
        {
            return true;
        }
        ans.pop_back();
    }

    return false;
}
void WordSearch(vector<vector<char>> &a,string word)
{
    int n_length=a[0].size();
    int n_width=a.size();
    string ans;
    ans.push_back(word[0]);
    int check=0;
    if(solve(a,word,ans,check,0,0,n_length,n_width))
    {
        cout<<"Word Exists";
    }
     else
     {
        cout<<"Does not exist";
     }
}
int main()
{

vector<vector<char>> matrix={{'A','B','C','E'},
                             {'S','F','C','S'},
                             {'A','D','E','E'}};
string word="ABCB";
WordSearch(matrix,word);

    return 0;
}
