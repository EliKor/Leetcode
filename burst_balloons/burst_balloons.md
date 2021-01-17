# Burst Balloons
This [problem](https://leetcode.com/problems/burst-balloons/) provides you with a list of $n$ balloons, where each balloon is labeled with some number. Note that in the Leetcode problem the provided array is called $nums$, however I will be calling it $labels$.
These labels allow you to define a rule for how many coins you receive when you pop the ith balloon as:
label[i-1] * label[i] * label[i+1], where label[-1] = label[n+1] = 1.
The problem asks to determine the maximum number of coins you can receive from popping all of the balloons.

## Solution 1 (Exponential)
The solution that I came up with was to determine all of the subsets of the list of balloons, memoize the number of coins received from popping this subset, using these scores to determine the maximum coins possible for popping the total set of balloons. My implementation ended up taking $O(2^n n^2)$ time due to having to generate every subset (2^n) and popping each balloon in the subset (O(n^2) because of erasing the balloon from the subset each time it was popped). This solution is pretty straightforward since we a simply exhausting the solution set, however it is way too slow.

# Solution 2 (Cubic)
The tricky part for me about determining a better DP solution was because I could not figure out how to split the problem into subproblems that would be independent of one another. 
For example, if we consider popping a single balloon, we cannot treat all balloons before this balloon as a subproblem and all balloons after this balloon as another subproblem, since both of these subsets now border one another (and thus can affect one another). S
o, we are left with again considering subsets of the balloons as a subproblem and are again headed towards the exponential solution above. 

However, what if we instead focus on the last balloon to be popped in range of balloons. 
Let's say that the balloon $last$ is the last balloon to be popped in some range of balloons $i$ to $j$. 
Well, we now know that all of the balloons from $i$ up to $last-1$ and from $last+1$ to $j$ share the same border balloon, $last$. 
We also know that all of the balloons in $i$ to $last-1$ and $last+1$ to $j$ will be popped before $last$ is popped, so this bordering balloon will be present for the entirety of the time that there are balloons in the range $i$ to $j$. 
With this common border established, it is now safe to consider balloons $i$ to $last-1$ as a subproblem and $last+1$ to $j$ as another subproblem. 
Whereas before we had to worry about these two subproblems affecting one another, the balloon $last$ now serves as a buffer between them.
The final aspect to consider is how we determine the number of coins we get from popping $last$.
Since we have assumed that $last$ is the last balloon in the range to be popped, by the time it is popped its neighbors must be balloon $i-1$ and $j+1$.
Finally, we have a recurrence that we can work with.
We define $opt(i, j)$ as being the maximum number of coins that we can achieve from popping the balloons in the range $i$ to $j$ (inclusive). Our base case is just a range containing a single balloon, whose value is simply the label on that balloon.
So, $opt(i, i) = label[i]$.
For an arbitrary $i$ and $j$, we can use our finding from above in considering the last balloon to pop in the range.
From this we have:
$opt(i, j) = max(opt(i, last-1) + opt(last+1, j) + (label[i-1] * label[last] * label[j+1]) \foreach last \in \{i..j\})$.
Finally, we have formally defined a recurrence that we can use to solve the problem, and do so in $O(n^3)$ time.
