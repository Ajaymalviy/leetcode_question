from queue import Queue

class Solution:
    def numSquares(self, n: int) -> int:
        # Function to generate all perfect squares up to n
        def generateSquares(n):
            squares = []
            i = 1
            while i * i <= n:
                squares.append(i * i)
                i += 1
            return squares
        
        # Initialize a queue for BFS and a set to keep track of visited numbers
        queue = Queue()
        visited = set()
        
        # Start from n and add it to the queue with step count 0
        queue.put((n, 0))
        
        while not queue.empty():
            current, steps = queue.get()
            
            # Explore all possible perfect squares less than or equal to the current number
            for square in generateSquares(current):
                next_num = current - square
                
                # If the next number becomes 0, we have found a combination
                if next_num == 0:
                    return steps + 1
                
                # If the next number is not visited, add it to the queue with updated step count
                if next_num not in visited:
                    queue.put((next_num, steps + 1))
                    visited.add(next_num)
        
        # If no solution is found, this line should not be reached
        return -1

# Example usage:
solution = Solution()
result = solution.numSquares(12)
print(result)
