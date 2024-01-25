#!/usr/bin/python3
"""
    Module minoperations
    function to define the fewest number of operations needed
    to result in exactly n H characters in the file.

"""

import numpy as np

def minOperations(n):
    """
        function to define the fewest number of operations needed
        to result in exactly n H characters in the file.

        :param n: number

        :return: int or 0 if n is impossible to achieve
    """
    if n <= 1:
        return 0

    min_op = []

    for i in range(2, n**2 + 1):
        while n % i == 0:
            min_op.append(i)
            n //= i
    if n > 1:
        min_op.append(n)

    return np.sum(min_op)
