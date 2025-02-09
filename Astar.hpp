from heapq import heappush, heappop

def astar(start, goal, graph):
    """
    A* pathfinding algorithm implementation
    Args:
        start: Starting node
        goal: Target node
        graph: Dictionary containing nodes and their neighbors with costs
    Returns:
        path: List of nodes forming the shortest path
        cost: Total cost of the path
    """
    
    # Initialize data structures
    frontier = [(0, start)]  # Priority queue of (f_score, node)
    came_from = {start: None}  # Keep track of path
    g_score = {start: 0}  # Cost from start to current node
    f_score = {start: heuristic(start, goal)}  # Estimated total cost
    
    while frontier:
        current_f, current = heappop(frontier)
        
        if current == goal:
            # Reconstruct path
            path = []
            while current:
                path.append(current)
                current = came_from[current]
            return path[::-1], g_score[goal]
        
        for neighbor in graph[current]:
            tentative_g = g_score[current] + graph[current][neighbor]
            
            if neighbor not in g_score or tentative_g < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = tentative_g
                f = tentative_g + heuristic(neighbor, goal)
                f_score[neighbor] = f
                heappush(frontier, (f, neighbor))
    
    return None, None  # No path found

def heuristic(node, goal):
    """
    Heuristic function for A* (Manhattan distance)
    Assumes nodes are represented as (x, y) coordinates
    """
    return abs(node[0] - goal[0]) + abs(node[1] - goal[1])