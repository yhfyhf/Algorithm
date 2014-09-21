# Valid Palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
`"A man, a plan, a canal: Panama"` is a palindrome.
`"race a car"` is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

### Solution
``` python
class Solution:
    # @param s, a string
    # @return a boolean
    def isPalindrome(self, s):
        A = filter((lambda x: x.isalnum()), s).lower()
        return A == A[::-1]
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
