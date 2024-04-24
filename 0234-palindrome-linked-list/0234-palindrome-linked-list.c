void isPalindrome_(
    struct ListNode head[static 1] , 
    struct ListNode tail[static 1],
    bool *res // reference
){
    static struct ListNode *base = NULL;
    if(head){
        base = head;
    }
    if(base == tail) return;
    if(tail->next){
        isPalindrome_(NULL,tail->next,res);
    }

    if(!(*res)) return ;
    *res = base->val == tail->val;
    base = base->next;
}

bool isPalindrome(struct ListNode* head) {
    bool res = true;
    if(head && head->next ){
        isPalindrome_(head,head->next,&res);
    }
    return res;
}