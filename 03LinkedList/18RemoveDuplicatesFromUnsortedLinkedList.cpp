    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     unordered_map<int,int>mp;
     Node* curr=head;
     Node* prev=new Node(-1);
     Node* newhead=prev;
     while(curr!=NULL){
         if(mp.count(curr->data)>0){
         while(curr!=NULL && mp.count(curr->data)>0){
                curr=curr->next;
             }
             if(curr!=NULL)
             mp[curr->data]=1;
             prev->next=curr;
             prev=prev->next;
         }
         else{
             mp[curr->data]=1;
             prev->next=curr;
             prev=prev->next;
             curr=curr->next;
             
         }
     }
     
     return newhead->next;
    }