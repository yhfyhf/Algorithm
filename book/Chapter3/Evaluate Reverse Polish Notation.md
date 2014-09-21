# Evaluate Reverse Polish Notation
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

###Some examples
```
["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
```

### Solution
``` c
class Solution {
public:
    int s2i(string s) {
        bool isPositive = true;
        if (s[0] == '-')
            isPositive = false;
        int i = isPositive? 0:1;
        int ret = 0;
        for (; i < s.size(); i++)
            ret = ret * 10 + s[i] - '0';
        return isPositive? ret:(-ret);
    }

    int evalRPN(vector<string> &tokens) {
        vector<string>::iterator it =  tokens.begin();
        vector<int> temp;
        while (it < tokens.end()) {
            if (*it == "+" || *it == "-" || *it == "*" || *it == "/") {
                int num2 = temp.back();
                temp.pop_back();
                int num1 = temp.back();
                temp.pop_back();
                if (*it == "+")
                    temp.push_back(num1 + num2);
                else if (*it == "-")
                    temp.push_back(num1 - num2);
                else if (*it == "*")
                    temp.push_back(num1 * num2);
                else
                    temp.push_back(num1 / num2);    
            }
            else
                temp.push_back(s2i(*it));
            it++;
        }
        return temp[0];
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
