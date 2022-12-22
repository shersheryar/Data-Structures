#include <iostream>
using namespace std;

  class node{
    public:
        int data;
        node *left, *right;
        int height;
        node(int data){
            this->data = data;
            left = right = NULL;
            height = 0;
        }
};

class BinarySearchTree{
    private:
    //node class
  

    node* root;
    node* Insert(node* root, int val);
    node* AvlInsert(node* t, int val);
    node* AVLInOrderTraversal(node* r);
    node* Delete(node* r, int data);
    node* InOrderTraversal(node* root);
    node* PreOrderTraversal(node* root);
    node* PostOrderTraversal(node* root);
    node* singleRightRotate(node* &t);
    node* singleLeftRotate(node* &t);
    node* doubleRightLeftRotate(node* &t);
    node* doubleLeftRightRotate(node* &t);
    node* FindMax(node* root);
    public:
        BinarySearchTree(){
            root = NULL;
        }
        void Insert(int val){
            Insert(this->root,val);
        }
        void InsertAvl(){
            AVLInOrderTraversal(this->root);
        }
        int height(node* t){
            return(t == NULL ? -1 : t->height);
        }
        void Delete(int val){
            Delete( this->root, val);
        }
        void InOrderTraversal(){
            InOrderTraversal(this->root);
        }
        void PreOrderTraversal(){
            PreOrderTraversal(this->root);
        }
        void PostOrderTraversal(){
            PostOrderTraversal(this->root);
        }
};

int main(){
    BinarySearchTree tree1, tree2;
    tree1.Insert(1);
    tree1.Insert(2);
    tree1.Insert(3);
    tree1.Insert(4);
    tree1.Insert(5);
    tree1.Insert(6);
    tree1.Insert(7);
    tree1.Insert(8);
    tree1.Insert(9);
    tree1.Insert(10);
    // tree1.Delete(1);

    // cout << "Before converting into avl" << endl;
    // cout << "In Order Print left--Root--Right" << endl;
    // tree1.InOrderTraversal();
    // cout << endl;
    // tree1.InsertAvl();
    // cout << "After converting into avl" << endl;
    // cout << "In Order Print left--Root--Right" << endl;
    // tree1.InOrderTraversal();
    return 0;
    
}

node* BinarySearchTree :: Insert(node* r, int val){
    if (r == NULL)
    {
        node* t = new node(val);
        if(r == root){
            root = t;
        }
        else{
            r = t;
        }
    }
    else if(r->data == val){
        cout << "Record already exits" << endl;
    }
    else if(val < r->data){
        r->left = Insert(r->left , val);
    }
    else if(val > r->data){
        r->right = Insert(r->right,val);
    }
    return r;
    
}

node * BinarySearchTree::Delete(node* r, int data)
{
//    node * r= root1;
    if(r==NULL)
     return r;
    else if(data < r->data)
        r->left = Delete(r->left, data);
    else if (data> r->data)
        r->right = Delete(r->right, data);
    else
    {
        //No child
        if(r->right == NULL && r->left == NULL)
        {
            delete r;
            r = NULL;  
            return r;
        }
        //One child on left
        else if(r->right == NULL)
        {
            node* temp = r;
            r= r->left;
            delete temp;
        }
        //One child on right
        else if(r->left == NULL)
        {
            node* temp = r;
            r= r->right;
            delete temp;
        }
        //two child
        else
        {
            node* temp = FindMax(root->left);
            root->data = temp->data;
            r->left = Delete(root->left, temp->data);
        }
    }
    return r;
}
node* BinarySearchTree::FindMax(node* r){
   
    while(r->right!=NULL){
        r= r->right;
    }
    return r;
   
}

node* BinarySearchTree :: InOrderTraversal(node* r){
    if(r == NULL){
        return NULL;
    }
    //first recur on left child
    InOrderTraversal(r->left);
    // then print the data of node
    cout << " " << r->data << " -> ";
    //now recur on right child
    InOrderTraversal(r->right);
}
node* BinarySearchTree :: AVLInOrderTraversal(node* r){
    if(r == NULL){
        return NULL;
    }
    //first recur on left child
    AVLInOrderTraversal(r->left);
    // then print the data of node
    // cout << " " << r->data << " -> ";
    int val = r->data;
    // DeleteNodeInBST(r,val);
    this->Delete(val);
    // cout << " there \n";
    AvlInsert(r,val);
    // cout << " here \n";
    //now recur on right child
    AVLInOrderTraversal(r->right);
}

node* BinarySearchTree::AvlInsert(node* t, int val){
    if(t == NULL){
        t = new node(val);
    }
    else if( t->data == val){
        cout << "record already exits: " << val << endl;
    }
    else if(val < t->data) // insert on left
    {
        t->left = Insert(t->left, val);
        int bf = height(t->left) - height (t->right);
            if(bf == 2){
                if(val < t->left->data){
                    t = singleRightRotate(t);
                }
                else{
                    t = doubleRightLeftRotate(t);
                }
            }
    }
    else if(val > t->data){ //insert on right
        t->right = Insert(t->right , val);
        int bf = height(t->right) - height(t->left);
            if(bf == 2){
                if(val > t->right->data){
                    t= singleLeftRotate(t);
                }
                else{
                    t = doubleLeftRightRotate(t);
                }
            }
    }
    t->height = max(height(t->left), height(t->right)) +1;
    return t;

}
// ------------------------double right left rotate----------------------------------
node* BinarySearchTree::doubleRightLeftRotate(node* &t){
    t->right = singleRightRotate(t->right);
    return singleLeftRotate(t);
}
// ------------------------------ double left right rotate ---------------------------------------
node* BinarySearchTree :: doubleLeftRightRotate(node* &t){
    t->left = singleLeftRotate(t->left);
    return singleRightRotate(t);
}
// --------------------------------- single right rotate -----------------------------------------
node* BinarySearchTree::singleRightRotate(node* &t){
    node* u = t->left;
    t->left = u->right;
    u->right = t;
    t->height = max(height(t->left), height(t->right))+1;
    u->height = max(height(u->left), t->height) + 1;
    return u;
}

// ---------------------single left rotate ----------------------
node* BinarySearchTree::singleLeftRotate(node* &t){
    node* u = t->right; 
    t->right = u->left;
    u->left = t;
    t->height = max(height(t->left), height(t->right))+1;
    u->height = max(height(u->right), t->height)+1;
    return u;
}
