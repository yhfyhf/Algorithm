# Question 1.3
Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer.

### NOTE
One or two additional variables are fine. An extra copy of the array is not.

### FOLLOW UP
Write the test cases for this method.

### Solution
``` c
// Test Cases:
// 1. "abcd"
// 2. "aaaa"
// 3. ""
// 4. "aaabbb"

#include <iostream>
using namespace std;

void removeDuplicate(char s[]) {
	if (s == NULL) return;
	int len = strlen(s);
	if (len < 2) return;
	int index = 0;

	for (int i = 0; i < len; ++i) {
		if (s[i] != '\0') {
			s[index++] = s[i];
			for (int j = i + 1; j < len; ++j)
				if (s[i] == s[j])
					s[j] = '\0';
		}
	}
	s[index] = '\0';
}

int main(int argc, char const *argv[]) {
	char s[] = "abcdefg";
	char s1[] = "abcd";
	char s2[] = "aaaa";
	char s3[] = "";
	char s4[] = "aaabbb";
	char s5[] = "abababa";
	removeDuplicate(s1);
	removeDuplicate(s2);
	removeDuplicate(s3);
	removeDuplicate(s4);
	removeDuplicate(s5);
	cout << s1 << '\n' << s2 << '\n' << s3 << '\n' << s4 << '\n' << s5 << endl;
	return 0;
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
