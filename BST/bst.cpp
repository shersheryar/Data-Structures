#include <iostream>
#include <cmath>
using namespace std;

  class node{
    public:
        int data;
        node *left, *right;
        node(int data){
            this->data = data;
            left = right = NULL;
        }
};

class BinarySearchTree{
    private:
    //node class
  

    node* root;
    node* Insert(node* root, int val);
    node* DeleteNodeInBST(node* root, int data);
    node* InOrderTraversal(node* root);
    node* PreOrderTraversal(node* root);
    node* PostOrderTraversal(node* root);
    node* FindMax(node* root);
    node* specificHeight(node* root,int h);
    int MinNode(node* root);
    int MaxNode(node* root);
    int Size(node* root);
    int height(node* root);
    int parentNodes(node* root);
    public:
        BinarySearchTree(){
            root = NULL;
        }
        void Insert(int val){
            Insert(this->root,val);
        }
        void Delete(int val){
            DeleteNodeInBST(this->root,val);
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
        int Height(){
            return height(this->root);
        }
        int size(){
            return Size(this->root);
        }
        int maxNode(){
            return MaxNode(this->root);
        }
        int minNode(){
            return MinNode(this->root);
        }
        void specificHeight(int h){
            specificHeight(this->root,h);
        }
        int parentNodes(){
        
            return parentNodes(this->root);
        }
};

int main(){
    BinarySearchTree tree1, tree2;
    tree1.Insert(100);
    tree1.Insert(50);
    tree1.Insert(150);
    tree1.Insert(75);
    tree1.Insert(125);
    tree1.Insert(74);
    tree1.Insert(76);
    tree1.Insert(124);
    tree1.Insert(130);
    tree1.Insert(73);
    tree1.Insert(131);
    // tree1.Delete(12);
    // cout << "In Order Print (left--Root--Right" << endl;
    // tree1.InOrderTraversal();
    // cout <<"\n-----------------------------------" << endl;
    // cout << tree1.Height();
    // cout << tree1.size();
    // cout << tree1.maxNode();
    // cout << tree1.minNode();
    // tree1.specificHeight(4);
    cout <<tree1.parentNodes();

    // cout << "Pre Order Print (Root--left--Right" << endl;
    // tree1.PreOrderTraversal();
    // cout <<"\n-----------------------------------" << endl;
    // cout << "Post Order Print (left--Right--Root" << endl;
    // tree1.PostOrderTraversal();
    // cout <<"\n-----------------------------------" << endl;
    return 0;
    
}

//=============================INSERT===================================
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
// =================================DELETE=========================================
node* BinarySearchTree :: DeleteNodeInBST(node* root, int data){
    if(root = NULL){
        return root;
    }
    else if(data < root->data){
        root->left = DeleteNodeInBST(root->left ,data);
    }
    else if(data > root->data){
        root->right = DeleteNodeInBST(root->right,data);
    }
    else{
        //NO child
        if(root->right == NULL && root->left == NULL){
            delete root;
            root = NULL;
            return root;
        }
        // One child on left
        else if(root->right = NULL){
            node* temp = root;
            root = root->left;
            delete temp;
        }
        // One child on right
        else if(root->left == NULL){
            node* temp = root;
            root = root->right;
            delete  temp;
        }
        //two child
        else{
            node* temp = FindMax(root->left);
            root->data = temp->data;
            root->left = DeleteNodeInBST(root->left, temp->data);
        }
    }
    return root;
}

// ===================================PARENTS NODES================================
int BinarySearchTree::parentNodes(node* root){
    
    static int count = 0;
    if(root->left==NULL && root->right == NULL){
        return count;
    }
    if(root->left != NULL && root->right == NULL){
        count++;
        parentNodes(root->left);
    }
    else if(root->right != NULL && root->left == NULL){
        count++;
        parentNodes(root->right);
    }
    else if(root->left != NULL && root->right != NULL){
        count++;
        parentNodes(root->left);
        parentNodes(root->right);
    }
}
// ==========================FIND NODES AT GIVEN HEIGHT=========================
node* BinarySearchTree::specificHeight(node* root,int h){
    if(root == NULL){
        return NULL;
    }
    if(h == 1){
        cout << root->data <<" ";
    }else if(h > 1){
        specificHeight(root->left,h-1);
        specificHeight(root->right,h-1);
    }
}
// ===============================FIND HEIGHT OF THE TREE===================================
int BinarySearchTree::height(node* root){
    if(root == NULL){
        return 0;
    }
    return max(height(root->left),height(root->right)) +1;
}
// =====================================FIND TOTAL NUMBER OF NODES=========================================
int BinarySearchTree::Size(node* root){
    if(root == NULL){
        return 0;
    }
    return Size(root->left) + Size(root->right) + 1;
}
// ==================================FINDS MAX NODE=================================================
int BinarySearchTree::MaxNode(node* root){
    if(root == NULL){
        return -1;
    }
    return max(root->data, max(MaxNode(root->left),MaxNode(root->right)));
}
// =======================================FIND MIN NODE===================================================
int BinarySearchTree::MinNode(node* root){
    if(root == NULL){
        return 1000;
    }
    return min(root->data, min(MinNode(root->left),MinNode(root->right)));
}
// ===================================FIND MAX NODES SECOND SOLUTION=========================================
node* BinarySearchTree::FindMax(node* r){
   
    while(r->right!=NULL){
        r= r->right;
    }
    return r;
   
}
// ======================================IN ORDER TRAVERSAL===============================================
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
