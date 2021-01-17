# General Thoughts on Approaching DP Problems
* Main goal is to define some recurrence
    * Base cases can sometimes be the trickiest aspect so define them carefully
* Think about what "actions" are being done in the problem, and the different actions that can occur at each step
    * e.g. in the Best Time to Buy and Sell A Stock problem, you can either buy, sell, or hold
    * A lot of this is simply binary, either do the action or do nothing
* Think about whether you can define subproblems over ranges of the input
* Try focusing solely on the first or last step of the problem
    * e.g. In Burst Balloons, you want to focus on the last balloon that you pop
* Decide on whether a top-down or bottom-up approach would be easier to implement/makes most sense
    * When working on a bottom-up approach, take care to calculate your subproblems in the right order

