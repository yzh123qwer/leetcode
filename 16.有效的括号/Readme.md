# 基本思路
通过栈的方式来实现，将给出的字符段依次读取，如果是正向的括号，那么就推入栈中，如果是反向的括号，则需判断最近一次的正向括号，如果是同种的，则将两个括都推出，如果不是同种，
则直接返回false，最后如果栈中没有剩余的，则返回true，否则返回false。<br>
程序中以双向链表的形式来实现栈。
