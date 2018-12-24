//Program to implement the insertions and deletion in binary tree

/*
  Created:December 25,2018
  Author:Ashritha27
*/

#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;

//tree node structure
struct node {
    int key;
    struct node* left;
    struct node* right;
};

//creates a new node
struct node* newnode(int key)
{
    struct node* temp = new node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
};

//traverses the tree inorder
void inorder(struct node* temp)
{
    if (!temp)
        return;

    inorder(temp->left);
    cout << temp->key << " ";
    inorder(temp->right);
}

//inserts new node to the tree
void insert(struct node* temp, int key)
{
    queue<struct node*> q;
    q.push(temp);
    while (!q.empty()) {
        struct node* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = newnode(key);
            break;
        } else
            q.push(temp->left);

        if (!temp->right) {
            temp->right = newnode(key);
            break;
        } else
            q.push(temp->right);
    }
}

//deletes the binary tree
void deletetree(struct node* root){
    if(root==NULL)
        return;
    deletetree(root->left);
    deletetree(root->right);
    free(root);

}

int main()
{
    struct node* root;
    root=newnode(1);
    insert(root,2);
    insert(root,3);
    insert(root,4);
    inorder(root);
    deletetree(root);
    inorder(root);

    return 0;
}
