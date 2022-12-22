#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node* previous;

        node(int val){
            data = val;
            next = NULL;
            previous = NULL;
        }
};
void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    if(head != NULL){
        head->previous = n;
    }
    head = n;
}
void insertionAtTail(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        insertAtHead(head,val);
        return;
    }
    node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = n;
    n->previous = curr;
}
void deleteAtHead(node* &head){
    node* temp = head;
    head = head->next;
    head->previous = NULL;
    delete temp; temp = NULL;

}
void deletion(node* &head, int pos){
    if(head == NULL){
        cout << " list is empty";
        return;
    }
    if(pos == 1){
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    int count = 1;
    while(temp != NULL && count != pos){
        temp = temp->next;
        count++;
    }
    
    temp->previous->next = temp->next;
    if(temp->next != NULL){
            temp->next->previous = temp->previous;

    }

    delete temp; temp = NULL;

}
int length(node* head){
    node* curr = head;
    int l = 0;
    while(curr != NULL){
        l++;
        curr = curr->next;
    }
    return l; 
}
node* lastKNodes(node* &head, int k){
    node* curr = head;
    int count = 0;
    node* newTail = NULL;
    node* newHead = NULL;
    int l = length(head);
    k = k%l;
    while(curr->next != NULL ){
       
        if ( count == (l-k-1)){
            newTail = curr;
            newHead = curr->next;
        }
        curr = curr->next;
        count++;
    }
    newTail->next = NULL;
    curr->next = head;
    return newHead;
}
//================== intersect =============================
void intersect(node* &head1, node* &head2,int pos){
    node* temp1 = head1;
    pos--;
    while(pos--){
        temp1 = temp1->next;
    }
    node* temp2 = head2;
    while(temp2->next !=NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

//===========insertion point of 2 linked list====================
 int intersection(node* &head1, node* &head2){
    int l1 = length(head1);
    int l2 = length(head2);
    int d= 0;
    // cout << "len" << l1 << " " << l2 << endl;
    node* longLength;
    node* shortLength;

    if(l1>l2){
        d = l1-l2;
        longLength = head1;
        shortLength = head2;
    }
    else
    {
        d = l2 - l1;
        longLength = head2;
        shortLength = head1;
    }
    while(d){
        longLength = longLength->next;
        if(longLength  == NULL){
            return -1;
        }
        d--;
    }
    // cout <<"hell" <<longLength->data;
    while(longLength != NULL && shortLength != NULL){
        if(longLength == shortLength){
            return longLength->data;
        }
        longLength = longLength->next;
        shortLength = shortLength->next;
    }
    return -1;
 }
//  ====================================================================
//==========mergining two sorted linked list=================
node* merge(node* &head, node* &head1){
    node* p1 = head;
    node* p2 = head1;
    node* dummyNode = new node(-1);
    node* p3 = dummyNode;
    while (p1!=NULL && p2!=NULL){
        if(p1->data < p2->data){
            p3->next = p1;
            p1 = p1->next;
        }
        else{
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    while(p1!=NULL){
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
     }
    while(p2!=NULL){
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
}
    return dummyNode->next;  
}

// ========== merging sorted linked list recursive way ===================
node* mergeRecursive(node* &head, node* &head1){
    if(head == NULL){
        return head1;
    }
    if(head1 == NULL){
        return head;
    }
    node* result;
    if(head->data < head1->data){
        result = head;
        result->next = mergeRecursive(head->next,head1);
    }
    else{
        result = head1;
        result->next = mergeRecursive(head, head1->next);
    }
    return result;
}
// ===========put even postion nodes after  odd position nodes========
void evenAfterOdd(node* &head){
     node* odd = head;
     node* even = head->next;
     node* evenStart = even;
     while(odd->next != NULL && even->next!= NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even  = even->next;
     }
     odd->next = evenStart;
     if(odd->next != NULL){
        even->next = NULL;
     }
}
void print(node* head ){
    node* curr = head;

    while(curr != NULL){
        cout<< curr->data <<"-->";
        curr = curr->next;
    }
    cout <<"NULL" << endl;
}

int main(){
    node* head = NULL;
    node* head2 = NULL;
    // print(head);
    // insertionAtTail(head, 1);
    // insertionAtTail(head, 2);
    // insertionAtTail(head, 3);
    // insertionAtTail(head, 4);
    // insertionAtTail(head, 5);
    // insertionAtTail(head, 6);
    // insertionAtTail(head2, 9);
    // insertionAtTail(head2, 10);
    // print(head);
    // ==========intersect==============
    // intersect(head,head2,6);
    // print(head);
    // print(head2);

    // ================intersection=============
    // int value = intersection(head,head2);
    // cout<<value;
    // deletion(head,1);
    // deleteAtHead(head);
    // print(head);
    // node* newHead = lastKNodes(head, 11);
    // print(newHead);  
    // int arr1[] = {1,4,5,7};
    // int arr2[] = {2,3,6,9};
    // for(int i = 0; i < 4;i++){
    //     insertionAtTail(head, arr1[i]);
    // }
    // for(int i = 0; i < 4;i++){
    //     insertionAtTail(head2, arr2[i]);
    // }
    // print(head);
    // print(head2);
    // node* newHead = mergeRecursive(head, head2);
    // print(newHead); 
    /// even ofter odd==================
    int arr1[] = {1,2,3,4,5,6};
    for(int i = 0; i < 4;i++){
        insertionAtTail(head, arr1[i]);
    }
    print(head);
    evenAfterOdd(head);
    print(head);
}