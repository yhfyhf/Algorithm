# Linked List Cycle
Given a linked list, determine if it has a cycle in it.

###Follow up
Can you solve it without using extra space?<br />

### Solution
``` c
/*
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
        if(head == NULL
            || head->next == NULL
            || head->next->next==NULL)
            return false;
        ListNode *pfast = head, *pslow = head;
        while(pfast != pslow) {
            if (pfast)pfast = pfast->next;
            if (pfast)pfast = pfast->next;
            if(!pfast) return false;
            if(pslow) pslow = pslow->next;
        }
        return true;
    }
};
```
<div id="disqus_thread"></div>
<script type="text/javascript">
    var disqus_shortname = 'algorithm-book';
    (function() {
        var dsq = document.createElement('script'); dsq.type = 'text/javascript'; dsq.async = true;
        dsq.src = '//' + disqus_shortname + '.disqus.com/embed.js';
        (document.getElementsByTagName('head')[0] || document.getElementsByTagName('body')[0]).appendChild(dsq);
    })();
</script>
