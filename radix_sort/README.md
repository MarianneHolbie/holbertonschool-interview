# Radix Sort

Radix sort is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping keys by the individual digits which share the same significant position and value. A positional notation is required, but because integers can represent strings of characters (e.g., names or dates) and specially formatted floating point numbers, radix sort is not limited to integers.

## Algorithm

1. Find the maximum number to know number of digits
2. Do counting sort for every digit. Note that instead of passing digit number, exp is passed. exp is 10^i where i is current digit number
3. Counting sort is stable sort. So, the order of elements with the same value is maintained.

## Complexity

- Time complexity: O(nk) where n is the number of elements in input array and k is the number of digits in the maximum number

- Space complexity: O(n+k)

## References

- [Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
