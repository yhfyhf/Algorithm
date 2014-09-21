# Anagrams

Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

### Solution
``` python
class Solution:
    # @param strs, a list of strings
    # @return a list of strings
    def anagrams(self, strs):
        sorted_words = dict()
        for word in strs:
            sorted_word = "".join(sorted(word))
            if sorted_word not in sorted_words:
                sorted_words[sorted_word] = []
            sorted_words[sorted_word].append(word)

        anagrams = []
        for key in sorted_words:
            if len(sorted_words[key]) > 1:
                for word in sorted_words[key]:
                    anagrams.append(word)
        return anagrams
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
