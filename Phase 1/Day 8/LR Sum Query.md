# Description
Given an array of N integers and Q queries. In each query two integers L, R is given, you have to find (A[L] + A[L+1] + A[L+2] + A[L+3]...A[R]) % 10^9+7.
 

## Input Format
The first line contains two space-separated integers N, Q where 1<=N<=10^6, 1<=Q<=10^6.

Next line contains N space-separated integers (-1e9<=Ai<=1e9).

Next Q lines contain two space-separated integers L, R where 1<=L<=R<=N.

## utput Format
For each query print the value of (A[L] + A[L+1] + A[L+2] + A[L+3]...A[R]) % 10^9+7 in a new line.

### Sample Input
10 10
12 -23 -123 2345 2345 44 345 -93945 -5353 1
1 5
1 8
1 10
2 2
6 6
4 8
2 9
4 10
3 6
5 9

### Sample Output
4556
999911007
999905655
999999984
44
999911141
999905642
999905789
4611
999903443