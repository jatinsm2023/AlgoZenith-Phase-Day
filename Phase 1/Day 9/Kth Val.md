# Description
You have been given an array A of N integers and M ranges. ith range is defined by the two integers li and ri, li≤ri.

Initially, array S is empty. For range i, add elements A[li],A[li+1]…..A[ri] in the array S. After adding all the elements in each of the range, sort the elements of S in ascending order.

You need to answer Q queries. Each query consists of a number K > 0. You have to find the Kth smallest element in S, i.e., the element at Kth position in sorted S.

It may be possible that the same element presents multiple times in S.

## Input Format
The first line of the input contains a single integer T - the number of test cases(1 ≤ T ≤ 10). Then T test cases follow.

The first line of each test case contains three integers N, M, and Q, (1 ≤ N, M, Q ≤ 10^5).

The second line contains N space-separated integers A1, A2,….,AN, the elements of the array A, (1≤Ai≤10^9).

Next M lines contain two space-separated integers li and ri - ith range, (1 ≤ li ≤ ri ≤ N).

The last line of a test case contains Q space-separated integers K1, K2,….,KQ, where Ki denotes the ith query. (1 ≤ Ki ≤ 10^18).

## Output Format
For each test case, print Q space-separated integers, where ith number denotes the answer of ith query. If the Kth value doesn't exist for a particular query, print -1.


### Sample Input
2
3 3 4
1 3 2
1 3
2 3
1 1
1 2 5 8
4 2 3
1 5 4 3
1 4
1 3
1 5 7

### Sample Output
1 1 3 -1 
1 4 5 
