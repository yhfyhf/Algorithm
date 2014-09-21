# Question 3.5
Implement a `MyQueue` class which implements a queue using two stacks.


ALGORITHM<br />
Always push data into inStack;<br />
While dequeue:<br />
1. if outStack is not empty, pop from outStack;
2. if outStack is empty, reverse the element in inStack into
      outStack, then pop from outStack.

### Solution
``` c
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
	stack<int> inStack, outStack;

public:
	void enqueue(int data) {
		inStack.push(data);
	}

	void reverse(stack<int> &s1, stack<int> &s2) {    // reverse from s1 to s2
		while (!s1.empty()) {
			int data = s1.top();
			s1.pop();
			s2.push(data);
		}
	}

	void dequeue() {
		if (outStack.empty())
			reverse(inStack, outStack);
		outStack.pop();
	}

	int tail() {
		if (!inStack.empty())
			return inStack.top();
		else if (!outStack.empty()) {
			reverse(outStack, inStack);
			return inStack.top();
		}
		else   // inStack and outStack are both empty, queue is empty
			return -1;
	}

	int front() {
		if (inStack.empty() && outStack.empty()) // queue is empty
			return -1;
		if (outStack.empty())
			reverse(inStack, outStack);
		return outStack.top();

	}

	int empty() {
		return inStack.empty() && outStack.empty();
	}
};

int main(int argc, char const *argv[]) {
	MyQueue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	cout << q.front() << ' ' << q.tail() << endl; // 1 2 3 4
	q.dequeue();
	cout << q.front() << ' ' << q.tail() << endl; // 2 3 4
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
