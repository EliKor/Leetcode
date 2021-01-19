# Largest Number
This [problem](https://leetcode.com/problems/largest-number/) provides us with a list of numbers and asks what is the largest possible number that can be achieved by rearranging the numbers.

## Solution
We can begin our solution by considering a case where we have two numbers, $a$ and $b$. In this case there are only two ways to combine the numbers. Let $a.b$ denote the number formed by concatenating $a$ with $b$. Thus, we have just $a.b$ and $b.a$. 
To check which number is bigger when $a.b$ and $b.a$ are strings, we start at the first character in each and continue until there we reach a point where one character is greater than the other. 
At that point, we know the concatenation containing this greater character represents the larger number.
Note that whether $a.b$ forms a greater number than $b.a$ can determined simply by using the inequality operators that have been overloaded for strings.

The main crux of the solution is seeing that this relation of comparing two concatenated numbers is transitive, which allows this basic comparison to be used to sort each of the numbers in the list, and provide us with a list of numbers that can be concatenated to form our solution.

The transitivity of our concatenation comparison can be proven as follows. Consider three positive numbers $a$, $b$, and $c$. Let $digits(a)$ be the number of digits in the number $a$.
We can then define the concatenation $a.b$ as being equivalent to $a \times 10^{digits(b)} + b$. Now, assume that we have $a.b > b.a$ and $b.c > c.b$. 
To prove the transitivity of our comparison, we want to show that $a.c > c.a$.
Converting our assumptions into their equivalent mathematical forms we have:
$a \times 10^{digits(b)} + b > b \times 10^{digits(a)} + a$ and $b \times 10^{digits(c)} + c > c \times 10^{digits(b)} + b$. 

