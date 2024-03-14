 Node* reverse(Node* head){
        Node* prev=NULL, *next=NULL,*curr=head;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node * rev=reverse(head);
        Node * t=rev;
        int carry=1;
        while(rev!=NULL&&carry!=0){
            int a=rev->data;
            a=a+carry;
            carry=a/10;
            rev->data=a%10;
            rev=rev->next;
        }
        rev=reverse(t);
        if(carry!=0){
            Node* newnode=new Node(carry);
            newnode->next=rev;
            rev=newnode;
        }
        return rev;
        
    }