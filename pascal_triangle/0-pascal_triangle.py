#!/usr/bin/python3
"""
    Pascal's triangle
"""


def pascal_triangle(n):
    """
        function to generate pascal's triangle of n

    :param n: integer

    :return: Pascal's triangle
    """
    if n <= 0:
        return []

    triangle = [[1]]

    for i in range(1, n):
        row = [1]  # begin each line by 1
        for j in range(1, i):
            # chaque valeur est la somme de deux valeurs au-dessus
            row.append(triangle[i-1][j-1] + triangle[i-1][j])
        row.append(1)  # chaque ligne se termine par 1
        triangle.append(row)

    return triangle
