/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Turtoise and Hare (Floyd's cycle-finding algorithm)
        ListNode *turtoise = head;
        ListNode *hare = head;
        ListNode *entry = head;
        while (hare != nullptr && hare->next != nullptr) {
            turtoise = turtoise->next;
            hare = hare->next->next;
            if (turtoise == hare) {
                while (turtoise != entry) {
                    turtoise = turtoise->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return nullptr;
    }
};
