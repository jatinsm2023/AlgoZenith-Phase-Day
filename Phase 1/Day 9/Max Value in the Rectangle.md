# Description
Given a 2d-array of dimension N*M and Q queries. In each query five integers x1, y1, x2, y2, C is given, you have to increase the value of each cell in the submatrix with (x1,y1) be the leftmost corner and (x2,y2) be the rightmost corner by C. Initially the value of all the cell of the 2d-array is 0.

After all the query is performed, print the maximum value present in the 2d-array and the number of the cell with the maximum value.

## Input Format
The first line contains three space-separated integers N, M, Q where 1<=N, M<=10^3, 1<=Q<=10^6.

The next Q lines contains five space separated integers x1, y1, x2, y2, C where 1<=x1<=x2<=N, 1<=y1<=y2<=M, -10^9<=C<=10^9.

## Output Format
After all the query is performed, print 2 space-separated integers representing the maximum value present in the 2d-array and the number of the cell with the maximum value.

### Sample Input

5 5 5

1 1 2 2 -8

1 2 3 4 9

2 3 3 3 -2

4 4 4 4 -4

2 3 2 4 0


### Sample Output

9 5