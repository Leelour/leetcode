#!/usr/bin/env python
#coding:utf-8

class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        return ' '.join(re.split('\s+', s.strip())[::-1])
