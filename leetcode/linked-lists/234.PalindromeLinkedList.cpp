
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class NaiveSolution
{
public:
    bool isPalindrome(ListNode *head)
    {
        // Time O(n) Space O(n)
        vector<int> vals;

        ListNode *node = head;

        while (node != NULL)
        {
            vals.push_back(node->val);
            node = node->next;
        }

        for (int i = 0; i < vals.size() / 2; i++)
        {
            if (vals[i] != vals[vals.size() - 1 - i])
                return false;
        }

        return true;
    }
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        // Time O(n) Space O(1)
        // I could not find this solution by myself, but it is quite clever.
        // See https://leetcode.com/problems/palindrome-linked-list/solutions/1137027/js-python-java-c-easy-floyd-s-reversal-solution-w-explanation/

        // find the half of the list using a pointer
        // that moves twice as fast in the list
        ListNode *prev = head;
        ListNode *slow = head;
        ListNode *fast = head;

        do
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;

            if (fast != NULL)
                fast = fast->next;

        } while (fast != NULL);

        // finish the list in the first half
        prev->next = NULL;

        // reverse pointers in the last half so that
        // we do not use additional space
        while (slow != NULL)
        {
            // fast is used as an aux var here to
            // prevent the need of other variable
            fast = slow->next;
            slow->next = prev;
            prev = slow;
            slow = fast;
        }

        // check if the halfs are palindrome
        // fast is used to go over the linkedlist
        // in the forward direction and prev goes
        // in the backward direction.
        fast = head;
        while ((fast != NULL) && (prev != NULL))
        {
            if (fast->val != prev->val)
                return false;

            fast = fast->next;
            prev = prev->next;
        }

        return true;
    }
};

int main()
{
    Solution s;

    // In a real program, the ListNode's should be freed.
    assert(s.isPalindrome(new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))))) == true);
    assert(s.isPalindrome(new ListNode(1, new ListNode(2, new ListNode(2)))) == false);
    assert(s.isPalindrome(new ListNode(1, new ListNode(2, new ListNode(1)))) == true);
    assert(s.isPalindrome(new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(3))))) == false);
    assert(s.isPalindrome(new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(3, new ListNode(2, new ListNode(2, new ListNode(1)))))))) == true);
    assert(s.isPalindrome(new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(2, new ListNode(2, new ListNode(1))))))) == true);
    assert(s.isPalindrome(new ListNode(0, new ListNode(2, new ListNode(2, new ListNode(3, new ListNode(2, new ListNode(2, new ListNode(1)))))))) == false);
    assert(s.isPalindrome(new ListNode(0, new ListNode(2, new ListNode(2, new ListNode(2, new ListNode(2, new ListNode(1))))))) == false);
    assert(s.isPalindrome(new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(3, new ListNode(2, new ListNode(2, new ListNode(0)))))))) == false);
    assert(s.isPalindrome(new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(2, new ListNode(2, new ListNode(0))))))) == false);
    assert(s.isPalindrome(new ListNode(1, new ListNode(2, new ListNode(0, new ListNode(3, new ListNode(2, new ListNode(2, new ListNode(1)))))))) == false);
    assert(s.isPalindrome(new ListNode(1, new ListNode(2, new ListNode(0, new ListNode(2, new ListNode(2, new ListNode(1))))))) == false);
    assert(s.isPalindrome(new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(3, new ListNode(0, new ListNode(2, new ListNode(1)))))))) == false);
    assert(s.isPalindrome(new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(0, new ListNode(2, new ListNode(1))))))) == false);

    return 0;
}