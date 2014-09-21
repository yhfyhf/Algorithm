# Reverse Words in A String

Given an input string, reverse the string word by word.

For example,
Given s = `"the sky is blue"`,
return `"blue is sky the"`.

### Solution
``` python
class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        return ' '.join(s.split()[::-1])
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
