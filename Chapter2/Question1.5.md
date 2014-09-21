# Question 1.5
Write a method to replace all spaces in a string with '%20'.

### ALGORITHM
1. Count the number of spaces during the first scan of string.
2. Parse the string from the end and for each charactor:

 *  If a space is encountered, store “%20”.
 *  Else, store the character as it is in the newly shifted location.

### Solution
``` c
#include <iostream>
#include <string>
using namespace std;

char* replace1(char *s) {   // 新开辟一个数组
	int len = strlen(s);
	if (len == 0) return NULL;
	int count = 0;  // count the number of spaces
	for (int i = 0; i < len; ++i)
		if (s[i] == ' ') ++count;
	int newLen = len + 2 * count + 1;
	char *replaced_s = new char[newLen];
	int j = 0; // index in replaced_s
	for (int i  = 0; i < len; ++i) {
		if(s[i] == ' ') {
			replaced_s[j] = '%';
			replaced_s[j+1] = '2';
			replaced_s[j+2] = '0';
			j += 3;
		}
		else
			replaced_s[j++] = s[i];
	}
	replaced_s[j] = '\0';
	return &replaced_s[0];
}

char* replace2(char *s) {  // 从尾部开始替换
	int len = strlen(s);
	if (len == 0) return NULL;
	int count = 0;
	for (int i = 0; i < len; ++i)
		if (s[i] == ' ') ++count;
	int newLen = len + 2 * count;
	int j = newLen;
	s[j--] = '\0';
	for (int i = len - 1; i >= 0; --i) {
		if(s[i] == ' ') {
			s[j] = '0';
			s[j-1] = '2';
			s[j-2] = '%';
			j -= 3;
		}
		else
			s[j--] = s[i];
	}
	return s;
}

int main(int argc, char const *argv[]) {
	char s[100] = "hello, how are you?";
	cout << replace1(s) << '\n' << replace2(s) << endl;
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
