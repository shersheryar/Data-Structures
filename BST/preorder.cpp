#include <iostream>
using namespace std;

class tree{
    public:
    tree* right;
    tree* left;
    int data;
    tree(int val){
        data = val;
        right = NULL;
        left = NULL;
    }
};


void preOrder(tree* root){
    if(root == NULL){
        return;
    }
    cout << root->data <<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(tree* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data <<" ";
    inOrder(root->right);
}
void postOrder(tree* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data <<" ";
}

int main(){
    tree* root = new tree(5);
    root->left = new tree(3);
    root->left->left = new tree(2);
    root->left->right = new tree(4);
    root->left->left->left = new tree(1);
    postOrder(root);
}