#include<iostream> 

class node
{
    public:
    int data,height;
    node *left,*right;

    node(int x)
    {
        data=x;
        height=1;
        left=right=NULL;
    }
};

node* insert(node *root,int key)
{
    if(root==NULL)
    {
        return new node(key);
    }

     if(key< )

}


int main()
{

    node *root=NULL;

    return 0;
}