
#include <cstring>
#include <ctype.h>
#include <string>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int st = 0;
        int end = s.size() - 1;

        while (st < end)
        {
            if (!isalnum(s[st]))
                st++;
            else if (!isalnum(s[end]))
                end--;
            else if (tolower(s[st]) != tolower(s[end]))
                return false;
            else
            {
                st++;
                end--;
            }
        }

        return true;
    }
};

int main()
{
    // add tests
    return 0;
}