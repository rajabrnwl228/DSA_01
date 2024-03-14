int wordLadderLength(string startword, string targetword, vector<string> &wordList)
{
    // Code here
    queue<pair<string, int>> q;
    unordered_set<string> st(wordList.begin(), wordList.end());
    q.push({startword, 1});
    st.erase(startword);
    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if (word == targetword)
            return steps;
        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (int j = 0; j < 26; j++)
            {
                if (word[i] == j + 'a')
                    continue;
                word[i] = j + 'a';
                if (st.find(word) != st.end())
                {
                    q.push({word, steps + 1});
                    st.erase(word);
                }
            }
            word[i] = original;
        }
    }
    return 0;
}