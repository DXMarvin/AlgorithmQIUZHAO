# Week_06 Notes

## 简单题目

* [1122. 数组的相对排序](https://leetcode-cn.com/problems/relative-sort-array/)

[Code](./1122.数组的相对排序.cpp)

使用 lambda 来组合出定制化的 cmp 方法，使用 std::sort 完成排序

* [242. 有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/)

[Code](./242.有效的字母异位词.cpp)

  - 直接排序判断
  - 使用 unordered_map 进行计数，使用 for_each, all_of 适当简化代码（说明意图而非如何实现）

* [387. 字符串中的第一个唯一字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/)

[Code](./387.字符串中的第一个唯一字符.cpp)

  - 使用 map 来计数
  - 第二个循环比较有趣，需要仍旧从原始字符串开始从头算起（即，找到其位置）


* [541. 反转字符串 II](https://leetcode-cn.com/problems/reverse-string-ii/)

[Code](./541.反转字符串-ii.cpp)


* [151. 翻转字符串里的单词](https://leetcode-cn.com/problems/reverse-words-in-a-string/)

[Code](./151.翻转字符串里的单词.cpp)


* [557. 反转字符串中的单词 III](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)

[Code](./557.反转字符串中的单词-iii.cpp)

使用 istringstream 来去除空格的限制，是比较讨巧的方法



仅仅反转字母（字节跳动在半年内面试中考过）

同构字符串（谷歌、亚马逊、微软在半年内面试中考过）

验证回文字符串 Ⅱ（Facebook 在半年内面试中常考）

中等题目