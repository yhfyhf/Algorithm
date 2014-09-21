# Question 2.2
Implement an algorithm to find the nth to last element of a singly linked list.

### Solution:
``` c
#include <iostream>
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

LinkList* findNthToLast(LinkList *head, int n) {
	LinkList *fast = head, *slow = head;
	for (int i = 0; i < n; ++i)
		fast = fast->next;
	while (fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

int main(int argc, char const *argv[]) {
	int a[] = {1, 2, 4, 5, 4, 4, 9};
	int length = 7;
	LinkList *head = createLinkList(a, length);
	int n = 4;
	LinkList *nthToLast = findNthToLast(head, n);
	cout << nthToLast->data << endl;
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
