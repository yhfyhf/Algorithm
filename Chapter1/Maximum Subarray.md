# Maximum Subarray

For example, given the array `[−2,1,−3,4,−1,2,1,−5,4]`,
the contiguous subarray `[4,−1,2,1]` has the largest sum = `6`.

### Solution
``` python
class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxSubArray(self, A):
        sum = max_sum = A[0]
        if len(A) > 1:
            for i in range(1, len(A)):
                sum = A[i] if sum<0 else sum+A[i]
                max_sum = sum if sum>max_sum else max_sum
        return max_sum
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
