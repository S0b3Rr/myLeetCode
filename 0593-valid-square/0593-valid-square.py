class Solution:
    def get_distance(self, p1, p2):
        return sqrt(pow((p1[0] - p2[0]), 2) + pow((p1[1] - p2[1]), 2))
        
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        if p1 == p2 or p1 == p3 or p1 == p4 or p2 == p3 or p2 == p4 or p3 == p4:
            return False
        
        return len(set([
            self.get_distance(p1, p2), self.get_distance(p1, p3), self.get_distance(p1, p4),
            self.get_distance(p2, p3), self.get_distance(p2, p4),
            self.get_distance(p3, p4),
        ])) == 2
