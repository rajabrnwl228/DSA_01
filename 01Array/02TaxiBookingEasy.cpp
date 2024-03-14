int minimumTime(int N, int cur, vector<int> &pos, vector<int> &time)
{
    int min = INT_MAX, sub = 0, abpos = 0;
    for (int i = 0; i < N; i++)
    {
        if (pos[i] > cur)
            abpos = pos[i] - cur;
        else
        {
            abpos = cur - pos[i];
        }
        sub = abpos * time[i];
        if (min > sub)
            min = sub;
    }
    return min;
}