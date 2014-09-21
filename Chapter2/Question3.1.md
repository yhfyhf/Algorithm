# Question 3.1
Describe how you could use a single array to implement three stacks.

### Solution
``` c
// Approach 1:
// Divide the array in three equal parts and allow the
// individual stack to grow in that limited space.
// » for stack 1, we will use [0, n/3)
// » for stack 2, we will use [n/3, 2n/3)
// » for stack 3, we will use [2n/3, n)

const int stackSize = 100;
int a[stackSize * 3]; // array
int stackPointer[3] = {0, 0, 0}; // [0, 100), [100, 200), [200, 300).

void push(int stackNum, int value) {
	if (stackPointer[stackNum] == stackSize - 1)
		return;
	int index = stackNum * stackSize + stackPointer[stackNum];  // index为数组中的index
	a[index] = value;
	stackPointer[stackNum]++;
}

int pop(int stackNum) {
	if(stackPointer[stackNum] == 0)
		return -1;  // 栈空
	int index = stackNum * stackSize + stackPointer[stackNum];
	a[index] = 0;
	stackPointer[stackNum]--;
	return a[index];
}

bool isEmpty(int stackNum) {
	return (stackPointer[stackNum] == 0);
}

// Approach 2:
// In this approach, any stack can grow as long as there is any
// free space in the array. Any new element in a stack keeps a
// pointer to the previous top element of that particular stack.

struct node {
	int value;
	int index; // index in stack
	int stackNum;
};

const int stackSize = 3 * 100; // total size
node a[stackSize];
int stackPointer[3] = {0, 0, 0};
int stackTopIndex[3] = {0, 0, 0};
int index = 0; // stack in array

void push(int stackNum, int value) {
	if (index == 299)
		return;
    node p = new node;
    p.value = value;
    p.index = index++;
    p.stackNum = stackNum;
    stackPointer[stackNum]++;
	a[index++] = p;
}

int pop(int stackNum) {
	while(a[index].stackNum != stackNum) // find the index of the top of the stack
		index--;
	int value = a[index].value;
	delete a[index--];
	stackPointer[stackNum]--;
	return value;
}

bool isEmpty(int stackNum) {
	return (stackPointer[stackNum] == 0);
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
