class Solution:
    def longestDecomposition(self, text: str) -> int:
        output = 0

        right_start = len(text) - 1
        window = 1
        
        while True:
            if text[right_start] == text[0]:
                if text[:window] == text[right_start:] and right_start != 0:
                    output += 2
                    text = text[window:right_start] 
                    if not text:
                        break
                    window = 0
                    right_start = len(text)
                elif right_start == 0:
                    break
                    
            window += 1
            right_start -= 1

        return output if not text else output + 1