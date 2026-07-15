class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr = head;
        ListNode* prev = head;

        while (curr != NULL) {
            if (curr->val == val) {
                if (curr == head) {
                    head = head->next;
                    curr = head;
                    prev = head;
                } else {
                    prev->next = curr->next;
                    curr = curr->next;
                }
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};