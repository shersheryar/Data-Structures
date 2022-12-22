#include <iostream>
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
    node* concate(node* root);
    int countNode(node* root,int);
    int height(node* root, int,int,int);
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
        void concatinate(BinarySearchTree obj){
            concate(obj.root);
        }
        int countNodes(){
            int Count = 0;
            int n = countNode(this->root,Count);
            // return Count;
            return n;
        }
        int Height(int value){
            int c = 0;
            int info = 0;
            int n = height(this->root,value,c,info);
            return n;
        }
};

int main(){
    BinarySearchTree tree1, tree2;
    tree1.Insert(10);
    tree1.Insert(8);
    tree1.Insert(6);
    tree1.Insert(12);
    // tree1.Delete(12);
    tree2.Insert(30);
    tree2.Insert(20);
    tree2.Insert(34);
    tree2.Insert(23);
    tree2.Insert(24);
    tree2.Insert(40);
    // int Count = tree2.countNodes();
    // int h = tree2.Height(0);
    // cout  << "nodes " << h;
    // cout << " Count = " << Count;
    // tree1.concatinate(tree2);
    // tree1.InOrderTraversal();
    cout << tree1.countNodes();


    // cout << "In Order Print (left--Root--Right" << endl;
    // // tree1.InOrderTraversal();
    // cout <<"\n-----------------------------------" << endl;
    // cout << "Pre Order Print (Root--left--Right" << endl;
    // // tree1.PreOrderTraversal();
    // // cout <<"\n-----------------------------------" << endl;
    // cout << "Post Order Print (left--Right--Root" << endl;
    // tree1.PostOrderTraversal();
    // cout <<"\n-----------------------------------" << endl;
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
    cout << r->data <<" -> ";
    //now recur on right child
    InOrderTraversal(r->right);
}
// int BinarySearchTree :: concate (node* r){
//     if(r->left != NULL){
//         concate(r->left);
//     }
//     this->Insert(r->data);
//     if(r->right != NULL){
//         concate(r->right);
//     }
// }
node* BinarySearchTree :: concate (node* r){
      if(r == NULL){
        return NULL;
    }
    //first recur on left child
    InOrderTraversal(r->left);
    // then print the data of node
    this->Insert(r->data);
    //now recur on right child
    InOrderTraversal(r->right);
}
int BinarySearchTree :: countNode(node* r, int Count){

    if(r->left == NULL && r->right == NULL){
        return Count;
    }

    else if(r->left != NULL){
        Count +=1;
    countNode(r->left,Count);
    }
    else if(r->right != NULL){
        Count +=1;
    countNode(r->right,Count);
    }
        // cout<< "count = " << Count << endl;   
}
int BinarySearchTree :: height(node* r, int h, int c, int info){
    // cout << c << " ";
    if( c == h ){
        cout << " info " << info << endl;
        
        if(r->left != NULL & r->right != NULL){
            info += 2;
            // cout  << "info";
            
            c-=1;
            return info;
        }
        else if(r->left == NULL & r->right != NULL){
            info+=1;
            c-=1;
            return info;
        }
        else{
            info += 1;
            c-=1;
            return info;
        }
    }
    // else if{
    //      if(r->left != NULL && c < h-1){
    //         c+=1;
    //         height(r->left,h,c,info);
    //         return info;
    //      }
    //     if(r->right != NULL &&  c < h-1){
    //     c+=1;
    //     height(r->right,h,c,info);
    //     return info;
    //     }
    //     else{
    //         return info;
    //     }
    // }
    else if(c != h-1 && r->left != NULL){
        c+=1;
        height(r->left,h,c,info);

    }
    else if(c != h-1 && r->right != NULL){
        c+=1;
        height(r->right,h,c,info);
    }
    else{
        return info;
    }
}
