# Question 1.6
Given an image represented by an `NxN` matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

###ALGORITHM
假设是逆时针旋转90°
1. 先将矩阵逆置;<br />
2. 交换第`i`行和第`n-1-i`行.

### Solution
``` c
#include <iostream>
using namespace std;

void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

void rotate(int img[][4], int n) {   // 逆置
	for (int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j)
			swap(img[i][j], img[j][i]);

	for (int i = 0; i < n/2; ++i) // 交换第i行和第n-1-i行
		for (int j = 0; j < n; ++j)
			swap(img[i][j], img[n-1-i][j]);
}

int main(int argc, char const *argv[]) {
	int img[][4] = { 1,  2,  3,  4,
	 		         5,  6,  7,  8,
	 		         9, 10, 11, 12,
	 		   	    13, 14, 15, 16 };
	rotate(img, 4);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j)
			cout << img[i][j] << ' ';
		cout << endl;
	}
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
