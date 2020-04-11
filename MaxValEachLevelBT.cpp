//using Queue for operations
//Below code prints levelwise max value in a binary tree


#include <bits/stdc++.h> 
#include <iostream>

using namespace std;
struct node{
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

void max_val_level_of_tree(node* root){
    int no, max;
    queue<node* > q;
    q.push(root);
    while(1){
        no = q.size();
        max = INT_MIN;
        if(no == 0)
           break;
        while(no--){
            node* front = q.front();
            q.pop();
            if(max<front->data)
                 max = front->data;
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
        cout<<max<<" ";
    }
}

int main()
{
    cout<<"Printing max values in each level of a binary tree"<<endl;
    node* root = NULL;
    root = newNode(4);
    root->left = newNode(9);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(7);
    max_val_level_of_tree(root);
    return 0;
}
