// Learn abort all of doubley LinkedList
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

// Array to Doubly LinkedList
Node* ArrayToDoublyLL (vector <int> a) {
    Node* head = new Node(a[0]);
    Node* mover = head;
    for(int i = 1; i < a.size(); ++i) {
        Node* tmp = new Node (a[i]);
        mover -> next = tmp;
        tmp -> prev = mover;
        mover = tmp;
    }
    return head;
}
// Print the DLL
void print (Node* head) {
    Node* tmp = head;
    while (tmp) {
        cout << tmp->data << ' ';
        tmp = tmp->next;
    }
    cout << endl;
}
// Insertion at the Beginning
Node* insertion_beginning(Node* head, int data) {
    Node* tmp = new Node (data);
    if(head != NULL) {
        tmp->next = head;
        head->prev = tmp;
    }  
    return tmp;
}
// Insertion at the end
Node* insertion_end(Node* head, int data) {
    Node* tmp = new Node (data);
    if(head == NULL) return tmp;

    Node* mover = head;
    while (mover->next) mover = mover->next;
    mover->next = tmp;
    tmp->prev = mover;
    return head;
}
// Insertion at the kth possition
Node* insertion_kth_pos(Node* head, int pos, int data) {
    Node* tmp = new Node(data);
    if(pos == 1) return insertion_beginning(head, data);

    Node* mover = head;
    int cnt = 1;
    while (mover->next and cnt < pos-1) {
        mover = mover -> next;
        cnt++;
    }
    
    if(cnt == pos-1) {
        tmp->next = mover->next;
        mover->next = tmp;
        tmp->prev = mover;
        if(tmp->next) tmp->next->prev = tmp;
    }
           
    return head;
}

// Deletion at the beginning
Node* deletion_fist(Node* head) {
    head = head->next;
    free(head->prev);
    head->prev = NULL;
    return head;
}
// Deletion at the end
Node* deletion_last(Node* head) {
    Node* tmp = head;
    while (tmp->next->next) tmp = tmp->next;
    free(tmp->next);
    tmp->next = NULL;
    return head;
}
// Deletion kth pos
Node* deletion_kth_pos (Node* head, int pos) {
    if(head == NULL or pos <= 0) return head;

    int cnt = 1;
    Node* tmp = head;
    while (tmp and cnt < pos) {
        tmp = tmp->next;
        cnt++;
    }
    // if pos is more than the number of nodes
    if(tmp == NULL) return head;

    if(tmp == head) {
        head = head->next;
        if(head) head->prev = NULL;
    }
    else {
        if(tmp->next) tmp->next->prev = tmp->prev;
        if(tmp->prev) tmp->prev->next = tmp->next;
    }
    free(tmp);
    return head;
}
int main()
{
    // 1. insertion
    // 2. deletation
    vector <int> a { 2, 3, 4};
    Node* head = ArrayToDoublyLL(a);
    cout << "Array to Doubly LL:  "; 
    print(head);
    
    // Insertion
    head = insertion_beginning(head, 1);
    cout << "Insertion at the beginning 1:  ";
    print(head);
    head = insertion_end(head, 5);
    cout << "Insertion at the end 5:  ";
    print(head);
    head = insertion_kth_pos(head, 5, 9);
    cout << "Insertion at kth pos :  ";
    print(head);

    // Deletion
    head = deletion_fist(head);
    cout << "After delete the 1st : ";
    print(head);
    head = deletion_last(head);
    cout << "After delete the end : ";
    print(head);
    head = deletion_kth_pos(head, 3);
    cout << "After delete kth : ";
    print(head);
    
}
