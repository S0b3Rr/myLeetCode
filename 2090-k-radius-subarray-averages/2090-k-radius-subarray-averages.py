class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        #空間換時間
        
        _sums = [0]
        
        for i in range(len(nums)):
            _sums.append(_sums[i]+nums[i])
        output = [-1 if i < k or i + k >= len(nums) else ((_sums[i + k + 1] -_sums[i - k])//(2 * k + 1)) for i in range(len(nums))]
        
        return output