# Notes of Data Structure #

##  Sample of the Course ##

### Part1:  ###



##  Assignments ##

### Ex8  ###
**Question**:
 求下圖稀疏矩陣的壓縮陣列表示法。

**Answer**
$$
\begin{bmatrix}
0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
0 & 0 & 0 & 0 & 0 & 0 & 6 & 0 & 0 & 0 \\
0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
0 & 0 & 0 & 0 & 8 & 0 & 0 & 0 & 0 & 0 \\
0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
0 & 3 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
\end{bmatrix}
$$

**Description**

稀疏矩陣是在一個矩陣中，不為0的數值佔比。

Note:
$$
PascalLike[i, j] = B + n * (i - x) * d + (j - y) * d
\\
\
\\
FortranLike[i, j] = B + (i - x) * d + m + (j - y)* d 
$$

### Ex12  ###
**Question**:
陣列（Array）是以PASCAL語言來宣告，每個陣列元素佔用**4**個單位的記憶體。若起始位址是255，在下列宣告中，所列元素存放位置為何？
  1. VarA = array[-5...1,1...55]，求 $A[1,12]$ 之位址。
  2. VarA = array[5...20, -10...40] ，求 $A[5,-5]$ 之位址。

**Answer**
1. 從敘述來看，這是個二維陣列。 $-5$ 到 $1$ 共 6。 $1$ 到 $55$ 共 54。
需求 $A[1,12] = 255+ 1 * (1-0) * 4 + *()$


**Description**

### Ex13  ###
**Question**:
假設我們以FORTRAN語言來宣告浮點數陣列 $A[8][10]$ ，且每個陣列元素佔用**4**個單位的記憶體。如果 $A[0][0]$ 的起始位址是200， 則元素 $A[5][6]$ 的位址為何？

**Answer**

**Description**

### Ex14  ###
**Question**:
假設有一三維陣列宣告為 $A(1:3, 1:4, 1:5)$， $A(1, 1, 1)=300$ 且 $d=1$ ， 試問以行為主的排列方式下，求出 $A(2, 2, 3)$ 的所在位址。

**Answer**

**Description**

### Ex15  ###
**Question**:
有一個三維陣列 $A(-3:2, -2:3, 0:4)$ ，以Row-major 方式排列，陣列之起始位址1118，試求 $Loc(A(1, 3, 3))=?$ $(d=1)$

**Answer**

**Description**

### Ex18  ###
**Question**:
請使用多項式的兩種陣列表示法來儲存 $P(x) = 8x^5 + 7x^4 + 5x^2 + 12$ 。

**Answer**

**Description**

### Ex19  ###
**Question**:
如何表示與儲存多項式 $P(x, y) = 9x^5 + 4x^4 y^3 + 14x^2y^2 + 13xy^2 + 15$ ？試說明之。

**Answer**

**Description**