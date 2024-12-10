## Description
Given a bracket sequence with ‘?’ at some places, you need to find the number of ways you can replace ‘?’ with ‘(‘ or ‘)’ to form a regular bracket sequence. A bracket sequence is called regular if it is possible to obtain the correct arithmetic expression by inserting characters + and 1 into this sequence.

## Input Format
The first line of the input contains one integer t - the number of test cases. Then t test cases follow.

The first and only line of each test case contains a string with characters, ‘(‘, ‘)’ and ‘?’.

## Output Format
For each test case, print the number of ways to replace ‘?’ with ‘(‘ or ‘)’ to form a balanced bracket sequence mod 10^9+7.

## Constraints
- 1 ≤ t ≤ 10^5

- 1 ≤ n ≤ 10^3 where n is the length of the string.

It is guaranteed that the sum of n^2 over all test cases does not exceed 10^6.