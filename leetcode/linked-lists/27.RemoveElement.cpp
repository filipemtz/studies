
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int last = nums.size() - 1;

        for (int i = 0; i < nums.size(); i++)
        {
            while ((nums[i] == val) && (last >= i))
            {
                swap(nums[i], nums[last]);
                last--;
            }
        }

        return last + 1;
    }
};

int main()
{
    // todo: add tests
    return 0;
}