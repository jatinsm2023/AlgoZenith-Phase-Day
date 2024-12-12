# Description
You are given the digits of a positive number N. Find the product of its digits. Since the product can be large, print it modulo 10^9 + 7. It is guaranteed that the number begins with a non-zero digit.

## Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the number of digits in the number. 

The second line of each test case contains N space-separated integers - the digits of the number.

## Output Format
For each test case, print the product of digits of the number modulo 10^9 + 7.

## Constraints
1≤ T ≤ 10^6

1≤ N ≤ 10^6

0≤ D ≤ 9

It is guaranteed that the sum of N over all test cases does not exceed 106.

### Sample Input
3
5
1 5 2 3 4
4
9 0 5 3
3
2 2 2


### Sample Output
120
0
8
