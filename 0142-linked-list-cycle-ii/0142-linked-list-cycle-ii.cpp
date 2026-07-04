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
        ListNode *slow = head;
        ListNode *fast = head;

        bool isCycle = false;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                isCycle = true;
                break;
            }
        }

        if(!isCycle){
            return NULL; //if no cycle was found return NULL because there is no starting point of the cycle
        }
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next; // these pointers will eventually meet at the start of the cycle
        }

        return slow;
    }
};

//Alternate solution
// public:
//     ListNode *detectCycle(ListNode *head) {
//         ListNode *slow = head;
//         ListNode *fast = head;

//         while(fast != NULL && fast->next != NULL){
//             slow = slow->next;
//             fast = fast->next->next;

//             if(slow == fast){
//                 slow = head;

//                 while(slow != fast){
//                     slow = slow->next;
//                     fast = fast->next;
//                 }

//                 return slow;
//             }
//         }

//         return NULL;
//     }
// };