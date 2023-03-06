#include <assert.h>
#include <string>
#include <vector>

using namespace std;

class Solution
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

    return 0;
}