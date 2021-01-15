# Buying and Selling Stocks With Cooldown
This [problem](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) involves determining the maximum profit that can be obtained through buying and selling a stock given a list of the stock's prices over a number of days.
You can buy and sell the stock any number of times, however, after you have sold the stock you have to wait a day (cooldown) before you can purchase the stock again.
The problem has a neat O(n) solution, but first we'll go through an $O(n^2)$ solution that I reached on my own.

## Solution 1
The first solution involves using DP with focusing on the day you buy a stock and the day you sell a stock. 
We can let $opt(i, j)$ be equal to the maximum profit that can be obtained by buying the stock on day $i$ and selling the stock on day $j$ (including any previous transactions). 
We can thus iterate over all $i,j$ from $0..n-1$ and $i >= j$ where $n$ is the length of our input list. Each time we consider $opt(i, j)$ to be the profit obtained from selling the stock purchased on day $i$ on day $j$, plus the maximum profit obtained previously. Since we have $O(n^2)$ iterations, each taking $O(1)$ time, the total runtime of our solution in $O(n^2)$.

## Solution 2
Instead of considering all pairs of days when buying and selling the stock, instead consider the last action that occurs. There are one of three actions that can occur: we can buy the stock, we can sell the stock, or we can do nothing.
Of these three actions, there are some restrictions. 
We can never sell a stock if we do not currently own the stock, and we cannot buy the stock if on the previous day we sold the stock.
With these considerations in mind, we can define $opt(i, 0)$ to be the maximum profit achieved up through day $i$ where after day $i$ ends we no longer own the stock. 
We can define $opt(i, 1)$ to be the maximum profit achieved up through day $i$ where after day $i$ wenow own the stock. 
If we end day $i$ without the stock, then we could have started the day without the stock and done nothing,or we could have sold the stock on that day. The maximum of these two options is equivalent to the maximum profit achieved when ending day $i$ without the stock.
If we end day $i$ with the stock, then we could have started the day with the stock and done nothing, or we could have bought the stock on day $i$. The maximum of these options is equivalent to the maximum profit achieved when ending day $i$ with the stock.

Thus, we have that $opt(i, 0) = \max(opt(i-1, 0), opt(i-1, 1) + prices[i])$ and $opt(i, 1) = \max(opt(i-1, 1), opt(i-2, 0) - prices[i])$. Finally, we can define $opt(-1, 0) = opt(-1, 1) = 0$.

Using this recurrence we can solve the problem in $O(n)$ time, and even only have to use $O(1)$ space since we only keep track of three values $opt(i-1, 0)$, $opt(i-2, 0)$, and $opt(i-1, 1)$.

