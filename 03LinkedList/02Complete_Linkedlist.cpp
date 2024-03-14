#include<iostream>
#include "01Node.cpp"
using namespace std;
Node* takeInput()
{
  int data;
  cin >> data;
  Node *head = NULL;
  Node *tail = NULL;
  while (data != -1)
  {
    Node *newNode = new Node(data);
    if (head == NULL)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      tail->next = newNode;
      tail = newNode; // tail=tail->next;
    }
    cin >> data;
  return head;
}
}
Node* Insert(Node *head, int data, int pos){
    Node *newNode = new Node(data);
    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    int count = 1;
    Node *temp = head;
    while (temp != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if(temp==NULL){
       cout<<"Enter the correct position !"<<endl;
    }
    else{
    newNode->next=temp->next;
    temp->next=newNode;
    }
    return head;

} 
void print(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout<<endl;
  return ;
}
