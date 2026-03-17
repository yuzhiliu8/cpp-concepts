from collections import deque
from typing import List

"""
Should use BFS
    if in a minute there is no change from a fresh orange to rotten, then queue will be empty, can stop
    if boolean never flipped, then stop
    if there exists a fresh orange --> return -1. If no fresh orange, then return current time - 1

how to keep track of time?
push orange (r, c) tuple and time for every orange
"""


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        self.m = len(grid)
        self.n = len(grid[0])
        q = deque()

        drc = [(1, 0), (0, 1), (-1, 0), (0, -1)]

        time = 0
        for r in range(self.m):
            for c in range(self.n):
                if grid[r][c] == 2:
                    q.append((r, c))
                    q.append(time)

        while len(q) > 0:
            r, c = q.popleft()
            time = q.popleft()

            for dr, dc in drc:
                if self.is_valid(r + dr, c + dc) and grid[r + dr][c + dc] == 1:
                    grid[r + dr][c + dc] = 2
                    q.append((r + dr, c + dc))
                    q.append(time + 1)

        for r in range(self.m):
            for c in range(self.n):
                if grid[r][c] == 1:
                    return -1

        return time

    def is_valid(self, r, c):
        return 0 <= r < self.m and 0 <= c < self.n
