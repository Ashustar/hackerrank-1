### Solution for [Weekly Challenges - Week 11](https://www.hackerrank.com/contests/w11)

#### Sherlock and Square

Simple Math. The answer is $2^{n+1} + 2$.

#### Strange numbers

A number $X$ with $length(X)≥1$ can also be considered strange if and only if

* $X$ is evenly divisible by $length(X)$
* the number $X/length(X)$ is recursively strange

Calculate the number of strange numbers in given range $[L, R]$.

As strange numbers are rather sprase, for a strange number $S$, if its length is $lenS$, it can directly derive number $S * (lenS + i \subset [0, 2])$ when the length of the new derived number is valid. Any longer numbers is impossible to generate directly by the number $S$.

So generate all number first (less than 300), then count the number.

#### Tree Pruning

Use at most $K$ remove operations (possibly zero) so that the total weight of the remaining vertices is largest.

Dynamic Programming. Use $DP[i][j]$ indicates the maximum weight on the subtree rooted at i with j remove operations used. Combine the value as knapsack problem. The complexity is $O(N*K*K)$, which is a little hight, but feasible for that problem.

While the tutorial offers a better and simple solution: consider the DFS sequence for the tree, a subtree rooted at i is a continuous subsequence in the DFS sequence started from i. So removing $K$ subtrees means remove $K$ continuous subsequence, of course the subsequence is determined and can be pre-calculated easily. Then a state $DP[i][j]$ can only tranform to $DP[i + 1][j]$ or $DP[i + size(subtree(i))][j + 1]$. So the complexity is optimized to $O(N*K)$.

#### Training the army

A very typical maximal flow problem. As in-going vertex and out-going vertex are both limited to use only once, so both of them need seperate into two vertices. And then each wizard is one level.

A better way is only view a wizard as a single point, and link to the point with in-going vertices with flow 1, and flow back to the out-goint vertices. Compare to the previous graph with $N * W + W * NW * 2$, it only contains $N + W$ points.

#### Two Array Problem

Though I didn't solve it, I know it just a Data Structure and Minimal Enclosing Circle problem, which is kind of boring.

As the tutorial suggests:

> For peroforming reverse and swaps it is really convenient to use the cartesian tree, also known as treap (tree + heap). 

Maybe if I keep solving algorithm puzzles, I have to learn it.