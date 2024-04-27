class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        def dfs(i: int, j: int) -> int:
            if i == len(key):
                return 0
            
            if dp[i][j] != -1:
                return dp[i][j]
            
            min_steps = float('inf')
            for k in positions[key[i]]:
                steps_to_rotate = min(abs(j - k), len(ring) - abs(j - k))
                steps_to_press = 1
                steps_to_next = dfs(i + 1, k)
                total_steps = steps_to_rotate + steps_to_press + steps_to_next
                min_steps = min(min_steps, total_steps)
                
            dp[i][j] = min_steps
            return min_steps
        
        positions = defaultdict(list)
        for i, c in enumerate(ring):
            positions[c].append(i)
        
        dp = [[-1] * len(ring) for _ in range(len(key))]
        return dfs(0, 0)
