
#include <iostream>
#include <vector>
#include <stdarg.h>
#include <climits>

using namespace std;

#define max(x, y) ((x > y) ? (x) : y)

class Solution
{
public:
    int maxProduct(vector<int> nums)
    {
        int prd = 1;
        int max_prod = INT_MIN;

        for (size_t i = 0; i < nums.size(); i++)
        {
            prd *= nums[i];

            if (prd > max_prod)
                max_prod = prd;

            if (prd == 0)
                prd = 1;
        }

        prd = 1;

        for (long i = nums.size() - 1; i >= 0; i--)
        {
            prd *= nums[i];

            if (prd > max_prod)
                max_prod = prd;

            if (prd == 0)
                prd = 1;
        }

        return max_prod;
    }
};

int main()
{
    Solution s;

    printf("0 - %d\n", s.maxProduct(vector<int>{-2, 0, -2}));
    printf("30 - %d\n", s.maxProduct(vector<int>{-5, 2, 1, 3, 0, -2, 3, 10}));
    printf("24 - %d\n", s.maxProduct(vector<int>{-2, 3, -4}));
    printf("6 - %d\n", s.maxProduct(vector<int>{-2, -2, 1, -3}));
    printf("36 - %d\n", s.maxProduct(vector<int>{-2, -2, 1, -3, -3}));
    printf("4 - %d\n", s.maxProduct(vector<int>{-2, 0, -2, -2, 0, 3}));
    printf("4 - %d\n", s.maxProduct(vector<int>{3, -2, 0, -2, -2, 0, 3}));
    printf("3 - %d\n", s.maxProduct(vector<int>{0, 3, -1}));

    return 0;
}