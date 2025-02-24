#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int value;
    node *left;
    node *right;

    node(int x)
    {
        value=x;
        left=right=NULL;
    }

};

int search(node *root,int target)
{
    if(root==NULL)
    {
     return 0;   
    }
     if(root->value==target)
    {
        return 1;
    }
     if(target>root->value)
     {
        return search(root->right,target);
     }
     else
      {
        return search(root->left,target);
      }
       
}


int traverse(node *root)
{
    vector<vector<int>> ans;
    queue<node*> q;
    q.push(root);
    
      while(!q.empty())
    {
        
        int size=q.size();
        vector<int> push;

        for(int i=0;i<size;i++)
        {
            node *temp=q.front();
            q.pop();

            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }

             if(temp->right!=NULL)
             {
                q.push(temp->right);
             }

             push.push_back(temp->value);
        }
        ans.push_back(push);  
    }
    return ans.size();


}

int main()
{
 queue<node*> q;
 int right,left,r;
 cout<<"Enter root value:";
 cin>>r;
 node *root=new node(r);
 q.push(root);

 while(!q.empty())
 {
    node *temp=q.front();
    q.pop();

    cout<<"enter value of left node for"<<temp->value<<":";
    cin>>left;

    if(left!=-1)
    {
      temp->left=new node(left);
      q.push(temp->left);
    }

     cout<<"enter value of right node for"<<temp->value<<":";
     cin>>right;

     if(right!=-1)
     {
        temp->right=new node(right);
        q.push(temp->right);
     }
 }
 int x;
 cout<<"Enter the number you want to search:";
    cin>>x;
 int result=search(root,x);
 if(result)
 {
    cout<<"exists";
 }
  else 
   cout<<"does not exist";


    return 0;
} 