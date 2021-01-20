# Trapping Rain Water
This [problem](https://leetcode.com/problems/trapping-rain-water/) asks to determine the amount of rain water that is trapped via a given array of heights.

## Solution
This problem is a pretty well-known Leetcode problem. perhaps because of the multiple different approachs that can be taken to solve it.
Before we tackle the problem, we must consider first how water is trapped. 
Water is trapped at a given location so long as there is some height to the left and some height  to the right that is greater than the current height of that location.
So now we know that there are some key values in this problem, the current location's height, and the heights of the left and right boundaries that are higher than this current location.

For a given location, we can find the highest height to the left and to the right, and then use the minimum of these two values to figure out how much water is trapped at this location. By summing the values for all locations, we can get the total water that is trapped.
This can be done in $O(n)$ time using two array to the store the maximum height location to the left and to the right of every location.

Additionally, we can also try to use a monotonic stack to solve this problem. The monotonic stack approach involves creating a stack with a specific invariant that can be used to our advantage.
This invariant is either that the elements of the stack are in increasing order, or are in decreasing order.
The invariant for this stack is that every location below a given location in a stock has a higher height, and thus our stack is in increasing order from top to bottom.
Whenever we come upon a location that has a height greater than the current height at the top of the stack, we need to remove the top of the stack to maintain the invariant.
We know that the element second to the top of the stack must be greater than the element that we just removed, and thus the element that was just removed is bounded to the left by the current top of the stack, and is bounded to the right by the current height we are considering.
This allows us to determine the amount of water trapped at this location, and we then continue popping from the stack if necessary to maintain our invariant.
Finally, the current height is added to the stack.
This solution runs in $O(n)$ time with $O(n)$ space required for the stack.

Lastly, there is a clever two-pointer approach to this problem.
We can work our way towards the center of the heights array, considering the left and right boundaries as we work towards the center.
While we do so, we also consider the maximum left boundary and the maximum right boundary.
If the current left boundary is lower than the current right boundary, we either update the maximum left boundary, or we know that this location can trap some water.
Thus, we calculate the amount of water that this location traps, and continue on by incrementing the left boundary towards the center.
If the current left boundary is higher than the current right boundary, we consider the same as above, except this time for the right boundary.

This provides us with a solution in $O(n)$ time and $O(1)$ space.
