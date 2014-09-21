# Question 2.4
You have two numbers represented by a linked list, where each node contains a single digit The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.

###EXAMPLE
Input: `(3 -> 1 -> 5)`, `(5 -> 9 -> 2)` <br />
Output: `8 -> 0 -> 8`<br />
`513 + 295 = 808`<br />

###ALGORITHM
1. 设置进位标志flag<br />
2. 处理不同长度的链表<br />
3. 最高位有进位	<br />

### Solution
``` c
#include <iostream>
using namespace std;

typedef struct node {
	int data;
	struct node *next;
}LinkList;

LinkList* createLinkList(int a[], int n) {
	LinkList *head, *p, *q;
	for (int i = 0; i < n; ++i) {
		q = new LinkList;
		q->data = a[i];
		if (i == 0) {
			p = q;
			head = p;
			continue;
		}
		p->next = q;
		p = q;
	}
	return head;
}

void printLinkList(LinkList *head) {
	while (head) {
		cout << head->data << ' ';
		head = head->next;
	}
	cout << endl;
}

LinkList* sum(LinkList *head1, LinkList *head2) {
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	LinkList *p1 = head1, *p2 = head2, *head, *cur = NULL;
	int flag = 0;
	while (p1 && p2) {
		LinkList *p = new LinkList;
		p->data = (p1->data + p2->data + flag) % 10;
		flag = (p1->data + p2->data + flag) / 10;
		if (cur == NULL) {
			cur = p;
			head = cur;
		}
		else {
			cur->next = p;
		    cur = cur->next;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	while (p1) {
		LinkList *p = new LinkList;
		p->data = (p1->data + flag) % 10;
		flag = (p1->data + flag) / 10;
		cur->next = p;
		cur = p;
		p1 = p1->next;
	}
	while (p2) {
		LinkList *p = new LinkList;
		p->data = (p2->data + flag) % 10;
		flag = (p2->data + flag) / 10;
		cur->next = p;
		cur = cur->next;
		p2 = p2->next;
	}
	if (flag > 0) {
		LinkList *p = new LinkList;
		p->data = 1;
		cur->next = p;
	}
	return head;
}

int main(int argc, char const *argv[]) {
	int a1[] = {1, 2, 4, 5, 4, 4, 9, 9, 9};
	int a2[] = {1, 9, 4, 5, 6, 7};
	LinkList *head1 = createLinkList(a1, 9);
	LinkList *head2 = createLinkList(a2, 6);
	LinkList *head = sum(head1, head2);
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
