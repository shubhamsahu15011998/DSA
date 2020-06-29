#include<bits/stdc++.h>
using namespace std;
//All types of traversal

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void in_order(Node *root)
{
    if(root->left) in_order(root->left);
    cout<<root->data<<" ";
    if(root->right) in_order(root->right);
}

void in_order_nr(Node *root)  //nr = non recursive
{
    stack<Node*> stak;
    do
    {
        while(root)
        {
            stak.push(root);
            root=root->left;
        }
        root=stak.top();stak.pop();
        cout<<root->data<<" ";
        root=root->right;
    }while(!stak.empty() || root!=NULL);
}

void pre_order(Node *root)
{
    cout<<root->data<<" ";
    if(root->left) pre_order(root->left);
    if(root->right) pre_order(root->right);
}

void pre_order_nr(Node *root)  //nr = non recursive
{
    stack<Node*> stak;
    do
    {
        while(root)
        {
            stak.push(root);
            cout<<root->data<<" ";
            root=root->left;
        }
        root=stak.top()->right;stak.pop();
    }while(!stak.empty() || root!=NULL);
}

void post_order(Node *root)
{
    if(root->left) post_order(root->left);
    if(root->right) post_order(root->right);
    cout<<root->data<<" ";
}

void post_order_nr(Node *root)  //nr = non recursive
{
    stack<Node*> stak;
    Node *pre=NULL;
    long i=0,j;
    do
    {
        while(root)
        {
            stak.push(root);
            root=root->left;
        }
        root=stak.top();
        if(pre==root->right || (root->right==NULL)) {cout<<root->data<<" ";stak.pop();pre=root;root=NULL;}
        else  root=root->right;
    }while(!stak.empty() || root!=NULL);
}

void level_order(Node *root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        root=q.front();q.pop();
        cout<<(root->data)<<" ";
        if(root->left) q.push(root->left);
        if(root->right) q.push(root->right);
    }
}

int main()
{
    int n,i=0;
    cin>>n;
    queue<Node*> q;
    Node *root,*temp=new Node();n--;
    root=temp;
    q.push(temp);
    while(!q.empty())
    {
        temp=q.front();q.pop();
        temp->data=++i;
        if(n>0) {temp->left=new Node();n--;q.push(temp->left);}
        if(n>0) {temp->right=new Node();n--;q.push(temp->right);}
    }

    cout<<"LEVEL ORDER :  ";
    level_order(root);
    cout<<endl;


    cout<<"IN ORDER   :  ";
    in_order(root);
    cout<<endl;

    cout<<"IN ORDER NR:  ";
    in_order_nr(root);
    cout<<endl;


    cout<<"PRE ORDER   :  ";
    pre_order(root);
    cout<<endl;

    cout<<"PRE ORDER NR:  ";
    pre_order_nr(root);
    cout<<endl;


    cout<<"POST ORDER   :  ";
    post_order(root);
    cout<<endl;

    cout<<"POST ORDER NR:  ";
    post_order_nr(root);
    cout<<endl;


    return 0;
}
