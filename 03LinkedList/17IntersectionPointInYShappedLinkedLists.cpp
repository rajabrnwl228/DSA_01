int len(Node* head){
    int len=0;
    Node*curr=head;
    while(curr!=NULL){
        curr=curr->next;
        len++;
    }
    return len;
}
//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node* tehead1=head1;
    Node* tehead2=head2;
    int head1len=len(tehead1);
    int head2len=len(tehead2);
    while(head1len>head2len){
        head1len--;
        tehead1=tehead1->next;
    }
    while(head2len>head1len){
        head2len--;
        tehead2=tehead2->next;
    }
    int ans=-1;
    while(tehead1!=NULL&&tehead2!=NULL){
        if(tehead1==tehead2){
             ans=tehead1->data;
             break;
        }
         
         tehead1=tehead1->next;
         tehead2=tehead2->next;
    }
    return ans;
    
}