# Question 2.5
Given a circular linked list, implement an algorithm which returns node at the beginning of the loop.

###DEFINITION
Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an earlier node, so as to make a loop in the linked list.

###EXAMPLE
Input: `A -> B -> C -> D -> E -> C` [the same C as earlier] <br />
Output: `C`

### Solution
``` c
#include <iostream>
#include <string>
using namespace std;

typedef struct node {
	int data;
	struct node *next;
}LinkList;

LinkList* createLinkList(int a[], int n) {
	LinkList *head, *p, *q;
    for(int i = 0; i < n; ++i){
        q = new LinkList;
        q->data = a[i];
        if(i==0){
            p = q;
            head = p;
            continue;
        }
        p->next = q;
        p = q;
    }
    return head;
}

LinkList* findBeginning(LinkList *head) {
	if (head == NULL)
		return NULL;
	LinkList *fast = head, *slow = head;
	while (fast != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow)
			break;
	}
	if (fast == NULL) {
		return NULL;   // no loop
	}
	LinkList *p = head;
	while(p != slow) {
		slow = slow->next;
		p = p->next;
	}
	return p;
}

int main(int argc, char const *argv[]) {
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	LinkList *head = createLinkList(a, 7);
	LinkList *p = head;
	while (p->next != NULL)
		p = p->next;
	p->next = head->next->next->next; // 表尾连接到第四个元素
	cout << findBeginning(head)->data << endl;
	return 0;
}
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
