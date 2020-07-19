# Week_01 Notes

## 简单题目

* [26.删除排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)

[Code](./26.删除排序数组中的重复项.cpp)

快慢指针，慢指针对应着不包含重复项数组的尾部位置

当然，也可以认为是进行遍历而已，遇到非重复项元素进行前提

* [189.旋转数组](https://leetcode-cn.com/problems/rotate-array/)

[Code](./189.旋转数组.cpp)

此题题解中三次翻转的方法很不错，且可以通过 STL 很方便地实现

方式一：
1 2 | 3 4 5 6 7
2 1 | 7 6 5 4 3 (分别 reverse)
3 4 5 6 7 | 1 2 (整体 reverse)
这种其实是向左移动，所以可以通过求 num-k 来做

方式二：
1 2 | 3 4 5 6 7
7 6 5 4 3 | 2 1 (整体 reverse)
6 7 | 1 2 3 4 5 (在原始位置分别 reverse)

* [21.合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)

[Code](./21.合并两个有序链表.cpp)

首先构造一个头结点会相对方便实现，最后需要 delete 掉

* [88.合并两个有序数组](https://leetcode-cn.com/problems/merge-sorted-array/)

[Code](./88.合并两个有序数组.cpp)

因为总数组长度是固定的 (m+n)，所以，可以从后往前进行数字填充
此外当 l1 （本数组）全部拷贝后，如果 l2 仍未到起始位置，将剩余 l2 拷贝到 l1 开头

* [1.两数之和](https://leetcode-cn.com/problems/two-sum/)

[Code](./1.两数之和.cpp)

使用 (unordered_)map 是很合适的方法

* [283.移动零](https://leetcode-cn.com/problems/move-zeroes/)

[Code](./283.移动零.cpp)

1 0 3 0 0 2
1 3 2 0 0 0

与 26.删除重复项 类似（其实更加简单），均是保持一个慢得指针/下一个要插入的位置，将非零元素插入，最后补零（冲掉没有被覆盖的元素）

当然，直接 swap 也是可以的

* [66.加一](https://leetcode-cn.com/problems/plus-one/)

[1, 2, 3] -> [1, 2, 4]
[1, 2, 9] -> [1, 3, 0]
[9, 9] -> [1, 0, 0]

[Code](./66.加一.cpp)

- 判断进位，并反向依次判断是否继续
- 直接计算最低位向上的最多重复 9 的位数，这些是会被替换为 0 的，然后第一个非 9 的数字加一（或者进行增添一个新的最高位 1）


* [242.有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/)

[Code](./242.有效的字母异位词.cpp)

使用 map 进行计数，并可以通过中途小于 0 进行提前退出


## 中等题目

* [641. 设计循环双端队列](https://leetcode.com/problems/design-circular-deque/)

[TODO]

* [49. 字母异位词分组](https://leetcode-cn.com/problems/group-anagrams/)

使用了一个 trick，将 sort 后的字符串作为 map 的键使用 ..

## 困难题目

* [接雨水](https://leetcode.com/problems/trapping-rain-water/) 

[TODO]

## 学习总结主题

* 用 add first 或 add last 这套新的 API 改写 Deque 的代码。

[TODO]

* 分析 Queue 和 Priority Queue 的源码。

[TODO]


