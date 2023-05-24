#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        
        Node(){
            this->data =0;
            this->next = NULL;
            
        }
        
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
        
        //TODO:- write a destructor to delete the Node
        ~Node(){
            //write your code here
        }
};

//finding the length of the linked list
int findLength(Node* &head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }  
    return len;
}

//inserting node at the head
void insertAtHead(Node* &head, Node* &tail ,int data){
    
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode; tail = newNode; return;
    }
    //Step1:
    Node* newNode = new Node(data);
    //step2:
    newNode -> next = head;
    //step3:
    head = newNode;
}

//inserting node at tail
void insertAtTail(Node* &head,Node* &tail, int data){
    
    if(head == NULL){
        Node* newNode = new Node(data); 
        head = newNode; tail = newNode; return;
    }

    //step-1: create a new Node
    Node* newNode = new Node(data);
    
    //step-2: connect with tail Node
    tail->next = newNode;
    
    //step3: update tail
    tail = newNode;
    
}

//insert at any Position
void insertAtPosition(int position, Node* &head,Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    
    //step-1: find the position
    if(position == 0){
        //we want to insert at head
        insertAtHead(head,tail,data);
        return;
    }
    
    int len = findLength(head);
    
    if(position >= len){
        //if we want to insert at end
        insertAtTail(head,tail,data);
        return;
    }
    int i =1;
    Node* prev =head;
    while(i < position){
        prev = prev -> next;
        i++;
    }
    Node* curr = prev->next;
    
    //step-2: create a new Node
     Node* newNode = new Node(data);
     
     //step3:
     newNode -> next = curr;
     
     //step4:
     prev->next = newNode;
     
     
    
}
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << ' ';
        temp = temp->next;
    }
}
void deleteNode(int position, Node* &head, Node* &tail){
    if(head == NULL){
        cout << "Can't delete, LL is emplty";
        return;
    }
    
    if(position ==1){
        //if we want to delete first Node
        Node *temp = head;
        head = head -> next;
        temp->next = NULL;
        delete temp;
        return;
    }
    int len = findLength(head);
    
    if(position == len){
        //delete last Node
        
        int i = 1;
        Node* prev = head;
        while(i < position){
            prev = prev->next;
            i++;
        }
        prev->next = NULL;
        Node* temp = tail;
        tail = prev;
        delete temp;
        return;
    }

     //deleting the middle Node
    int i =1;
    Node* prev = head;
    while(i < position-1){
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;
    
    prev->next = curr -> next;
    curr->next = NULL;
    
    delete curr;
}

int main()
{
    
    // Node* first = new Node(10);
    // Node* second = new Node(20);
    // Node* third = new Node(30);
    // Node* fourth = new Node(40);
    // Node* fifth = new Node(50);
    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;
    Node* head = NULL; Node* tail = NULL;
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,60);
    insertAtHead(head,tail,90);
    insertAtTail(head,tail,77);  
    insertAtPosition(0,head,tail,101);
    deleteNode(6,head,tail);
    cout << "Printinf the linked list "<<endl;
    print(head);
    return 0;
}
