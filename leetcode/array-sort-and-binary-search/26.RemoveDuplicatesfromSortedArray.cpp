

#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

// is it possible to speed this up by doing a kind of binary search in arrays with repetition?

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int count = 1;
        int n = nums.size();

        for (int idx = 1; idx < n; idx++)
            if (nums[idx] != nums[idx - 1])
                nums[count++] = nums[idx];

        return count;
    }
};

int main()
{
    // todo: add tests
    return 0;
}