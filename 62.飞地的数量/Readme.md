# 基本思路
深度优先搜索<br>
程序首先遍历边缘单元格，只要这个单元格式1，那么与他相连或者间接相连的单元格均不是飞地。因此在遍历边缘单元格时，只要将这些格子的值赋值为-1。<br>
完成之后，在遍历一次所有单元格，只要它的值为1，那么就是飞地，每找到一个，将answer+1（初值为0），最后返回answer。
