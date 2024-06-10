#!/usr/bin/python3
"""
Function to rotate a 2D matrix 90 degrees clockwise
"""


def rotate_2d_matrix(matrix):
    """
        Function to rotate a 2D matrix 90 degrees clockwise
        Args:
            matrix: 2D matrix to rotate
        Returns: transposed matrix
    """
    # store the length of the matrix
    n = len(matrix)

    # number of layers in the matrix
    for i in range(n // 2):
        # actual rotation of the matrix
        for j in range(i, n - i - 1):
            # store the current element
            temp = matrix[i][j]
            # replace the current element with the element at
            # the bottom left
            matrix[i][j] = matrix[n - 1 - j][i]
            # replace the element at the bottom left with the element
            # at the bottom right
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j]
            # replace the element at the bottom right with the element
            # at the top right
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i]
            # replace the element at the top right with the current
            # element
            matrix[j][n - 1 - i] = temp

    return matrix
