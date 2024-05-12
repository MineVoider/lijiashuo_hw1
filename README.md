# 实现思路
本文主要是行列式、逆、秩的思路
## 一、矩阵的行列式
1. 递归函数  类似于分段函数 
$$
|\textbf{A}|=
\begin{cases} 
\sum_{j=1}^n (-1)^{i+j}a_{ij}|\textbf{A}_{ij}| & & {n\geq2}\\
a_{11}a_{22}-a_{12}a_{21} & & {n=2}\\
a_{11} & & {n=1}
\end{cases}
$$ 
2. 用 if else 语句实现分段函数
3. 代数余子式的值：
   1. 将第i，j行略过，当行数或列数超过时减1，从而实现与原矩阵对应关系
   2. 求$(-1)^{i+j}$：当i+j为奇数是，该式为-1，否则为1
   3. 求代数余子式的值：系数*det(代数余子式矩阵)
## 二、矩阵的逆
1. 排除零矩阵与非方阵矩阵
2. 定义伴随矩阵，伴随矩阵的行数与列数与原矩阵相同
3. 赋值伴随矩阵，$a^*_{ij}=(-1)^{i+j}|\textbf{A}_{ji}|$，即$a^*_{ij}$=第i行第j列代数余子式的值
4. 求矩阵的逆，数乘$\dfrac{1}{|\textbf{A}|}$与$\textbf{A}^*$即可
## 三、矩阵的秩
1. 函数初始化秩为矩阵行数和列数中较小的那个值：
$$
\text{int rank} = \min(m,n)
$$
2. 为了以列作为参考对象研究矩阵的秩，要保证矩阵的列数小于行数，即当列数大于行数时，矩阵转置
3. 矩阵秩减一的唯一标志：从第一列开始递增，每次从初始行开始，之后的每一行对应列的数为0时，矩阵的秩减1
   1. 初始行的数值与当前列的数值不同，开始时两者均为1(数组为第0个)只有当矩阵的秩保持不变(即从初始行开始往下至少有一个数不为0)时，初始行+1。否则不变(也就是说当矩阵的秩减1时，初始行与当前列就不同步了)
   2. 当存在从初始行开始往下的值不为0时，进行行交换(当初始行本身的值不为0时，可交换可不交换)，然后进行高斯消元，行运算的具体方式为：
   $$ R_j=R_j-\dfrac{a_{ji}}{a_{ii}}\times R_i $$
4. 最后返回矩阵的秩即可
## 附：本地演示图片![alt text](image.png)