// Binary Search Tree Implementation..  
#include<iostream>
using namespace std;
    class node {
    public:
    int data;
    node* left, *right;
    node(int data){
        this->data=  data;
        left= right= NULL;
        }
    };
   
class BinarySearchTree{
    private:
    //node class

    //private data members and methods
    node* root;
    node* Insert( node* root, int val);
    node* Delete(node* root,int data);
    node* InOrderTraversal( node* root);
    node* PreOrderTraversal( node* root);
    node* PostOrderTraversal( node* root);
    node* sibling( node* r,int val);
    node* decendent( node* r,int val);
    node* ancestor( node* r,int val);
    node* FindMax(node* root);
    public:
    BinarySearchTree(){
        root= NULL;
    }
    void    Insert(int val){
       
       Insert(this->root,  val);
   }
   
    void    Delete(int val){
   Delete(this->root, val);
   }
    void InOrderTraversal(){
        InOrderTraversal( this->root);
    }
    void siblings(int val){
        sibling( this->root,val);
    }
    void PreOrderTraversal(){
        PreOrderTraversal( this->root);
    }
    void PostOrderTraversal(){
        PostOrderTraversal( this->root);
    }
    void decentants(int val){
        decendent(this->root,val);
    }
    void ancestors(int val){
        ancestor(this->root,val);
    }
};
int main (){
    BinarySearchTree tree1, tree2;
      tree1.Insert(50);
    tree1.Insert(17);
    tree1.Insert(72);
    tree1.Insert(12);
    tree1.Insert(23);
    tree1.Insert(54);
    tree1.Insert(76);
    tree1.Insert(9);
    tree1.Insert(14);
    tree1.Insert(19);
    tree1.Insert(67);
    // tree1.Insert(21);

    // tree1.Delete(10);
    // tree1.ancestors(23);
    // tree1.sibOrderTraversal(9);
    // tree1.siblings(54);
    tree1.decentants(17);
    // cout<<"In Order Print (left--Root--Right)"<<endl;
    tree1.InOrderTraversal();
    // cout<<"\n-----------------------"<<endl;
    // cout<<"Pre Order Print (Root--left--Right)"<<endl;
    // tree1.PreOrderTraversal();    
    // cout<<"\n-----------------------"<<endl;
    // cout<<"Post Order Print (left--Right--Root)"<<endl;
    // tree1.PostOrderTraversal();
    return 0;
}
node* BinarySearchTree::Insert(node* r, int val ){
 if (r==NULL)
    {
        node* t= new node(val);
        if (r==root)
            root=t;
        else
        r=t;
    }
    else if (r->data== val){
        cout<<"Record already exist"<<val;
    }
    else if (val < r->data) // insert on left s
    r->left = Insert(r->left , val );
    else if (val > r->data)
        r->right= Insert( r->right,val);
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
// node * BinarySearchTree::InOrderTraversal( node* r){
//      if (r == NULL)
//         return NULL;
//     //first recur on left child
//     InOrderTraversal(r->left);
//    //then print the data of node
//     cout << " "<< r->data << " -> ";
//   // now recur on right child
//     InOrderTraversal(r->right);
// }
node * BinarySearchTree::InOrderTraversal( node* r){
     if (r == NULL)
        return NULL;
    //first recur on left child
    if(r->left == NULL && r->right!= NULL ){
        cout << " no CBT";
    }
    InOrderTraversal(r->left);
   //then print the data of node
    // cout << " "<< r->data << " -> ";
  // now recur on right child
    InOrderTraversal(r->right);
}
node * BinarySearchTree::decendent( node* r,int val){
    if(val < r->data){
        decendent(r->left,val); 
    }else if(val > r->data){
        decendent(r->right,val);
    }else if(val == r->data,val){
        InOrderTraversal(r->left);
        InOrderTraversal(r->right);
    }
}

node * BinarySearchTree::ancestor( node* r,int val){
     if (r == NULL)
        return NULL;
    //first recur on left child
    if(val != r->data){
        cout << " "<< r->data << " -> ";
        if(val < r->data){
        ancestor(r->left,val);
        }else{
        ancestor(r->right,val);
        }
    }else{
        return NULL;
    }
}

node* BinarySearchTree::FindMax(node* r){    
    while(r->right!=NULL){
        r= r->right;
    }
    return r;    
}
node* BinarySearchTree::PreOrderTraversal( node* r){
     if (r == NULL)
        return NULL;
   
    cout << " "<< r->data << " -> ";
    PreOrderTraversal(r->left);
    PreOrderTraversal(r->right);    
}
node* BinarySearchTree::PostOrderTraversal( node* r){
     if (r == NULL)
        return NULL;
    PostOrderTraversal(r->left);
    PostOrderTraversal(r->right);    
    cout << " "<< r->data << " -> ";
}
// node* BinarySearchTree::PostOrderTraversal( node* r){
//      if (r == NULL)
//         return NULL;
//     PostOrderTraversal(r->left);
//     PostOrderTraversal(r->right);    
//     cout << " "<< r->data << " -> ";
// }

//-------------------------------- Siblings------------------------
node * BinarySearchTree::sibling( node* r,int val){
    if (r == NULL)
        
        return NULL;
   if(r->left->data == val) {
        cout   << " "<< r->right->data << endl;

    }else if(r->right->data == val ){
        cout << r->left->data << endl;
    }
   if(val > r->data){
    sibling(r->right,val);
   }else if(val < r->data){

    sibling(r->left,val);
   }
}