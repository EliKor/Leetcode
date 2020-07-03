I spent days trying to figure this out, got a very slow passing solution, and ultimately looked at the solution (which is actually very simple).
All solutions that I write about take O(1) space. For the brute force approach, simply iterate through each element and compare, taking O(mn) time.
Since the matrix is sorted and we are doing a search, a variant of binary search seemed like a good idea.

My slow passing solution took O(m*log n) time by simply doing binary search on each row.

I spent a long time thinking about the properties of the matrix, but the most crucial property is that when an element is too big, all elements below
and to the right of that element will also be too large. 
Conversely, if an element is too small, all elements above and to the left of the element will also be too small.
So, we can have a bound to the right and a bound from above that we can visualize as we walk through the array. 

We start on the top row and at the rightmost element because we need to ensure that when we are excluding elements (by either going down or left)
we are doing so justifiably. Moving to left effectively eliminates all elements right of the current element, so all of these elements must be too large.
Moving to down effectively eliminates all elements above the current element, so all of these elements must be too small.
By starting in the top right corner of the array, we are able to ensure that this invariant holds with each iteration.
We then check each element against the target and conduct our own form of a binary search, 
moving to the left if the current element is too big, and moving down if the element is too small.
If we reach past the edge of the matrix then the element does not exist in the matrix, so we exit the loop and return false.
This solution takes O(m+n) time.

Key insight:
Use the array structure to your advantage. This is easily seen by the fact that the array is sorted, but the properties about the elements in 2D are slightly more subtle.
