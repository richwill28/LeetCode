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
    bool hasCycle(ListNode *head) {
        // Turtoise and Hare (Floyd's cycle-finding algorithm)
        ListNode *turtoise = head;
        ListNode *hare = head;
        while (hare != nullptr && hare->next != nullptr) {
            turtoise = turtoise->next;
            hare = hare->next->next;
            if (turtoise == hare) {
                return true;
            }
        }
        return false;
    }
};
