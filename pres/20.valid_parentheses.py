def isValid(self, s: str, l=list()) -> bool:
    """
    Recurse through the string, pushing and popping from the stack as needed.
    l: the stack
    s: string
    """
    return (
        # Case of win: stack is empty and string is empty
        True if (len(s) == 0 and len(l) == 0)
        # reached end of string but stack is not empty
        else False if (len(s) == 0 and len(l) != 0)
        # Encountered opening brace - recurse one level deeper + add to stack
        else self.isValid(s[1:], [s[0]] + l) if s[0] in ['(', '[', '{']
        # Everything below this is a closing brace
        # 1. stack is empty -> no opening brace to match
        else False if len(l) == 0
        # 2. stack is not empty, opening brace matches, recurse deeper and pop stack
        else self.isValid(s[1:], l[1:]) if (s[0] == ')' and l[0] == '(') or (s[0] == ']' and l[0] == '[') or (s[0] == '}' and l[0] == '{')
        # 3. stack is not empty, opening brace does not match
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


