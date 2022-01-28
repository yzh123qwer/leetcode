/*
19. 删除链表的倒数第 N 个结点
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

 

示例 1：


输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
示例 2：

输入：head = [1], n = 1
输出：[]
示例 3：

输入：head = [1,2], n = 1
输出：[1]
*/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr){
            if (n == 1)
                return nullptr;
            else 
                return head;
        }
        else if (head->next->next == nullptr) {
            cout << "1";
            if (n == 1) {
                head->next = nullptr;
                return head;
            }
            else if (n == 2) {
                head = head->next;
                cout << head->val;
                return head;
            }
        }
        int i, j;
        ListNode* A = head;
        for (i = 0; A != nullptr; i++, A = A->next);
        if (i - n - 1 == -1){
            head = head->next;
            return head;
        }//为了区别删除第一个节点和第二节点，删除第一个和第二个下面的for语句都不执行，分别是-1和0
        for (j = 0, A = head; j < i - n - 1; j++, A = A->next);
        ListNode* B = A->next;
        B = B->next;
        A->next = B;
        return head;
    }
};
