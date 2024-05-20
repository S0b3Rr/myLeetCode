class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]: 
        output = []
        
        def dfs(current_list, idx, current_sum):
            if current_sum == n and len(current_list) == k:
                output.append(current_list)
                return
            if current_sum > n or len(current_list) > k:
                return
            for next_num in range(idx + 1, 10):
                dfs(current_list+[next_num], next_num, current_sum + next_num)
                
        dfs([], 0, 0)
        
        return output