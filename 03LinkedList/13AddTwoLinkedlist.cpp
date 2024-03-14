    Node* reverse(Node *head){
        Node* prev=NULL;
        Node* next=NULL;
        Node* curr=head;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {        
        Node* revfirst=reverse(first);
        Node* revsecond=reverse(second);
        
        //add two linkedlist
        Node* rev1=revfirst;
        Node* rev2=revsecond;
        Node* newhead=NULL;
        Node* newtail=NULL;
        int carry=0;
        while(rev1!=NULL && rev2!=NULL){
            int a=rev1->data;
            int b=rev2->data;
            int c=a+b+carry;
            carry=c/10;
            Node* newnode=new Node(c%10);
            if(newhead==NULL){
                newhead=newnode;
                newtail=newnode;
            }
            else{
                newtail->next=newnode;
                newtail=newnode;
            }
            rev1=rev1->next;
            rev2=rev2->next;
            
        }
        while(rev1!=NULL){
            int a=rev1->data;
            int c=a+carry;
            carry=c/10;
            Node* newnode=new Node(c%10);
            newtail->next=newnode;
            newtail=newnode;
            rev1=rev1->next;
            
        }
        while(rev2!=NULL){
            int a=rev2->data;
            int c=a+carry;
            carry=c/10;
            Node* newnode=new Node(c%10);
            newtail->next=newnode;
            newtail=newnode;
            rev2=rev2->next;
            
        }
         if(carry!=0){
            Node* newnode=new Node(carry);
            newtail->next=newnode;
            newtail=newnode;
             
         }   
        first=reverse(revfirst);
        second=reverse(revsecond); 
        newhead=reverse(newhead);
        return newhead;
    }