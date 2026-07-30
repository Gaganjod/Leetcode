class Solution {
public:
    bool isPalindrome(ListNode* head) {

        // Step 1: Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* temp = slow;
        ListNode* prev = NULL;

        while (temp != NULL) {
            ListNode* front = temp->next;

            temp->next = prev;
            prev = temp;
            temp = front;
        }

        // Step 3: Compare first half and reversed second half
        ListNode* first = head;
        ListNode* second = prev;

        while (second != NULL) {

            if (first->val != second->val) {
                return false;
            }

            first = first->next;
            second = second->next;
        }

        return true;
    }
};