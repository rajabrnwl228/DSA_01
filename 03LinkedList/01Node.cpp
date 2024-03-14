#include<iostream>
using namespace std;
class Node {
    public:
        int data;
        Node *next;

    Node(int data){
        this->data=data;
        this->next=NULL;

    }
    /*by default delete will just delete the data in heap pointed by node pointer
    and it will not break the link
    due to which any deleted node can still access the other node through link
    */

    /* Method-1  To delete only one node data and break the link through that node so that deleted node cannot access the list.
    In this destructor we don't need to point the next pointer of the node to NULL, "manually", before calling delete node 
     */
    //  ~Node(){
    //     if(this->next!=NULL)
    //         this->next=NULL;
    // }

    //it will delete all nodes till null
    ~Node(){
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        } 
    }

};
