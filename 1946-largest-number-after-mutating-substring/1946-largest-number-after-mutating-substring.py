class Solution:
    def maximumNumber(self, num: str, change: List[int]) -> str:
        changed = False
        for idx, val in enumerate(num):
            if int(val) < change[int(val)]:
                num = num[:idx] + str(change[int(val)]) + num[idx + 1:]
                changed = True
            elif changed and int(val) > change[int(val)]:
                break
        return num