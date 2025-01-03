#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// https://leetcode.com/problems/linked-list-cycle/
bool hasCycle(ListNode *head) // Detect cycle in linked list TC: O(N) SC: O(1)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}

// https://leetcode.com/problems/linked-list-cycle-ii/
ListNode *detectCycle(ListNode *head) // return the starting point of the cycle TC: O(N) SC: O(1)
{
    ListNode *slow = head;
    ListNode *fast = head;
    bool isCycle = false;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            isCycle = true;
            break;
        }
    }

    if (!isCycle)
    {
        return NULL;
    }

    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
// remove cycle
void *removeCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    bool isCycle = false;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            isCycle = true;
            break;
        }
    }

    if (!isCycle)
    {
        return NULL;
    }

    slow = head;
    ListNode* prev = NULL;
    while (slow != fast)
    {
        slow = slow->next;
        prev = fast; // store the previous node of fast
        fast = fast->next;
    }
    prev -> next = NULL; // remove cycle
    
}

int main()
{

    return 0;
}