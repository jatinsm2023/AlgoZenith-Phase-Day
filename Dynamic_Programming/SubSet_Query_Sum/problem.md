### Description

Given an array of size NN, and QQ queries, for each query, you need to get the indices of the elements of the array whose subset-sum is equal to the queried sum sumisumi​, if possible, else return −1−1.

### Input Format

Complete the Function subset_queries( vector &arr, vector &queries ) that takes vector aa and queriesqueries vector as input.

### Output Format

Return a vector < vector < int > > having 00-based indices of the elements of the array whose subset-sum is equal to the queried sum sumisumi​ for each ithith query, if possible, else return vector { −1−1 }.

### Constraints

- 1≤N≤100   , size of vector < int > arr
- 1≤Q≤10^5   ,  size of vector < int > queries
- 1≤arr[i]≤10^5
- 1≤sumi​≤10^5


### Test Cases

#### Case 1
##### Input
5 3
1 2 3 4 5
7 16 3

##### Output
1
-1
1