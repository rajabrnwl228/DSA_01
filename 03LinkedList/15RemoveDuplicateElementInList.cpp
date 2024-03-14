#include"01Node.cpp"
Node *removeDuplicates(Node *head)
{
 // your code goes here
 Node* temp=head;
 while(temp!=NULL){
    while(temp->next!=NULL && temp->data==temp->next->data){
         temp->next=temp->next->next;
    }
    temp=temp->next;
 }
     return head;
}