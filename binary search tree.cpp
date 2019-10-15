#include<iostream>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
}*root=NULL;;

struct node* create_node(int value)
{

    struct node* n= new node;
    n->data=value;
    n->left=NULL;
    n->right=NULL;
    return n;
};


void insertion(struct node*& root, struct node* new_node)
{

    if(root==NULL)
         root=new_node;
    if(root->data < new_node->data)
        insertion(root->right,new_node);
    if(root->data > new_node->data)
        insertion(root->left,new_node);
}

void inorder(struct node* root)
{
    if(root->left)
    inorder(root->left);
    cout<<root->data<<" ";
    if(root->right)
    inorder(root->right);

}

int main(){
    int arr[]={10, 20, 30, 25, 15, 5, 35, 45, 55, 50, 45, 40};

    int s=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<s;i++)
    {
        insertion(root,create_node(arr[i]));
    }

    inorder(root);
    return 0;
}
