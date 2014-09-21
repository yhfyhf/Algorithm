# Two Sum

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: `numbers={2, 7, 11, 15}, target=9`<br>
Output: `index1=1, index2=2`

### Solution
```python
class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
    	sorted_num = sorted(num)
    	i = 0
    	j = len(num) - 1
    	while target != sorted_num[i] + sorted_num[j]:
    		if target > sorted_num[i] + sorted_num[j]:
    			i = i + 1
    		else:
    			j = j -1
    	index1 = num.index(sorted_num[i])
    	index2 = num.index(sorted_num[j])
    	if index1 == index2:
    	    del num[index1]
    	    index2 = num.index(sorted_num[j]) + 1
    	return (min(index1, index2)+1, max(index1, index2)+1)
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
