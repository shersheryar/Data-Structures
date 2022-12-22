#include <iostream>
using namespace std;
//----------------------------------------------node class---------------------------------------
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
//--------------------------------------------AVL TREE class-------------------------------------------
class AVLTree{
    private:
        //private data member and methods
        node* root;
        node* Insert(node* root, int  val);
        node* Delete(node* root, int data);
        node* PreOrderTraversal(node* root);
        node* FindMax(node* root);
        //rotation
        node* singleRightRotate(node* &t);
        node* singleLeftRotate(node* &t);
        node* doubleRightLeftRotate(node* &t);
        node* doubleLeftRightRotate(node* &t);
        int getBalance(node* t);
        public:
            AVLTree(){
                root = NULL;
            }
            void Insert(int val){
                root = Insert(this->root, val);
            }
            void Delete(int val){
                root = Delete(this->root, val);
            }
            void PreOrderTraversal(){
                PreOrderTraversal(this->root);
            }
            int height(node* t){
                return(t == NULL ? -1 : t->height);
            }
            int lenght(node* r){
                int lh = 0 , rh = 0;
                if(r == NULL){
                    return -1;
                }
                if(r->left != NULL){
                    lh++;
                    lh+=lenght(r->left);
                }
                if(r->right != NULL){
                    rh++;
                    rh+=lenght(r->right);
                }
                if(rh>lh ) return rh;
                else return lh;
            }
            int treeHeight(node* t){
                int static l_height = 0;
                int static r_height = 0;
                if(t == NULL){
                    return -1;
                 }
                else{
                    l_height = treeHeight(t->left);
                        r_height = treeHeight(t->right);
                        if(l_height > r_height){
                            return (l_height + 1);
                        }
                        else{
                            return (r_height + 1);
                        }
                }
            }
};

int main(){
    AVLTree tree1, tree2;
    tree1.Insert(10);
    tree1.Insert(18);
    tree1.Insert(6);
    tree1.Insert(9);
    tree1.Insert(15);
    tree1.Insert(14);
    tree1.Insert(20);
    cout << "Pre Order Print (Root -- left -- right)" << endl;
    tree1.PreOrderTraversal();

    return 0;
    
}

// --------------------------------Functions------------------------
// --------------------------------Insert------------------------------------
node* AVLTree::Insert(node* t, int val){
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
node* AVLTree::doubleRightLeftRotate(node* &t){
    t->right = singleRightRotate(t->right);
    return singleLeftRotate(t);
}
// ------------------------------ double left right rotate ---------------------------------------
node* AVLTree :: doubleLeftRightRotate(node* &t){
    t->left = singleLeftRotate(t->left);
    return singleRightRotate(t);
}
// --------------------------------- single right rotate -----------------------------------------
node* AVLTree::singleRightRotate(node* &t){
    node* u = t->left;
    t->left = u->right;
    u->right = t;
    t->height = max(height(t->left), height(t->right))+1;
    u->height = max(height(u->left), t->height) + 1;
    return u;
}

// ---------------------single left rotate ----------------------
node* AVLTree::singleLeftRotate(node* &t){
    node* u = t->right; 
    t->right = u->left;
    u->left = t;
    t->height = max(height(t->left), height(t->right))+1;
    u->height = max(height(u->right), t->height)+1;
    return u;
}
node * AVLTree::Delete(node* r, int data)
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
            node* temp = FindMax(r->right);
            int x= r->data;  //
            r->data = temp->data;
            temp->data= x;
            r->left = Delete(r->left, temp->data);
        }
    }
     if(r == NULL) return r;

        r->height = max(height(r->left), height(r->right))+1;

        // If node is unbalanced
        // If left node is deleted, right case
        if(height(r->left) - height(r->right) == 2)
        {
            // right right case
            if(height(r->left->left) - height(r->left->right) == 1)
                return singleLeftRotate(r);
            // right left case
            else
                return doubleRightLeftRotate(r);
        }
        // If right node is deleted, left case
        else if(height(r->right) - height(r->left) == 2)
        {
            // left left case
            if(height(r->right->right) - height(r->right->left) == 1)
                return singleRightRotate(r);
            // left right case
            else
                return doubleLeftRightRotate(r);
        }
        return r;
}
node* AVLTree::FindMax(node* r){    
    while(r->right!=NULL){
        r= r->right;
    }
    return r;    
}
node* AVLTree::PreOrderTraversal( node* r){
     if (r == NULL)
        return NULL;
    cout << " "<< r->data << " -> ";
    PreOrderTraversal(r->left);
    PreOrderTraversal(r->right);    
}
