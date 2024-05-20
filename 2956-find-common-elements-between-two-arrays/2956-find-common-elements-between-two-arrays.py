class Solution:
    def findIntersectionValues(self, nums1: List[int], nums2: List[int]) -> List[int]:
        d1 = set()
        d2 = set()
        c1 = c2 = 0

        for i in nums1:
            d1.add(i)

        for i in nums2:
            d2.add(i)
            if i in d1:
                c2+=1
        
        for i in nums1:
            if i in d2:
                c1 += 1

        if c1 and c2:
            return [c1, c2]
        return [0, 0]