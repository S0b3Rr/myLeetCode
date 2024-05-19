class Solution:
    def get_paired(self, s):
        if s == '(':
            return ')'
        elif s == '{':
            return '}'
        else:
            return ']'
        
    def isValid(self, s: str) -> bool:
        stack = []
        for char in s:
            if char in ['(', '[', '{']:
                stack.append(char)
            else:
                if stack and self.get_paired(stack[-1]) == char:
                    del stack[-1]
                else:
                    return False
        return (True if not stack else False) 