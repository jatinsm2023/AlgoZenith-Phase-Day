# Description
There are N students and ith student likes all numbers in the range [li ,ri ], both inclusive. A number is good if it is liked by at least K students.

You are even Q queries. Each query consists of two numbers L, R. You have to find how many numbers in the range [L,R] is good.

## Input Format
The first line of input contains three integers, N, K (1 ≤ K ≤ N ≤ 1000000), and Q (1 ≤ Q ≤ 1000000).

The next N lines contain two integers li and ri (1 ≤ li ≤ ri≤ 1000000), describing that the i-th student likes all the numbers [li,ri].

The next Q lines contain L and R, (1 ≤ L ≤ R ≤ 1000000).

## Output Format
For each query print how many numbers in the range [L,R] is good in a new line.


### Test Case 1 
10 3 10

1 5

2 7

3 9

1 5

3 8

4 10

7 10

8 8

5 5

6 7

1 5

3 8

4 9

3 10

2 6

3 9

7 7

5 5

8 8

3 7

### Output 

4

6

6

7

5

7

1

1

1

5