# Question 1.4
Write a method to decide if two strings are anagrams or not.

###Solution #1
Sort the strings.<br />
###Solution #2
Check if the two strings have identical counts for each unique char.

### Solution
``` c
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/* Solution #1 */
bool isAnagram1(string s1, string s2) {  // O(nlogn)
	int len1 = s1.length();
	int len2 = s2.length();
	if (len1 != len2) return false;

	sort(&s1[0], &s1[0] + len1);
	sort(&s2[0], &s2[0] + len2);
	return (s1 == s2);
}

/* Solution #2 */
bool isAnagram2(string s1, string s2) { // O(n)
	int countChar[256] = {0}; // count frequency of every char
	int len1 = s1.length();
	int len2 = s2.length();
	if (len1 != len2) return false;

	for (int i = 0; i< len1; ++i) {
		++countChar[(int)s1[i]];
		--countChar[(int)s2[i]];
	}

	for (int i = 0; i < 256; ++i)
		if (countChar[i] != 0)
			return false;
	return true;
}

int main(int argc, char const *argv[]) {
	string s1 = "hello";
	string s2 = "lehol";
	string s3 = "ehloo";
	cout << isAnagram1(s1, s2) << '\n' << isAnagram1(s2, s3) << endl;
	cout << isAnagram2(s1, s2) << '\n' << isAnagram2(s2, s3) << endl;
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
