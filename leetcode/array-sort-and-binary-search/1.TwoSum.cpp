#include <map>
#include <algorithm>
#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

class NaiveSolution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> pos;
        pos.push_back(0);
        pos.push_back(1);

        bool found = false;

        for (size_t i = 0; !found && (i < nums.size()); i++)
        {
            for (size_t j = (i + 1); !found && (j < nums.size()); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    pos[0] = i;
                    pos[1] = j;
                    found = true;
                }
            }
        }

        return pos;
    }
};

class NLogNSolution
{
public:
    void heapify(vector<int> &arr, vector<int> &indices, int n, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[indices[left]] > arr[indices[largest]])
            largest = left;

        if (right < n && arr[indices[right]] > arr[indices[largest]])
            largest = right;

        if (largest != i)
        {
            swap(indices[i], indices[largest]);
            heapify(arr, indices, n, largest);
        }
    }

    vector<int> heapSort(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> indices(n);

        for (int i = 0; i < n; i++)
        {
            indices[i] = i;
        }

        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(arr, indices, n, i);
        }

        vector<int> sortedIndices(n);
        for (int i = n - 1; i >= 0; i--)
        {
            sortedIndices[i] = indices[0];
            swap(indices[0], indices[i]);
            heapify(arr, indices, i, 0);
        }

        return sortedIndices;
    }

    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> indices = heapSort(nums);

        /*
        printf("\ntarget: %d\n", target);

        printf("orig: ");
        for (size_t i = 0; i < nums.size(); i++)
            printf("%d ", nums[i]);
        printf("\n");

        printf("indices: ");
        for (size_t i = 0; i < nums.size(); i++)
            printf("%d ", indices[i]);
        printf("\n");

        printf("sorted: ");
        for (size_t i = 0; i < nums.size(); i++)
            printf("%d ", nums[indices[i]]);
        printf("\n");
        */

        int right = nums.size() - 1;
        int left = 0;

        /*
        // binary search
        // works if all numbers are positive, but fails with negatives
        int center = 0;

        while (left <= right)
        {
            center = (left + right) / 2;

            if (nums[indices[center]] == target)
                break;
            else if (target > nums[indices[center]])
                left = center + 1;
            else
                right = center - 1;
        }

        printf("center: %d indice[center]: %d\n", center, indices[center]);

        left = 0;
        right = center;
        */

        vector<int> pos;

        while (left < right)
        {
            int sum = nums[indices[left]] + nums[indices[right]];

            // printf("left: %d right: %d sum: %d desired: %d\n", left, right, sum, target);

            if (sum == target)
            {
                pos.push_back(indices[left]);
                pos.push_back(indices[right]);
                break;
            }
            else if (sum > target)
                right--;
            else
                left++;
        }

        sort(pos.begin(), pos.end());
        return pos;
    }
};

class Solution
{
    // Time O(n) Space O(n)
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> m;

        m.insert(pair<int, int>(nums[0], 0));

        for (int idx = 1; idx < nums.size(); idx++)
        {
            int diff = target - nums[idx];

            auto it = m.find(diff);

            if (it != m.end())
            {
                // printf("it->second: %d idx: %d\n", it->second, idx);
                return vector<int>{it->second, idx};
            }
            else
                m.insert(pair<int, int>(nums[idx], idx));
        }

        // printf("it->second: -1 idx: -1\n");
        return vector<int>{-1, -1};
    }
};

int main()
{
    Solution s;

    vector<int> v1{2, 7, 11, 15};
    vector<int> r1 = s.twoSum(v1, 9);
    assert(r1 == (vector<int>{0, 1}));

    vector<int> v2{3, 2, 4};
    vector<int> r2 = s.twoSum(v2, 6);
    assert(r2 == (vector<int>{1, 2}));

    vector<int> v3{3, 3};
    vector<int> r3 = s.twoSum(v3, 6);
    assert(r3 == (vector<int>{0, 1}));

    vector<int> v4{-3, 4, 3, 90};
    vector<int> r4 = s.twoSum(v4, 0);
    assert(r4 == (vector<int>{0, 2}));

    return 0;
}