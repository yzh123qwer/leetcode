# 基本思路
题目的目的较为简单，在一次遍历输入数组中的元素过程，如果是新出现的数字，则将记住其位置，如果是已经出现过得元素，则只需要将最近一次出现的位置相减，如果差小于k，则直接返回true，
如果所有元素遍历完成都没有返回true，则不存在，返回false。<br>
但是对于已经出现过得元素，在第二次查找过程中，如果只是没有顺序的存储则又会花费大量的时间进行查找，因此使用散列表的方式进行存储。<br>
程序中使用的散列表较为简单，散列函数为(a * a) % tableSize，其中a为被散列的值。当散列地址发生冲突时，使用开放地址法中的线性探测法。<br>
注：程序在LeetCode上发生内存溢出的报错，但是在vs2019上可以运行。
