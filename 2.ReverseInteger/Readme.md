# 基本思路
在对负数进行求余和除法的时候会多出一个负号，因此直接将负数转为正数，最后返回的时候，在加上一个负号即可。<br>
其次要对一些特殊的数进行特殊处理，程序中进判断0（不需要进行转换）和-2147483648（转换为正数后会发生溢出）。<br>
接下来是对数位的判断，对数位进行判断可以使得，当多次输入数位较少的数时，提高程序的总运行时间，程序中使用了不太好的办法（编写完成之后认为是可以改进的）。<br>
如果一个数的数位是10位数字，则需要判断转换之后是否会发生溢出，程序中大段语句都用于这个。
