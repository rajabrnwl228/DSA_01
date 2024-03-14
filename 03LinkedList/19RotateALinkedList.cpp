 /* if constraint is
 1 <= k <= N
 then Method -1 is better else method-2
 */
 Node* rotate(Node* head, int k)
    {
        // Your code here
       Node *newhead=head;
        Node* first=head;
        Node* second=head;
        int count=0;
        while(first!=NULL){
            count++;
            if(k==count){
                if(first->next==NULL)
                {
                    first=new Node(-1);
                    break;
                }
                 newhead=first->next;
                 first->next=NULL;
                 first=newhead;
                 break;
            }
            first=first->next;
        }
        while(first->next!=NULL){
            first=first->next;
        }
        first->next=second;
        
        return newhead;
    }
//method-2
int length(Node* head){
        Node* temp=head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        int len=length(head);
        if(k>=len) 
            return head;
        Node *newhead=head;
        Node* first=head;
        Node* second=head;
        int count=0;
        while(first!=NULL){
            count++;
            if(k==count){
                 newhead=first->next;
                 first->next=NULL;
                 first=newhead;
                 break;
            }
            first=first->next;
        }
        while(first->next!=NULL){
            first=first->next;
        }
        first->next=second;
        
        return newhead;
    }
