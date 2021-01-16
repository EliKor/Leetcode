# Word Break
## The first Word Break problem
This [problem](https://leetcode.com/problems/word-break/) asks to determine whether a given string $s$ of size $n$ can be broken into the one or more of the words contained in a list of words $wordDict$.

The solution to this problem involves keeping track of the furthest that one can build up to in $s$ using the words found in $wordDict$. 
Thus, starting at index 0, substrings of increasing length are tested to see if they are contained within $wordDict$. 
If they are, then we mark the last position of the substring as being "reachable", and continue. 
If we get to a point where the final character of $s$ is "reachable" then we have determined that $s$ can be broken into one or more of the words contained in $wordDict$.
In my implementation, `up_to[i]` represents whether we are able to "reach up to" index $i$ in $s$ by using a word/words in $wordDict$. Thus, we can return `up_to[n]`.

## The second Word Break problem
This [problem](https://leetcode.com/problems/word-break-ii/) is very similar to the first, however this time we want to keep track of all of the possible solutions to the problem. This can be done using a very similar approach as in the first problem, but can also be solved using memoized-DFS.
We again try to determine how far we can "reach" in $s$ with the words in $wordDict$, however instead of continuing to iterate through all of the substrings of $s$, we try to follow the path of the current solution that we have found.
Thus, if we have found that some prefix of $s$ is equivalent to a word in $wordDict$, we may continue by seeing if we can build the corresponding suffix with the words in $wordDict$. 
By memoizing this process, we can efficiently navigate our way through the different solutions without having to do any redundant traversals. This way if we ever run into the same suffix twice, we won't have to calculate the solution for this suffix twice.

