#include  <iostream> 

struct Node {
  int data;
  Node* next;
};

void insertAtBeginning(Node*& head, int data) {
  Node* newNode = new Node{data};
  newNode -> next = head;
  head = newNode;
}

void insertAtMiddle(Node*& head, int data) {
  if (head == nullptr) {
    head = new Node{data, nullptr};
    return;
  }

  Node* slow = head;
  Node* fast = head-> next;  // Start fast one node ahead for even-length adjustment

  while (fast != nullptr && fast-> next != nullptr) {
    slow = slow-> next;
    fast = fast-> next-> next;
  }

  Node* newNode = new Node{data};
  newNode-> next = slow-> next;
  slow-> next = newNode;
}

void insertAtEnd(Node*& head, int data) {
  Node* newNode = new Node{data};
  newNode-> next = nullptr;

  if (head == nullptr) {
    head = newNode;
    return;
  }

  Node* current = head;
  while (current-> next != nullptr) {
    current = current-> next;
  }

  current-> next = newNode;
}

int main() {
  Node* head = nullptr;

  insertAtBeginning(head, 30);
  insertAtBeginning(head, 20);
  insertAtBeginning(head, 10);

  Node* current = head;
  std::cout  <<  "List after inserting at the beginning: ";
  while (current != nullptr) {
    std::cout  <<  current-> data  <<  " ";
    current = current-> next;
  }
  std::cout  <<  std::endl;
  
 
  insertAtMiddle(head, 60);
  
  current = head;
  std::cout  <<  "List after inserting in the middle: ";
  while (current != nullptr) {
    std::cout  <<  current-> data  <<  " ";
    current = current-> next;
  }
  std::cout  <<  std::endl;

  insertAtEnd(head, 40);

  current = head;
  std::cout  <<  "List after inserting at the end: ";
  while (current != nullptr) {
    std::cout  <<  current-> data  <<  " ";
    current = current-> next;
  }
  std::cout  <<  std::endl;

  // Memory cleanup (to prevent memory leaks)
  while (head != nullptr) {
    Node* temp = head;
    head = head-> next;
    delete temp;
  }

 /* //-----------------------------------------------------------
*/ //---------------------------------------------------------------
  return 0;
}