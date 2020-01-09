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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // output
        ListNode * output = new ListNode(0);
        ListNode * start = output;
        
        // Loop through list
        while(l1)
        {
            // Add digits, carry over if necessary
            int digit_sum = l1->val + l2->val + output->val;
            if (digit_sum >= 10)
            {
                output->val = digit_sum - 10;
                output->next = new ListNode(1);
            }
            else
            {
                output->val = digit_sum;
                output->next = new ListNode(0);
            }
            
            if (!l1->next && l2->next)
            {
                // Pad zeros
                l1->next = new ListNode(0);
            }
            else if (!l2->next && l1->next)
            {
                // Pad zeros
                l2->next = new ListNode(0);
            }
            
            l1 = l1->next;
            l2 = l2->next;
            
            output = output->next;
        }
        
        // If there is a zero at the end remove it
        ListNode* temp = start;
        if (output->val == 0)
        {
            while (temp->next != output)
            {
                temp = temp->next;
            }
            temp->next = NULL;
        }
        
        return start;
    }
};


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* output = new ListNode(0); // dummy
        ListNode* current = output;
        ListNode* p = l1;
        ListNode* q = l2;
        int carry = 0;
        while (p != NULL || q != NULL)
        {
            int x = (p != NULL) ? p->val : 0;
            int y = (q != NULL) ? q->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
            if (p != NULL)
            {
                p = p->next;
            }
            if (q != NULL)
            {
                q = q->next;
            }
        }
        if (carry > 0)
        {
            current->next = new ListNode(carry);
        }
        
        return output->next;
    }
};