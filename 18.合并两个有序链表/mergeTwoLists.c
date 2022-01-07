//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if (list1 == NULL)
        return list2;
    else if (list2 == NULL)
        return list1;
    else{
        struct ListNode *list_return = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (list1->val <= list2->val){
            list_return->val = list1->val;
            list1 = list1->next;
            if (list1 == NULL){
                list_return->next = list2;
                return list_return;
            }
        }
        else{
            list_return->val = list2->val;
            list2 = list2->next;
            if (list2 == NULL){
                list_return->next = list1;
                return list_return;
            }
        }
        struct ListNode *tmp1 = list_return;
        struct ListNode *tmp2 = NULL;
        for ( ; list1 != NULL || list2 != NULL; ){
            if (list1 == NULL){
                tmp1->next = list2;
                return list_return;
            }
            else if (list2 == NULL){
                tmp1->next = list1;
                return list_return;
            }
            else if (list1->val <= list2->val){
                tmp2 = (struct ListNode*)malloc(sizeof(struct ListNode));
                tmp2->val = list1->val;
                tmp1->next = tmp2;
                tmp1 = tmp1->next;
                list1 = list1->next;
                continue;
            }
            else{
                tmp2 = (struct ListNode*)malloc(sizeof(struct ListNode));
                tmp2->val = list2->val;
                tmp1->next = tmp2;
                tmp1 = tmp1->next;
                list2 = list2->next;
                continue;
            }
        }
        return list_return;
    }
}
