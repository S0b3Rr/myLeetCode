class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        table = {}
        for num in nums:
            if table.get(num) is None:
                table[num] = 0
            table[num] += 1
        output = []
        for _ in range(k):
            count = -1
            it = 0
            for key, val in table.items():
                if val > count:
                    count = val
                    it = key
            output.append(it)
            table[it] = 0
        return output