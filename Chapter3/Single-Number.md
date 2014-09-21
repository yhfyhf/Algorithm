# Single Number
Given an array of integers, every element appears twice except for one. Find that single one.

### Note
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

### Solution
``` c
class Solution {
public:
	int singleNumber(int A[], int n) {
    	int result = 0;
    	for(int i = 0; i < n; i++)
        	result = result ^ A[i];
    	return result;
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
