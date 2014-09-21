# Question 3.2
How would you design a stack which, in addition to push and pop, also has a function min which returns the minimum element? Push, pop and min should all operate in `O(1)` time.

### Solution
``` c
// You can implement this by having each node in the stack keep track
// of the minimum be- neath itself Then, to find the min,
// you just look at what the top element thinks is the min.

struct node{
	int value;
	int curMin;
};

class StackWithMin1 {
private:
	int top;
	node *buf;

const int SIZE = 100;

public:
	StackWithMin1(int SIZE) {   // contructor
		buf = new node[SIZE];
		top = 0;
		buf[0].curMin = ~(1<<31); // 2147483647
	}

	~StackWithMin1() {           // destructor
		delete[] buf;
	}

	int pop() {
		return buf[top--].value;
	}

	void push(int value) {
		buf[++top].value = value;
		buf[top].curMin = buf[top-1].curMin > value?
							 value : buf[top-1].curMin;
	}

	int min() {
		return bug[top].curMin;
	}
};

/* ========================================================== */

// There’s just one issue with this: if we have a large stack,
// we waste a lot of space by keeping track of the min for
// every single element. Can we do better?

// We can (maybe) do a bit better than this by using an additional
// stack which keeps track of the mins.

class Stack {
private:
	int *buf;
	int top;

public:
	Stack(int size) {   // contructor
		buf = new int[size];
		top = 0;
	}

	~Stack() {           // destructor
		delete[] buf;
	}

	void push(int value) {
		buf[++top] = value;
	}

	int pop() {
		return buf[top--];
	}
}; // end of class

class StackWithMin2 {
private:
	stack s1, s2;
public:
	StackWithMin2() {
		s1 = new Stack(100);
		s2 = new Stack(100);
	}

	~StackWithMin2() {
		delete s1;
		delete s2;
	}

	void push(int value) {
		s1.push(value);
		if (val < min())
			s2.push(value);
	}

	int pop() {
		if(s1.buf[top] == min())
			s2.pop();
		s1.pop();
	}

	int min() {
		if (s2.top == 0)
			return ~(1<<31); // 2147483647
		else
			return s2.top();
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
