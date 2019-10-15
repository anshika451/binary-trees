#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct NODE{
    int data;
    struct NODE *left;
    struct NODE *right;
};

struct NODE* create_node(int key)
{
    struct NODE* newnode= new NODE;
    newnode->data=key;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void insert_node(struct NODE*& root,struct NODE* node)
{
    char ch;
    if(root==NULL)
    {
        root=node;
        cout<<"node inserted";
    }
    else
    {
        cout<<"\nENTER L OR R to insert in left or right of:"<<root->data<<" respectively.:";
        cin>>ch;
        if(ch=='L')
            insert_node(root->left,node);
        if(ch=='R')
            insert_node(root->right,node);
    }
}



void levelorder(struct NODE* root)
{
    struct NODE* curr=NULL;
    queue<struct NODE*> q;
    q.push(root);
    while(!q.empty())
    {
        curr=q.front();
        q.pop();
        cout<<" "<<curr->data;
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
    }
}


void preorder_nr(struct NODE* root)
{
    struct NODE* curr=root;
    stack<struct NODE*> s;
    s.push(NULL);
    while(curr)
    {
        cout<<" "<<curr->data;
        if(curr->right)
            s.push(curr->right);
        if(curr->left)
        curr=curr->left;
        else
           {
            curr=s.top();
            s.pop();
           }
    }
}

void inorder_nr(struct NODE* root)
{
    struct NODE* curr=root;
    stack<struct NODE*> SI;
    while(curr!=NULL || SI.empty()==false)
    {
        while(curr!=NULL)
        {
            SI.push(curr);
            curr=curr->left;
        }
        curr=SI.top();
        SI.pop();
        cout<<" "<<curr->data;
        curr=curr->right;
    }
}

void postorder(struct NODE* root)
{
    if(root)
    {   
        if(root->left)
            postorder(root->left);
        if(root->right)
            postorder(root->right);
        cout<<" "<<root->data;
    }
}

int main()
{
    struct NODE* root=NULL;
    int val;
    char ch1='Y';
    do
    {
        cout<<"\nEnter value to be inserted into BT:";
        cin>>val;
        insert_node(root,create_node(val));
        cout<<"\nWANT TO ENTER MORE(Y/N):";
        cin>>ch1;
    }
    while(ch1=='Y');
    
    cout<<"\n";
    levelorder(root);
    cout<<"\n";
    preorder_nr(root);
    cout<<"\n";
    inorder_nr(root);
    cout<<"\n";
    postorder(root);
    return 0;
}
