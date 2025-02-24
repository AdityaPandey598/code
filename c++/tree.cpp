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

void printTree(node* root) {
    if (!root) {
        return;
    }
      printTree(root->left);
    cout << root->value << " ";
   
    printTree(root->right);
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


node *buildTree(vector<int> &a)
{
    queue<node*> q;
    int i=1;
    node *root=new node(a[0]);
    q.push(root);

     while(i<a.size())
     {
        node *temp=q.front();
        q.pop();

         if(i<a.size())
         {
            temp->left=new node(a[i++]);
            q.push(temp->left);
         }

         if(i<a.size())
         {
            temp->right=new node(a[i++]);
            q.push(temp->right);
         }
     }
     return root;

}

int checkBst(node *root,long minval,long maxval)
{
    if(root==NULL)
    {
        return 1;
    }
     if(root->value>maxval || root->value<minval)
     {
        return 0;
     }
      return checkBst(root->left,minval,root->value) && 
             checkBst(root->right,root->value,maxval);

}

int main()
{
 /*queue<node*> q;
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
 }*/

  vector<int> nums = { 1, 2, 3, 4, 5, 6, 6, 6, 6 };
    node* root = buildTree(nums);
    printTree(root);




    return 0;
}