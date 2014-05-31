#!/usr/bin/env python
#coding:utf-8

class Solution:
    # @param tokens, a list of string
    # @return an integer
    def evalRPN(self, tokens):
        stack = []
        for token in tokens:
            if token in ['+', '-', '*', '/']:
                b = stack.pop()
                a = stack.pop()
                #python division always round to negtive infinity
                stack.append(int(eval(str(float(a))+token+str(float(b)))))
            else:
                stack.append(int(token))
        return stack.pop()

if __name__ == '__main__':
    sol = Solution()
    print sol.evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"])
