#include <assert.h>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class NaiveSolution
{
public:
    vector<string> all_subseqs(string text)
    {
        vector<string> v;

        for (size_t i = 0; i < text.size(); i++)
        {
            size_t n = v.size();

            for (size_t j = 0; j < n; j++)
            {
                string s = string(v[j]);
                s.push_back(text[i]);
                v.push_back(s);
            }

            string s = "";
            s.push_back(text[i]);
            v.push_back(s);
        }

        return v;
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        size_t max_size = 0;

        vector<string> v1 = all_subseqs(text1);
        vector<string> v2 = all_subseqs(text2);

        for (size_t i = 0; i < v1.size(); i++)
            for (size_t j = 0; j < v2.size(); j++)
                if ((v1[i] == v2[j]) && (v1[i].size() > max_size))
                    max_size = v1[i].size();

        return max_size;
    }
};

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int subseq_length[text1.size()][text2.size()];

        memset(subseq_length, 0, text1.size() * text2.size() * sizeof(int));

        for (size_t i = 0; i < text1.size(); i++)
        {
            for (size_t j = 0; j < text2.size(); j++)
            {
                if (text1[i] == text2[j])
                {
                    int val = 0;

                    if (i > 0 && j > 0)
                        val = subseq_length[i - 1][j - 1];

                    subseq_length[i][j] = val + 1;
                }
                else
                {
                    int prev_i = (i > 0) ? subseq_length[i - 1][j] : 0;
                    int prev_j = (j > 0) ? subseq_length[i][j - 1] : 0;
                    subseq_length[i][j] = max(prev_i, prev_j);
                }
            }
        }

        return subseq_length[text1.size() - 1][text2.size() - 1];
    }
};

class Solution2
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int length1 = text1.length();
        int length2 = text2.length();
        vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));
        for (int i = 1; i <= length1; i++)
        {
            for (int j = 1; j <= length2; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[length1][length2];
    }
};

int main()
{
    Solution s;

    assert(s.longestCommonSubsequence("abcde", "ace") == 3);
    assert(s.longestCommonSubsequence("abc", "abc") == 3);
    assert(s.longestCommonSubsequence("abc", "def") == 0);
    assert(s.longestCommonSubsequence("ace", "abcde") == 3);
    assert(s.longestCommonSubsequence("ab", "abababa") == 2);
    assert(s.longestCommonSubsequence("abacad", "aa") == 2);
    assert(s.longestCommonSubsequence("abacad", "aaa") == 3);
    assert(s.longestCommonSubsequence("zabacad", "aaa") == 3);
    assert(s.longestCommonSubsequence("zabacad", "aaaa") == 3);
    assert(s.longestCommonSubsequence("aaaa", "zabacad") == 3);
    assert(s.longestCommonSubsequence("lajjatarr", "zabacad") == 3);
    assert(s.longestCommonSubsequence("lajjatarr", "zabacadr") == 4);
    assert(s.longestCommonSubsequence("lajjatarr", "zabjacadr") == 5);
    assert(s.longestCommonSubsequence("abcde", "cabdf") == 3);
    assert(s.longestCommonSubsequence("abcde", "cabdfde") == 4);

    return 0;
}