# Evaluate Reverse Polish Notation

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are `+`, `-`, `*`, `/`. Each operand may be an integer or another expression.

Some examples:

    ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
    ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

### Solution
``` Python
class Solution:
    # @param tokens, a list of string
    # @return an integer
    def evalRPN(self, tokens):
        temp = []
        operations = {
            '+': (lambda x,y: x+y),
            '-': (lambda x,y: x-y),
            '*': (lambda x,y: x*y),
            '/': (lambda x,y: x/y if x/y>=0 or x%y==0 else x/y+1)
        }
        for element in tokens:
            if element not in operations:
                temp.append(element)
            else:
                latter = int(temp.pop())
                former = int(temp.pop())
                temp.append(operations[element](former, latter))
        return int(temp[0])
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
