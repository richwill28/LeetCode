/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // k linked lists and n number of elements

    // O(k * n) time complexity
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int smallest = INT_MAX;
        int minIndex = -1;
        int nullCounter = 0;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] == nullptr) {
                nullCounter++;
            } else if (lists[i]->val < smallest) {
                smallest = lists[i]->val;
                minIndex = i;
            }
        }

        if (nullCounter == lists.size()) {
            return nullptr;
        }

        ListNode* head = lists[minIndex];
        lists[minIndex] = lists[minIndex]->next;
        head->next = mergeKLists(lists);
        return head;
    }

    // O(n log n) time complexity
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> minPQ;
        for (auto& list : lists) {
            while (list != nullptr) {
                minPQ.push(list->val);
                ListNode* temp = list;
                list = list->next;
                delete temp;
            }
        }

        ListNode* dummy = new ListNode();
        ListNode* list = dummy;
        while (!minPQ.empty()) {
            list->next = new ListNode(minPQ.top());
            list = list->next;
            minPQ.pop();
        }

        return dummy->next;
    }

    // O (n log k) time complexity
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode* l1, ListNode* l2) { return l1->val > l2->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> minPQ(comp);

        for (auto& list : lists) {
            if (list != nullptr) {
                minPQ.push(list);
            }
        }

        ListNode* dummy = new ListNode();
        ListNode* list = dummy;
        while (!minPQ.empty()) {
            list->next = minPQ.top();
            list = list->next;
            minPQ.pop();
            if (list->next != nullptr) {
                minPQ.push(list->next);
            }
        }

        return dummy->next;
    }
};
