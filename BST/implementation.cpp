#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct node{
    int info;
    node *left, *right;
};

class binSearchTree{
    private:
        node* temp;
        node* delptr;
    public:
        node* root;
        int number;
        binSearchTree();
        void options();
        void Insert(node*);
        void inOrder(node*);
        void Delete(node*);
        int delSpecial(node*);
};
int main(){
    system("cls");
    char ch;
    binSearchTree obj;
    while(1){
        obj.options();
        ch = getch();
        switch(ch)
        {
            case '1':
                system("cls");
                cout <<"\n Enter number to add in a tree ...\n";
                cin>>obj.number;
                obj.Insert(obj.root);
                break;
            case '2':
                system("cls");
                cout <<"\n Enter number to delete in a tree ...\n";
                cin>>obj.number;
                obj.Delete(obj.root);
                break;
            case '3':
                system("cls");
                obj.inOrder(obj.root);
                break;
            case '4':
                exit(0);
                break;
            default:
                exit(0);
                break;
        }
    }
}
// ------------------------------------------
binSearchTree ::binSearchTree(){
    root = temp = delptr = NULL;
}
// ----------------------------------------------
void binSearchTree::Insert(node* temp){
    if(root == NULL){
        temp = new node;
        temp->info = number;
        temp->left = NULL;
        temp->right = NULL;
        root = temp;
        return;
    }
    if(temp->info == number){
        cout <<"\n Given number "<< number <<" is already present in tree.\n";
        return;
    }
    if(temp->info > number){
        if(temp->left != NULL){
            Insert(temp->left);
            return;
        }
        else{
            temp->left = new node;
            temp->left->info = number;
            temp->left->left = NULL;
            temp->left->right = NULL;
            return;
        }
    }
    if(temp->info < number){
        if(temp->right != NULL){
            Insert(temp->right);
            return;
        }
        else{
            temp->right = new node;
            temp->right->info = number;
            temp->right->left = NULL;
            temp->right->right = NULL;
            return;
        }
    }
}

// --------------------------------
void binSearchTree::options(){
    cout<<"\n\n ************** Select Option *****************.\n";
    cout<<"\n Enter any of choices.\n";
    cout<<"\n 1 : Adding (inserting) node in BST.\n";
    cout<<"\n 2 : Deleting  node in BST.\n";
    cout<<"\n 3 : Print the whole BST .\n";
    cout<<"\n 4 : Quitting the Program.\n";

}
// -------------------------------------
void binSearchTree :: inOrder(node* temp){
    if(root == NULL){
        cout <<"Tree is empty" << endl;
        return;
    }
    if(temp->left != NULL){
        inOrder(temp->left);
    }
    cout << temp->info <<" ";
    if(temp->right != NULL){
        inOrder(temp->right);
    }
    return;
}
// -----------------------------------
void binSearchTree :: Delete(node* temp){
    if(temp == NULL){
        cout << "Tree is empty..\n";
        return;
    }
    if(temp->info > number){
        if(temp->left->info == number &&  temp->left->left != NULL && temp->left->right != NULL){
            temp->left->info = delSpecial(temp->left->right);
            return;
        }
        if(temp->left->info == number && temp->left->right == NULL){
        
            this->delptr = temp->left;
            temp->left = temp->left->left;
            delete this->delptr;
            this->delptr= NULL;
            return;
        }
        
        if(temp->left->info == number && temp->left->left == NULL){
            // node* delptr;
            this->delptr = temp->left;
            temp->left = temp->left->right;
            delete this->delptr;
            this->delptr= NULL;
            return;
        }
        if(temp->left->info == number && temp->left->left == NULL && temp->left->right == NULL){
            temp->left = NULL;
            return;
        }
         if(temp->left->info != number && temp->left->left == NULL && temp->left->right == NULL){
           cout << "Number not found... /n";
           return; 
        }
        if (temp->left->info != number)
        {
            Delete(temp->left);
            return;
        }
    }
    if(temp->info < number){
        if(temp->right->info == number &&  temp->right->left != NULL && temp->right->right != NULL){
            temp->right->info = delSpecial(temp->right->right);
            return;
        }
        if(temp->right->info == number && temp->right->right == NULL){
            this->delptr = temp->right;
            temp->right = temp->right->left;
            delete this->delptr;
            this->delptr= NULL;
            return;
        }
        
        if(temp->right->info == number && temp->right->left == NULL){
            // node* delptr;
            this->delptr = temp->right;
            temp->right = temp->right->right;
            delete this->delptr;
            this->delptr = NULL;
            return;
        }
        if(temp->right->info == number && temp->right->left == NULL && temp->right->right == NULL){
                temp->right = NULL;
                return;
        }
        if(temp->right->info != number && temp->right->left == NULL && temp->right->right == NULL){
           cout << "Number not found... /n";
           return; 
        }
        if(temp->right->info != number){
            Delete(temp->right);
            return;
        }

    }
}
int binSearchTree::delSpecial(node* temp){
    int Num;
    if(temp->left == NULL){
        Num = temp->info;
        this->delptr = temp;
        delete this->delptr;
        this->delptr = NULL;
        // temp = NULL;
    }
    else if(temp->left->left != NULL){
        Num = delSpecial(temp->left);
        
    }
    else{
        Num =  temp->left->info;    
        this->delptr = temp->left;
        if(temp->left->right != NULL){
            temp->left = temp->left->right;
        }
        delete this->delptr;
        this->delptr = NULL; 
    }
    return Num;
}