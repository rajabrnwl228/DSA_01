#include "01Node.cpp"
int getNthFromLast(Node *head, int n)
{
    if(head==NULL){
        return -1;
    }
    int len=0;
    Node* temp1=head;
    while(temp1!=NULL){
        len++;
        temp1=temp1->next;
    }
    if(len<n)
        return -1;
        
    Node*temp=head;
    int count=0;
    while(temp!=NULL){
        if(count==len-n)
        {
            return temp->data;
        }
        count++;
        temp=temp->next;
    }
}