#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Mar 11 00:18:07 2026

@author: awais
"""

# def ensure_positive(func):
#     def wrapper(x):
#         if x < 0:
#             raise ValueError("Input must be positive!")
#         return func(x)
#     return wrapper

# @ensure_positive
# def calculate_log(x):
#     import math
#     return math.log(x)

# print(calculate_log(5))
# print(calculate_log(-5))

def ensure_range(func):
    def wrapper(x):
        if x < 3 or x > 7:
            raise ValueError("Input outside the defined range!")
        return func(x)
    return wrapper

@ensure_range
def my_special_fun(a):
    print(10*a)
    
my_special_fun(9)
