# Week_02 Notes

## 简单题目

* [590. N 叉树的后序遍历](https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/)

[Code](./590.n叉树的后序遍历.cpp)

迭代 [TODO]


* [589. N 叉树的前序遍历](https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/description/)

[Code](./589.n叉树的后序遍历.cpp)

## 中等题目

* [94. 二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)

[Code](./94.二叉树的中序遍历.cpp)


* [144. 二叉树的前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/)

[Code](./144.二叉树的前序遍历.cpp)

* [429. N 叉树的层序遍历](https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/)

[Code](./429.n叉树的层序遍历)

* [264. 丑数](https://leetcode-cn.com/problems/ugly-number-ii/)

[TODO] No idea

* [347. 前 K 个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements/)

[Code](./347.前-k-个高频元素.cpp)

C++ priority_queue 自定义比较函数，比较优雅的方式是使用 lambda 表达式，并且加上 type alias，代码总体是比较精简的

``` cpp
  using m_T = pair<int, int>;
  // http://neutrofoton.github.io/blog/2016/12/29/c-plus-plus-priority-queue-with-comparator/
  auto cmp = [](m_T& p1, m_T& p2) {return p1.second < p2.second;} ;
  priority_queue<m_T, std::vector<m_T>, decltype(cmp)> que(cmp);; 
```

Note, using type alias 需要定义在类的内部

* [236. 二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)

[Code](./236.二叉树的最近公共祖先.cpp)

之前看过题解，很漂亮


* [105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

[TODO]

* [77. 组合](https://leetcode-cn.com/problems/combinations/)

[Code](./77.组合.cpp)

又一次忘记了之前的 backtrack 的模板..

* [46. 全排列](https://leetcode-cn.com/problems/permutations/)

[Code](./46.全排列.cpp)

  - 使用 visited 数组来保证序列中仅访问一次元素
  - 使用 stl next_permutation 需要首先将数组进行排序

* [47. 全排列 II](https://leetcode-cn.com/problems/permutations-ii/)

[Code](./47.全排列-ii.cpp)

  - 与普通全排列一样，将结果传入 set 中来保证不重复
  - 在 drill down 处进行判断（在之前 visisted 位置进行判断），此判断之前看过题解，简单地解释：
  如果前一个数字和当前数字一样，但是前面那个并没有使用，那当前数字是没有必要使用的（因为原则上同样的数字，如果要使用的话，至少需要按顺序使用 ...）

  ``` cpp
    if (i > 0 && nums[i] == nums[i-1] && !visited[i-1]) {
        continue;
    }
  ```