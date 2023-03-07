
#include <vector>
#include <cstdlib>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class IterativeSolution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        ListNode *next, *aux, *prev;

        prev = head;
        next = prev->next;

        while (next != NULL)
        {
            aux = next->next;
            next->next = prev;
            prev = next;
            next = aux;
        }

        head->next = nullptr;

        return prev;
    }
};

int main()
{
    // todo: add tests
    return 0;
}