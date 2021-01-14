# Max Product Subarray
The [max product subarray problem](https://leetcode.com/problems/maximum-product-subarray/) involves finding the maximum product that can be obtained by multiplying continguous elements of a given array. The problem is very similar to the max sum subarray problem, and thus their solutions share many similarities.

## Solution 1

The first solution to the problem solves the problem in $O(n)$ time thanks to a key insight. However, first notice that whenever a zero is encountered in an array, we should always restart our process of finding the maximum product subarray by continuing with the next non-zero element. Thus, we can treat elements between zeros as being in their own arrays.

Now, the key insight is that the maximum product of an array without zeros must include either the very first element of the array, or the very last element of the array (or both). This can be proved by contradiction. Assume that neither the first nor the last element of the array is used in the maximum product. We can continue by breaking into two cases: this maximum product is negative or this maximum product is positive. 

If the maximum product is negative and the first element is positive, then the first element by itself would be the maximum product, a contradiction. If the first element is negative, then it could be multiplied by the maximum product and produce an equal to or greater value, another contradiction. The same holds for the last element.

If the maximum product is positive and the first element is positive, then it could be mulitplied by the maximum product to produce a greater value, a contradiction. The same holds for the last element. Finally, if both the first and last elements are negative, then including both of these values would yield a positive product, which would have to be equal to or greater than the maximum product, another contradiction.

Thus, the solution involves keeping track of the prefix and suffix product of the array, where we are constantly resetting these values to the next non-zero value when we encounter zero, or otherwise including the next value in the prefix/suffix. By iteratively adding the values of the array to the prefix and suffix, and updating our max product during each iteration, we must find the maximum product.

## Solution 2

The second solution solves the problem in $O(n \log n)$ time and relies on a divide-and-conquer approach. Simply divide the array in half, finding the maximum product in the left half and right half. Next, find the maximum product that spans across these halves. The tricky part with finding this spanning maximum product is that it could be the result of the product of the minimum spanning products as you go to the left and as you go to the right. Finally, the maximum of these left, right, and spanning products must be the maximum product.
