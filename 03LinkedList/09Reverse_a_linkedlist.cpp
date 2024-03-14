#include "01Node.cpp"
// Mehtod 1 using curr prev and next node iteratively
Node *reverse(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head, *next = head;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
// Mehtod 1 using curr prev and next node recursively
Node* reverseHelper(Node* prev, Node* current) {
    if (current == nullptr) {
        return prev;
    }

    Node* next = current->next;
    current->next = prev;
    return reverseHelper(current, next);
}
Node* reverseLinkedListRecursive(Node* head) {
    return reverseHelper(nullptr, head);
}


//method 3 using recursion without curr prev and next
Node* reverseLinkedListRecursive(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* newHead = reverseLinkedListRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}