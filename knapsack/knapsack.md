# Knapsack problems
The knapsack problem is a canonical DP problem that involves a knapsack with a weight limit, and a list of weights with corresponding values. The problem asks to determine the maximum value that can be obtained given the list of weights and the knapsack's weight constraint.
Note that the knapsack problem cannot be solved in true polynomial time since it's optimal complexity is reliant on value of the knapsack's weight constraint.

## Solution
We'll look at two different variants of the knapsack problem: the unbounded problem and the 0,1 problem.
For the unbounded problem, each weight can be used an infinite number of times. For the 0,1 problem, each weight can be used at most once.

First looking at the unbounded problem, we can determine what types of subproblems we would like to solve.
Here we focus in on our weight constraint, and see that if we know that maximum value for a knapsack with a smaller
weight than the one we are currently considering, we can use this knowledge to determine the solution for our knapsack.
Specifically, we can iteratively find the max values for every knapsack with lower weight capacity than our knapsack, 
and then figure out which of the weights we can add into these solutions to find the most optimal solution.

Thus, we'll interate from $0$ to $W$, where $W$ is the weight constraint for our knapsack. For each value $w$ between $0$ and $W$, we will determine the maximum valued knapsack with weight constraint $w$ by considering adding each of the $n$ possible weights to the backpack. Note that if we are considering adding weight $i$ to our backpack, we need to make sure that $w >= weights[i]$. If so, then we know that we can form a backpack of weight $w$ with value $opt[w-weights[i]] + values[i]$, where $opt$ is the array storing all of our solutions to the previous $w$ knapsacks.
Iterating over every possible weight we can add and taking the maximum of these values, we have found the maximum value for the knapsack with weight constraint $w$.
Thus, $opt[W]$ must be our solution.


The 0,1 problem involves a very similar way of thinking, however this time we must be careful to ensure that no weight is added twice to our knapsack. 
To do so, we first iterate over every weight value ($i$ in range $0$ to $n-1$), and then iterate over weight constraint value up to $W$ ($j$ in range $0$ to $W$). Thus, $opt(i, j)$ represents the maximum value that we can get considering weights $0$ to $i$ for the knapsack with weight constraint $j$. 
This time, instead of considering each possible weight per iteration, we only consider whether we should add in the weight $i$ to our previously found solutions. If we do add weight $i$, then the value of that knapsack is $opt(i-1, j-weight[i]) + values[i]$. If we don't add weight $i$, $opt(i, j) = opt(i-1, j)$.
Finally, we have that our solution is $opt(n, W)$.

Both solutions have a runtime of $O(nW)$, and can have a space complexity of $O(W)$ through some clever iteration directions for the 0,1 problem.
This clever iteration change relies on the fact that we only need to keep track of the results from the previous iteration. Notice how in the code we never have $i-2$, but rather just $i$ and $i-1$.
Next, we can notice that we are only ever accessing values for the weight capacity that are less than the current weight capacity that we are considering (since we only ever consider $w - weights[i]$ or $w$).
Thus, our $opt$ array only needs to be a single row of length $W$.
