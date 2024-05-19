class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        table1 = {}
        table2 = {}
        for idx, text in enumerate(list1):
            table1[text] = idx
        for idx, text in enumerate(list2):
            if table1.get(text) is not None:
                table2[text] = idx + table1.get(text)
        min_sum = 9999
        output = []
        for key, val in table2.items():
            if val < min_sum:
                min_sum = val
                output = []
                output.append(key)
            elif val == min_sum:
                output.append(key)
            else:
                continue
        return output