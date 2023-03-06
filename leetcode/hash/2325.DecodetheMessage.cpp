
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

class Solution
{
public:
    string decodeMessage(string key, string message)
    {
        char decode[256];

        memset(decode, 0, 256 * sizeof(char));
        char current_letter = 'a';

        for (size_t i = 0; i < key.size(); i++)
        {
            char c = key[i];
            if (c == ' ')
                continue;
            if (decode[(int)c] == 0)
            {
                decode[(int)c] = current_letter;
                current_letter++;
            }
        }

        decode[' '] = ' ';

        string output;
        for (size_t i = 0; i < message.size(); i++)
            output += decode[(int)message[i]];

        return output;
    }
};

int main()
{
    // todo: add tests
    return 0;
}