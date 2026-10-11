#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Mar  4 02:01:54 2026

@author: awais
"""

from functools import reduce

nums = [1, 2, 3, 4, 5, 10]

my_double = lambda x : x * 2

greater = lambda x: x > 3
threes = lambda x : x % 3 == 0

# # MAP: Double every number
# doubled = list(map(my_double, nums))
# print("doubled after map", doubled)

# # FILTER: Only numbers > 3
# greater_than_three = list(filter(threes, nums))
# print("filtered list", greater_than_three)

# REDUCE: Sum of all numbers
total = reduce(lambda x, y: x * y, nums)
print("reduced:", total)


