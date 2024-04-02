#!/usr/bin/python3
"""
    Script that solves the N queens problem
"""

import sys


if __name__ == "__main__":

    if len(sys.argv) != 2:
        print("Usage: nqueens N\n")
        exit(1)
    N = int(sys.argv[1])
    if not isinstance(N, int):
        print("N must be a number\n")
        exit(1)
    if N < 4:
        print("N must be at least\n")
        exit(1)

    board = [[0 for i in range(N)] for j in range(N)]


    def is_safe(board, row, col):
        """
            Check if a queen can be placed in board[row][col]
            :param board: list of lists containing the board
            :param row: row to check
            :param col: column to check
        """

        # check this row on left side
        for i in range(col):
            if board[row][i]:
                return False

        # check upper diagonal on left side
        for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
            if board[i][j]:
                return False

        # check lower diagonal on left side
        for i, j in zip(range(row, N, 1), range(col, -1, -1)):
            if board[i][j]:
                return False

        return True


    def solve_n_queens(board, col):
        # base case: if all queens are placed
        if col >= N:
            print_solution(board)
            return True

        solution_found = False
        # consider a column: trying place queen in all rows
        for i in range(N):
            if is_safe(board, i, col):
                # place this queen in board[i][col]
                board[i][col] = 1

                # recur to place rest of queens
                if solve_n_queens(board, col + 1):
                    solution_found = True

                # if placing queen in board[i][col] doesn't lead to a solution
                board[i][col] = 0

        # if queen can not be placed in any row in this col
        return solution_found


    def print_solution(board):
        """
            print board
        :param board: NxN board
        :return: position of queens
        """
        solution = []
        for i in range(N):
            for j in range(N):
                if board[i][j] == 1:
                    solution.append([i, j])
        print(solution)

    solve_n_queens(board, 0)
