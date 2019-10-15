# Solution Walkthrough

___
The ex1.cpp contains a solution to the longest ordered subarray problem using dynammic programming.
sample input:  (8, 3, 6, 50, 10, 8, 100, 30, 60, 40, 80)
a possible valid output: (3, 6, 10, 30, 60, 80)
___
ex2.cpp contains a solution to the following problem using dynammic programming. The input is a triangle of positive integers of the interval [1, 10000]. The output should be the largest sum existent on a path from the number in the first line to the last line. Each number in the path is 'seated' on the left or right of the value above it. 
sample input :
```bash
4
8  2
3  1  9
5  7  1  3
6  5  4  5  2
```
The output would be:
```bash
27
4 8 3 7 5 
```
In the pdf there is an analysis of the runtime of the solution and a comparison to the brute force approach and why a greedy algorithm would fail to work for the problem. (When running press enter twice after ending the last row)
___
The ex3.cpp file containg my solution to the scuba diver problem. A link to the question(found in chegg) is given [here](https://www.chegg.com/homework-help/questions-and-answers/problem-3-scuba-diver-12-points-scuba-diver-uses-special-equipment-diving-cylinder-two-con-q29192931)