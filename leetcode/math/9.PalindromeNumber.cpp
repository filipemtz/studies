

#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

class NaiveSolution
{
public:
    bool isPalindrome(int x)
    {
        vector<unsigned char> digits;

        if (x < 0)
            return false;

        do
        {
            digits.push_back(x % 10);
            x = x / 10;

        } while (x != 0);

        for (int i = 0; i < digits.size() / 2; i++)
            if (digits[i] != digits[digits.size() - 1 - i])
                return false;

        return true;
    }
};

class SolutionExtractingDigits
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        if (x == 0)
            return true;

        int e = log10(x);
        int p = pow(10, e);

        while (e > 0)
        {
            int q = x / p;

            if ((x % 10) != q)
                return false;

            x -= q * p;
            x /= 10;
            p /= 100;
            e -= 2;
        }

        return true;
    }
};

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // the fastest solution in leetcode uses this approach, but when
        // I submitted it, it was slower than the previous...
        if (x < 0)
            return false;

        int extractor = x;
        long int reversed = 0;

        do
        {
            reversed = reversed * 10 + (extractor % 10);
            extractor /= 10;
        } while (extractor != 0);

        return (reversed == x);
    }
};

int main()
{
    // todo: add tests
    return 0;
}