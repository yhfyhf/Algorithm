# Question 2.1
Write code to remove duplicates from an unsorted linked list.

###FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?<br />

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

void printLinkList(LinkList*head) {
	LinkList *p = head;
	while (p) {
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}

void removeDuplicate(LinkList *head) {
	if (head == NULL)
		return;
	LinkList *p = head, *q, *r;
	while(p) {
		q = p;
		r = q->next;
		while(r) {
			if (p->data == r->data) {
				LinkList *temp = r;
				q->next = r->next;
				delete temp;
				r = q->next;
			}
			else {
				q = r;
				r = r->next;
			}
		}
		p = p->next;
	}
}

int main(int argc, char const *argv[]) {
	int a[] = {1, 2, 4, 5, 4, 4, 9};
	LinkList *head = createLinkList(a, 7);
 	removeDuplicate(head);
	printLinkList(head);
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
