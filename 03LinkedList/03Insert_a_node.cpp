#include<iostream>
using namespace std;
//for rename typedef
class Node {
    public:
        int data;
        Node *next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        if(this->next!=NULL){
    //         delete next;
            this->next=NULL;
        } 
    }
};

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
int main(){
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(4);
    a->next=b;
    b->next=c;
    print(a);
    a=Insert(a,0,1);
    print(a);
    a=Insert(a,3,4);
    print(a);
    a=Insert(a,5,6);
    print(a);
    a=Insert(a,6,8);
    print(a);
    return 0;

}
