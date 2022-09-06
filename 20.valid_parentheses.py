class Solution:
    def isValid(self, s: str, stack=list()) -> bool:
        return (
            # obvious case of the win
            True if (len(s) == 0 and len(stack) == 0)
            # reached end of string but stack is not empty
            else False if (len(s) == 0 and len(stack) != 0)
            # Encountered opening brace - recurse one level deeper + add to stack
            else self.isValid(s[1:], [s[0]] + stack) if s[0] in ['(', '[', '{']
            # Encounter closing brace
            # 1. stack is empty -> no opening brace to match
            else False if len(stack) == 0
            # 2. stack is not empty, opening brace matches, recurse deeper and pop stack
            else self.isValid(s[1:], stack[1:]) if (s[0] == ')' and stack[0] == '(') or (s[0] == ']' and stack[0] == '[') or (s[0] == '}' and stack[0] == '{')
            else False
        )
        
s = Solution()
print(s.isValid("()"))
print(s.isValid("()[]{}"))
print(s.isValid("(]"))
print(s.isValid("([)]"))
print(s.isValid("{[]}"))
print(s.isValid("]"))
print(s.isValid("(("))
print(s.isValid("(("))


