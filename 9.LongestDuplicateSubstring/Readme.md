# 基本思路
最长重复子串产生的最基础条件为：出现重复字母，因此程序采用两次for语句实现，从第一个字母开始，每次向前推进一个，每次推进都要检索一次是否和之前的字符相同。如果相同则开始判断重复子串的
长度，并记录第一个字母位置，在所有字母都判断完成之后，选取出最长的长度，并申请一个一个新的字符串，并赋值为最长字符串，并返回（字符串自身长度是字符数+1，并以'\0'结尾）。<br>
但是这样会遇到一些特殊情况，将会导致程序大幅度提升，如在LeetCode中给出一个例子是：“zzzz……zzzz”大概有3千个左右，这个例子在执行将会大幅度提升程序迭代时间，实际上只有最后一次迭代是有意义
的。
