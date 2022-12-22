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

void insert(tree* root, int val){
    tree* temp;
        temp = root;
    if(root == NULL){
        tree* n = new tree(val);
        root = n;
        // cout << root->data << "hello";
        return;
    }
    if(val < temp->data){
        if(temp->left == NULL){
            tree* n = new tree(val);
            temp = n;
            cout << temp->data;
            return;
        }
        insert(temp->left,val);
        return;
    }
    else if(val > temp->data){
        if(temp->right == NULL){
            tree* n = new tree(val);
            temp = n;
            cout << root->data;
            return;
        }
        insert(temp->right,val);
        return;
    }
}
void preOrder(tree* root){
    if(root == NULL){
        return;
    }
    cout << root->data <<" ";
    preOrder(root->left);
    preOrder(root->right);
}
int main(){
    tree* root = NULL;
    insert(root, 5);
    // preOrder(root);
    // cout << root->data;
    insert(root, 3);
    // insert(root, 2);
    // insert(root, 4);
    // cout << endl;
    // cout << root->data;
    // insert(root, 1);
    preOrder(root);
}
