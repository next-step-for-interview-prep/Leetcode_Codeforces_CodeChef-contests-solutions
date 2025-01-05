#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *insertGreatestCommonDivisors(ListNode *head)
{
    if (!head || !(head->next))
        return head;

    ListNode *curr = new ListNode(head->val);
    curr = head;

    while (curr->next)
    {
        int ans = __gcd(curr->val, curr->next->val);
        ListNode *temp = new ListNode(ans);
        temp->next = curr->next;
        curr->next = temp;
        curr = temp->next;
    }
    return head;
}

int main(int argc, char const *argv[])
{
    ListNode* head;
    head = insertGreatestCommonDivisors(head);
    return 0;
}