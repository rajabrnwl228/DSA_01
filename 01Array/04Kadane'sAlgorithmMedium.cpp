
// does not change the original array
long long maxSubarraySum(int arr[], int n)
{
    long long max = INT_MIN, temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp = temp + arr[i];
        if (temp > max)
        {
            max = temp;
        }
        if (temp < 0)
        {
            temp = 0;
        }
    }
    return max;
}

// change the original array
long long maxSubarraySum(int arr[], int n)
{

    // Your code here
    long long max = arr[0];
    long long temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        temp = arr[i] + arr[i - 1];
        if (temp > arr[i])
        {
            arr[i] = temp;
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
