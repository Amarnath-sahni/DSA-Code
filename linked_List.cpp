/*insert at kth position ina singly linked list add a node at the end
#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node(int data){
        val = data;
        next = NULL;
    }

};
void insertAtHead(node* &head , int val){
    node* new_node = new node(val);
    new_node->next =head;
    head = new_node;
}
void insertAtTail(node* &head, int val){
    node* new_node =new node(val);
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}
void insertAtPosition(node* &head, int val, int pos){
    node* temp = head;
    int current_pos=0;
    while(current_pos!=pos - 1){
        temp = temp->next;
        current_pos++;
    }
}
void display(node* head){
    node* temp =head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head = NULL;
    insertAtHead(head,2);
    display(head);
    insertAtHead(head,1);
    display(head);
    insertAtTail(head ,3);
    display(head);

    insertAtPosition(head,4,1);
    display(head);
     return 0;


}


 void updatePosition(node* &head, int k, int val){
        node* temp = head;
        int curr_pos=0;
        while (curr_pos!= k)
        {
           temp = temp->next;
           curr_pos++;
        }//temp while is pointing to kth position
        temp->val=val; 
    }

    void deleteTail(node* &head){
        node* second_last=head;
        while (second_last->next->next!= NULL)
        {
          second_last=second_last->next->next;
        }
        node* temp = second_last->next;
        second_last->next = NULL;
        free(temp);
    }

    void deleteAtHead(node* &head){
        node* temp = head;
        head = head->next;
        free(temp);
    }

    void deleteAtArvetryconstent(node* &head, int pos){
        if(pos==0){
            deleteAtHead(head);
            return;
        }
        int curr_pos=0;
        node* prev=head;
        while (curr_pos!=pos-1){
            prev=prev->next;
            curr_pos++;
        }//prev pointing to node of pos-1
        node* temp = prev->next;//node to be delete
        prev->next= prev->next->next;
        free(temp);        
    }


    int main(){
        //node* n=new node(1);
       // cout<<n->val<<" "<<n->next;
       node* head=NULL;
       insertAtHead(head,1);
        insertAtHead(head,2);
         insertAtHead(head,3);
          insertAtHead(head,4);
       diplay(head);
       insertAtTail(head,9);
       insertAtTail(head,8);
       insertAtTail(head,7);
       diplay(head);
       insertAtArveryconstent(head,9,3);
       diplay(head);
       updatePosition(head,2,10);
       updatePosition(head,1,7);updatePosition(head,0,5);updatePosition(head,3,6);
       diplay(head);
       deleteTail(head);
        diplay(head);
        deleteAtHead(head);
        diplay(head);

        deleteAtArvetryconstent(head,1);
        diplay(head);
         deleteAtArvetryconstent(head,3);
        diplay(head);
        return 0;
    }*/





    /*q1. given the head of linked list, delete every alternating element from the linked list shorting from the second element.
   
   #include<iostream>
   using namespace std;
   class node{
    public:
    int val;
    node*next;
    node(int data){
        val=data;
        next=NULL;
    }
   };
   class linkedlist{
    public:
    node* head;
    linkedlist(){
        head = NULL;
    }
    void insertAtTail(int val){
        node* new_node = new node(val);
        if(head==NULL){//linked list are empty
        head= new_node;
        return;
        }
        node* temp = head;
        while (temp->next!=NULL){
        temp= temp->next;
        }
       temp->next=new_node; 
    }


    void display(){
        node* temp =head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<"null";
    }
   };

 void DeleteAlternatingElemet(node* &head){
    node* curr_node = head;
    while (curr_node!=NULL && curr_node->next!=NULL) {
        node* temp = curr_node->next;
        curr_node->next = curr_node->next->next;
        free(temp);
        curr_node = curr_node->next;
    } cout<<endl; 
   }

   void insertDupplicateelement(node* &head){
         node* curr_node = head;
        while(curr_node!=NULL){
            while(curr_node->next && curr_node->val == curr_node->next->val){//delet elemernt
            node* temp = curr_node->next;
            curr_node->next = curr_node->next->next;
            free(temp);
            }
            curr_node = curr_node->next;
        }
    }

   int main(){
    linkedlist ll;
    ll.insertAtTail(1);
     ll.insertAtTail(2);
      ll.insertAtTail(2);
       ll.insertAtTail(3);
        ll.insertAtTail(3);
        ll.insertAtTail(3);
        ll.display();
       // DeleteAlternatingElemet(ll.head);
       // ll.display();
        insertDupplicateelement(ll.head);                                                                         
        ll.display();
    return 0;
   } */


   /* pettern: deleting element from singly linkedlist
   q2.given head of a shorted linkedlist, detet all duplicates such that each each element appears only once. return the linkedlist
   shorted as well 

  #include<iostream> 
  using namespace std;

class node{
    public:
    int val;
    node* next;
    node(int data){
        val=data;
        next=NULL;
    }
};
class linkedlist{
    public:
    node* head;
    linkedlist(){
         head = NULL;
    }
    void insertAtTail(int val){
        node* new_node= new node(val);
        if(head==NULL){
            head=new_node; 
            return;
        }
        node* temp = head;
        while(temp->next!=NULL){ 
            temp = temp->next;
        }
         temp->next = new_node;
    }

    void display(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
// delete dupplicate element in assending order
void insertDupplicateelement(node* &head){
        node* curr_node = head;
        while(curr_node){
            while(curr_node->next && curr_node->val == curr_node->next->val){
            node* temp = curr_node->next;
            curr_node->next = curr_node->next->next;
            free(temp);
            }
            curr_node = curr_node->next;
        }
    }
    //recrssive through solve this reversing order
void reversePrint(node* &head){
    if(head == NULL){
        return;
    }
    //recursive case
    reversePrint(head->next);
    cout<<head->val;
}
//reverse element through the linked list
node* revesethroughl(node* &head){
    node* prevptr = NULL;
    node* currptr =head;
    //currptr next =prevptr;
    //move all 3 ptrs by one step ahead
    while(currptr!=NULL){
       node* nextptr = currptr -> next;
       currptr->next=prevptr;
       prevptr=currptr;
       currptr=nextptr;
    }
    //when this loop end, prevptr pointing to my last node which is new head
    node* new_head = prevptr;
    return new_head;
}

 bool bothlinkedlistequal(node* head1, node* head2){
    node* ptr1 = head1;
    node* ptr2 = head2;
    while(ptr1!= NULL && ptr2!=NULL){
if(ptr1->val!= ptr2->val){
    return false;
}
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return(ptr1==NULL && ptr2==NULL);
 }
// int getlength(node* head){
//     node* temp = head;
//     int length =0;
//     while(temp!=NULL){
//         length++;
//         temp=temp->next;
//     }
//     return lenght;
// }
//  node* getinterset(node* head1, node* head2){
//     int l1 = getlength(head1);
//     int l2 = getlength(head2);
//     //calculate the both link list 
//     //step2->find diffent k between linkedlist and move longer linkedlist ptr by k steps
//  node* ptr, ptr2;
//  if(l1>l2){
//     int k= l1-l2;
//     ptr1 = moveheadbyk(head1, k);
//     ptr = head2;
//  }else{
//     int k= l2-l1;
//     ptr2 = moveheadbyk(head1, k);
//     ptr = head2;
//  }
//  while(ptr1){
//     if(ptr1==ptr2){
//         return ptr1;
//     }ptr1 = ptr1->next;
//     ptr2 = ptr2->next;
//  }
//  return NULL;
 
//  }
  int main(){
    node* head = NULL;
    linkedlist ll1;
     ll1.insertAtTail(1);
   ll1.insertAtTail(1);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(4);
    ll1.insertAtTail(6);
   ll1.display();
   linkedlist ll2;
     ll2.insertAtTail(1);
   ll2.insertAtTail(1);
    ll2.insertAtTail(3);
    ll2.insertAtTail(4);
    ll2.insertAtTail(4);
    ll2.insertAtTail(6);
   ll2.display();
   //reversePrint(ll.head);
   //ll.display();
//insertDupplicateelement(ll.head);
//ll.display();
//ll.head=revesethroughl(ll.head);
//ll.display();
cout<<bothlinkedlistequal(ll1.head, ll2.head);
    return 0;
  }*/

//   #include<iostream>
// using namespace std;
// class node{
// public:
// int val;
// node* next;
// node(int data){
//     val = data;
//     next = NULL;
// }
// };
// void insertAtHead(node* &head, int val){
//     node* new_node = new node(val);
//     new_node->next = head;
//     head = new_node;
// }
//  void insertAtTail(node* &head, int val){
//     node* new_node = new node(val);
//     if(head == NULL){
//         head = new_node;
//         return;
//     }
//     node* temp =head;
//     while(temp->next!=NULL){
//         temp = temp->next;
//     }
//     new_node->next = head;
//  }
//  void display(node* head){
//     node* temp = head;
//     while(temp!=NULL){
//         cout<<temp->val<<" ";
//         temp= temp->next;
//     }
//     cout<<" NULL\n";
//  }
//  void insertkposition(node* &head, int val, int pos){
//    if(pos==0){
//     node* new_node = new node(val);
//     new_node->next = head;
//     head = new_node;
//     return;
//    }
//    node* new_node = new node(val);
//    node* temp = head;
//    int curr_pos = 0;
//    while(curr_pos!= pos-1){
//     temp = temp->next;
//     curr_pos++;
//    }
//    new_node->next = temp->next;
//    temp->next = new_node;
//  }
// void deleteLastNode(node* &head){
//    node* second_last = head;
//    while (second_last->next->next!=NULL)
//    {
//     second_last = second_last->next;
//    }
//    node* temp = second_last->next; //this element is deleted
//    second_last->next = NULL;
//    free(temp);
// }
// void deleteInStarting(node* &head){
//     node* temp = head;
//     head = head->next;
//     free(head);
// }
// //deleting element any postion of given linkedlists
// void deleteAnyPostion(node* &head, int pos){
//     if(pos==0){
//         deleteInStarting(head);
//         return;
//     }
//     int curr_pos=0;
//     node* prev = head;
//     while(curr_pos!= pos-1){
//         prev = prev->next;
//         curr_pos++;
//     }
//     node* temp = prev->next;
//     prev->next = prev->next->next;
//     free(temp);
// }
// int main(){
//     node* head = NULL;
//     insertAtHead(head, 1);
//     insertAtHead(head, 2);
//     insertAtHead(head, 3);
//     insertAtHead(head, 4);
//     display(head);
//     insertAtTail(head, 1);
//     insertAtTail(head, 2);
//     insertAtTail(head, 3);
//     insertAtTail(head, 4);
// display(head);
// // insertkposition(head,10,0);
// // display(head);
// // deleteLastNode(head);
// // display(head);
// // deleteInStarting(head);
// // display(head);
// deleteAnyPostion(head,2);                              
// display(head);
//     return 0;
// }
