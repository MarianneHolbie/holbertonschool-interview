#!/usr/bin/python3
"""
    Module minoperations

"""


def minOperations(n):
    """
        function to define the fewest number of operations needed
        to result in exactly n H characters in the file.

        :param n: number

        :return: int or 0 if n is impossible to achieve
    """
    if n <= 1:
        return 0

    min_op = [float('inf')] * (n + 1)

    # initialize min_op, if one H is already in
    min_op[1] = 0

    # loop 2 to n
    for i in range(2, n + 1):
        for j in range(1, i // 2 + 1):
            if i % j == 0:
                min_op[i] = min(min_op[i], min_op[j] + i // j)

    return min_op[n]
