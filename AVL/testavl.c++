#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node *left, *right;
        int height;
        node(int val){
            this->data = val;
            left=right = NULL;
            height = 0;
        }
};

class avl{
    private:
        node* root;
        node* Insert(node* temp, int val);
        node* Delete(node* temp, int data);
        node* PreOrderTraversal(node* temp);
        node* singleLeftRotate(node* &t);
        node* singleRightRotate(node* &t);
        node* doubleRightLeftRotate(node* &t);
        node* doubleLeftRightRotate(node* &t);
        int getBalance(node* t);
        public:
            avl(){
                root = NULL;
            }
            void Insert(int val){
                root = Insert(this->root,val);
            }
            void Delete(int val){
                root = Delete(this->root, val);
            }
            void PreOrderTraversal(){
                PreOrderTraversal(this->root);
            }
            int height(node* t){
                return(t == NULL ? -1 : this->height);
            }
            int length(node* r){
                int lh=0, rh  = 0;
                if(r == NULL){
                    return -1;
                }
                if(r->left != NULL){
                    lh++;
                    lh+=length(r->left);
                }
                if(r->right != NULL){
                    rh++;
                    rh+=length(r->right);
                }
                if(lh>rh) return lh;
                else return rh;
            }
};

int main(){


}

node*  avl::Insert(node* temp, int val){
    if(temp == NULL){
        temp = new node(val);
    }
    else if(temp->data == val){
        cout << "Record already exits: " << val;
    }
    else if(val < temp->data){
        temp->left = Insert(temp->left,val);
        int bf = height(temp->left) - height(temp->right);
        if(bf == 2){
            if(val < temp->left->data){
                temp = singleRightRotate(temp);
            }
            else{
                temp = doubleRightLeftRotate(temp);
            }
        }
    }
    else if(val > temp->data){
        temp->right = Insert(temp->right,val);
        int bf = height(temp->right) - height(temp->left);
        if(val > temp->right){
            temp = singleLeftRotate(temp);
        } 
        else{
            temp = doubleLeftRightRotate(temp);
        }
    }
    temp->height = max(height(temp->left), height(temp->right) + 1);
    return temp;
}

node* avl::doubleRightLeftRotate(node* &t){
    t->right= singleRightRotate(t->right);
    return singleLeftRotate(t);
}
node* avl::doubleLeftRightRotate(node* &t){
    t->left = singleLeftRotate(t->left);
    return singleRightRotate(t);
}

node* avl::singleLeftRotate(node* &t){
    node* u = t->left;
    
}