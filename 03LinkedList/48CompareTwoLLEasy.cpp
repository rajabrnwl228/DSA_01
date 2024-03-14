int compare(Node *list1, Node *list2)
{
    // Code Here
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->c > list2->c)
            return 1;
        else if (list1->c < list2->c)
            return -1;
        list1 = list1->next;
        list2 = list2->next;
    }
    return 0;
}