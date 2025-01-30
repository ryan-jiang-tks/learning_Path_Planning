#not a big deal
import numpy as np
from typing import List, Tuple

class PathPlanner:
    def __init__(self):
        self.grid = None
        self.start = None
        self.goal = None
    
    def set_grid(self, grid: np.ndarray):
        """Set the occupancy grid for path planning"""
        self.grid = grid
    
    def a_star(self, start: Tuple[int, int], goal: Tuple[int, int]) -> List[Tuple[int, int]]:
        """Basic A* path planning algorithm"""
        if self.grid is None:
            raise ValueError("Grid not set")
            
        self.start = start
        self.goal = goal
        
        # Initialize data structures
        open_set = {start}
        came_from = {}
        g_score = {start: 0}
        f_score = {start: self._heuristic(start)}
        
        while open_set:
            current = min(open_set, key=lambda x: f_score.get(x, float('inf')))
            
            if current == goal:
                return self._reconstruct_path(came_from, current)
                
            open_set.remove(current)
            
            for neighbor in self._get_neighbors(current):
                tentative_g_score = g_score[current] + 1
                
                if tentative_g_score < g_score.get(neighbor, float('inf')):
                    came_from[neighbor] = current
                    g_score[neighbor] = tentative_g_score
                    f_score[neighbor] = g_score[neighbor] + self._heuristic(neighbor)
                    open_set.add(neighbor)
        
        return []  # No path found
    
    def _heuristic(self, pos: Tuple[int, int]) -> float:
        """Manhattan distance heuristic"""
        return abs(pos[0] - self.goal[0]) + abs(pos[1] - self.goal[1])
    
    def _get_neighbors(self, pos: Tuple[int, int]) -> List[Tuple[int, int]]:
        """Get valid neighboring positions"""
        neighbors = []
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # 4-connected grid
        
        for dx, dy in directions:
            new_pos = (pos[0] + dx, pos[1] + dy)
            if (0 <= new_pos[0] < self.grid.shape[0] and 
                0 <= new_pos[1] < self.grid.shape[1] and 
                self.grid[new_pos] == 0):  # 0 represents free space
                neighbors.append(new_pos)
        
        return neighbors
    
    def _reconstruct_path(self, came_from: dict, current: Tuple[int, int]) -> List[Tuple[int, int]]:
        """Reconstruct path from came_from dictionary"""
        path = [current]
        while current in came_from:
            current = came_from[current]
            path.append(current)
        return path[::-1]

# Example usage
if __name__ == "__main__":
    # Create a simple grid (0 = free space, 1 = obstacle)
    grid = np.zeros((10, 10))
    grid[2:4, 2:8] = 1  # Add some obstacles
    
    planner = PathPlanner()
    planner.set_grid(grid)
    path = planner.a_star((0, 0), (9, 9))
    print(f"Found path: {path}")