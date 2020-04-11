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

bool full_binary_check(node* root){
    if(!root)
      return true;
    
   queue<node* > q;
   int n;
   q.push(root);
   n = q.size();
    
   while(!q.empty()){
        node* front = q.front();
        q.pop();
        if(front->left == NULL && front->right == NULL)
            continue;
        if(front->left == NULL || front->right == NULL)
            return false;
        
        q.push(front->left);
        q.push(front->right);
    }
    return true;
}
int main(){
    cout<<"checking full binary tree for the given tree"<<endl;
    node* root = NULL;
    root = newNode(4);
    root->left = newNode(9);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
   // root->right->right = newNode(7);
    if(full_binary_check(root))
         cout<<"true";
    else
        cout<<"false";
        
    return 0;    
}
