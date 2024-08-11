## Description
You have a convex n-sided convex polygon where each vertex has an integer value v(i). You are given an integer array values where v[i] is the value of the ith vertex (i.e., clockwise order).

You will triangulate the convex polygon into n−2 triangles. For each triangle, the value of that triangle is the product of the values of its vertices, and the total score of the triangulation is the sum of these values over all n−2 triangles in the triangulation.

Output the smallest possible total score that you can achieve with some triangulation of the polygon.

## Input Format
First Line contains T - the number of test cases.
The First Line of each test case contains n - the number of vertices of the convex polygon.
The second line of each test case containsvn space-separated values v[i] of the vertices in clockwise order.

## Output Format
For each test case, Output the smallest possible total score that you can achieve with some triangulation of the polygon.

Constraints

- 1≤T≤10 
- 3≤n≤100
- 1≤v[i]≤10 
 
Sum of n over all test cases is ≤5000.