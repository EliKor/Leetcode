# Decode Ways
This is [problem](https://leetcode.com/problems/decode-ways/) asks to determine the number of ways that a string of digits can be decoded by mapping the characters 'A'-'Z' to 1-26.

## Solution
This problem can be solved in $O(n)$ time using DP, where $n$ is the size of the input string. The problem would be pretty straight forward if not for the zeros, but regardless has a straight-forward solution.

We define a recurrence $opt(i)$ where $opt(i)$ is the number of ways to decode the message $s$ from $0..i$ exclusive. We see that if our current digit that we are considering is a 0, then we cannot leave this character on its own. So, there are initially $0$ ways to decode the message. Otherwise, we can keep the digit separate from all other digits, and start out with $opt(i-1)$ different ways to decode the message. Now, if we are able to include this digit with the previously considered digits we can add $opt(i-2)$ different ways to decode the message, since we have now decoded a brand new final character and can append this to all previous different decodings. Thus, we have four separate cases for $opt(i)$. 

If $s[i-1] = 0$ and $s[i-2]$ is $1$ or $2$, we have $opt(i) = opt(i-2)$. 

If $s[i-1] = 0$ and $s[i-2]$ is not $1$ or $2$, we have $opt(i) = 0$ ways to decode the message since it is invalid (the single digit 0 does not map to anything). 

If $s[i-1] \neq 0$ and $s[i-2]$ is $1$ then we have $opt(i) = opt(i-1) + opt(i-2)$. If $s[i-2]$ is $2$ and $s[i-1] < 6$ then we also have $opt(i) = opt(i-1) + opt(i-2)$

Otherwise, we have $opt(i) = opt(i-1)$.
