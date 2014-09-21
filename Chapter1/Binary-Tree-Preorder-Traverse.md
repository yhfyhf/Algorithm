# Binary Tree Preorder Traverse

Given a binary tree, return the preorder traversal of its nodes' values.

For example: Given binary tree `{1,#,2,3}`,

        1
         \
          2
         /
        3

return `[1,2,3]`.

Note: Recursive solution is trivial, could you do it iteratively?

### Solution
``` python
# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def preorderTraversal(self, root):
        temp = []
        res = []
        if not root:
            return res
        temp.append(root)
        while len(temp):
            node = temp.pop()
            res.append(node.val)
            if node.right:
                temp.append(node.right)
            if node.left:
                temp.append(node.left)
        return res
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
