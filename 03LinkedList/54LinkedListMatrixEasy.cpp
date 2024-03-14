Node *helper(int i, int j, Node *temp, int mat[MAX][MAX], int n)
{
    if (i < n && j < n - 1)
    {
        temp->right = new Node(mat[i][j + 1]);
        helper(i, j + 1, temp->right, mat, n);
    }
    if (i < n - 1 && j < n)
    {
        temp->down = new Node(mat[i + 1][j]);
        helper(i + 1, j, temp->down, mat, n);
    }
    return temp;
}
Node *constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    // code here
    Node *temp = new Node(mat[0][0]);
    Node *ans = temp;
    helper(0, 0, temp, mat, n);

    return ans;
}