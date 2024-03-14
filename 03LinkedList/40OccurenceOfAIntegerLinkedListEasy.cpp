int count(struct node *head, int search_for)
{
    // add your code here
    node *temp = head;
    int ans = 0;
    while (temp != NULL)
    {
        if (temp->data == search_for)
            ans++;
        temp = temp->next;
    }
    return ans;
}