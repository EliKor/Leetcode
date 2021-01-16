Since the array is sorted and this is a search problem, we know that we should be using some form of binary search.
The main idea is deciding when we need to "break out" of our current section.
We can compare ```nums[lo]```, ```nums[mid]```, ```nums[hi]```, and ```target``` to find the appropriate information we need to make this decision.
Comparing ```nums[mid]``` with ```nums[lo]``` can tell us if there are greater values on the left side of the array.
Comparing ```nums[mid] ``` with ```nums[hi]``` can tell us if there are lesser values on the right side of the array.

Whenever ```nums[mid] < target``` we usually need to be focusing on the right subarray.
The exception is when there are larger elements to the left, and the highest value of the current section isn't big enough.
In this case, ```nums[lo] > nums[mid]``` and ```target > nums[hi]```.

Whenever ```nums[mid] > target``` we usually need to be focusing on the left subarray.
The exception is when there are smaller elements to the right, and the lowest value of our current section isn't small enough.
In this case, ```nums[hi] < nums[mid]``` and ```target < nums[lo]```.

These exceptions can be added to the typical binary search algorithm to come up with the solution.
