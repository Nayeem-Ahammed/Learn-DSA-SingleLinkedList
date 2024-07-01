// Everything of Single LinkedList
// provide by - Nayeem Ahammed

#include <bits/stdc++.h>
using namespace std;

// Node Definiation : use struct or class
struct Node{
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Convert Array to Linked List
Node* conv_Arr_to_LL(const vector <int>& a){
    Node* head = new Node(a[0]);
    Node* mover = head;
    for(int i=1; i<a.size(); ++i){
        Node* tmp = new Node(a[i]);
        mover->next = tmp;
        mover = tmp;
    }
    return head;
}

// print the Linked List
void print(Node* head){
    Node* tmp = head;
    while(tmp){
        cout << tmp->data << ' ';
        tmp = tmp->next;
    }
    cout << endl;
}

// Returen the size of Linked List
int LengthOfLL(Node* head){
    int cnt = 0;
    Node* tmp = head;
    while(tmp){
        tmp = tmp->next;
        cnt++;
    }
    return cnt;
}

// Search in Linked List
bool CheckIfPresent(Node* head, int val){
    Node* tmp = head;
    while(tmp){
        if(tmp->data == val) return true;
        tmp = tmp->next;
    }
    return false;
}

// delete the head
Node* deleteHead(Node* head){
    if(head == nullptr) return head;
    Node* tmp = head;
    head = head->next;
    delete tmp; // free(tmp);
    return head;
}
// remove the tail
Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while( temp->next->next ) temp = temp->next; // != nul
    free(temp->next);
    temp->next = nullptr;
    return head;
}
// deleting the kth element
Node* removeKth(Node* head, int k){
    if(head == NULL) return head;
    if(k == 1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    int cnt = 1;
    while(temp){
        if(cnt++ == k){
            prev -> next = prev -> next -> next;
            free(temp); 
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

// insert head
Node* insertHead(Node* head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    return newNode;
}
// insert at the end/ tail
Node* insertTail(Node* head, int data){
    Node* newNode = new Node(data);
    if(head == NULL) return newNode;

    Node* tmp = head;
    while(tmp->next) tmp = tmp->next;
    tmp->next = newNode;
    return head;
}
// insert at specific position
Node* insertKth(Node* head, int pos, int data){
    if(pos == 1) return insertHead(head, data);
    Node* newNode = new Node(data);
    int cnt = 1;
    Node* tmp = head;
    while(tmp) {
        cnt++;
        if(cnt == pos) {
            newNode->next = tmp->next;
            tmp->next = newNode;
            break;
        }
        tmp = tmp->next;
    }
    return head;
}
int main()
{
    // 1. Traversal
    // 2. Searching
    // 3. length
    // 4. Insertion : beginning, end, specific pos, val
    // 5. Deletion : beginning, end, specific pos, val

    vector <int> arr { 5, 3, 1, 7, 9};
    Node* head = conv_Arr_to_LL(arr);
    print(head);
    cout <<"Lenght of LL : " << LengthOfLL(head) << endl;
    if(CheckIfPresent(head, 7)) cout << "7 is present" << endl;
    else cout << "7 Not present" << endl;

    cout << "Linked List : "; print(head);
    head = deleteHead(head);
    cout << "After removing head : "; 
    print(head);

    head = removeTail(head);
    cout << "After removing Tail : "; 
    print(head);

    head = removeKth(head, 2);
    cout << "After removing 2nd : ";
    print(head);

    // insertion
    head = insertHead(head, 5);
    cout << "After inseting head at val 5 : ";
    print(head);

    head = insertTail(head, 9);
    cout << "After inserting tail at 9 : ";
    print(head);

    head = insertKth(head, 2, 15);
    cout <<"After inserting 3rd pos at 15 : ";
    print(head);
}
