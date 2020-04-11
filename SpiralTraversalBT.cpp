// Using Two Queues for traversals 
// One Queue is for Even levels and Second Queue is for Odd Levels of a Binary Tree


#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node* left; 
    node* right;
};

node* newNode(int data){
    node* temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
void spiralTraversal(node* root){
    
    if(root == NULL)
      return;
    
    stack<node* > stackEven;
    stack<node* > stackOdd;
    
    stackOdd.push(root);
    
    while(!stackOdd.empty() || !stackEven.empty()){
        
        
        while(!stackOdd.empty()){
            node* temp = stackOdd.top();
            stackOdd.pop();
        
            cout<<temp->data<<" ";
            if(temp->right)
               stackEven.push(temp->right);
            if(temp->left)
               stackEven.push(temp->left);
        }
        while(!stackEven.empty()){
            node* temp = stackEven.top();
            stackEven.pop();
            
            cout<<temp->data<<" ";
            if(temp->left)
               stackOdd.push(temp->left);
            if(temp->right)
               stackOdd.push(temp->right);
        }
        
    }
}


int main(){
    cout<<"checking full binary tree for the given tree"<<endl;
    
    node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    
    spiralTraversal(root);
        
    return 0;    
}

