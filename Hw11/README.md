# Solution Walkthrough

___
In the pdf first there is a proof that for a graph with negative weights, adding same amount of weight to all edges so that they all become possitive and then running dijkstra's algorithm is not a correct algorithm for finding the shortest path.
Then it explains how the last problem is formalized as a graph problem
___
The optimal_meet_point.cpp file contains a solution to the following problem: Imagine a graph s.t all verteces represent a city and all edges have the distance of the cities as weights. The output should be the optimal meeting point for 2 friends so that the sum of the distances that they both have to cover is minimal.
___
The puzzle.cpp file is my solution to the problem: Consider a n by n grid in which every entry contains a natural number. You start from the top left corner and have to go to the bottom right one to win and on each turn you can move in each direction a number of blocks on a single direction equal to the number in the position entry. The program finds the minimum nr of moves or no solution at all if there is not any.