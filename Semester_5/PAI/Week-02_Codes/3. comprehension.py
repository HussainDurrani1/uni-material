#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Mar  4 00:51:56 2026

@author: awais
"""

# List Comprehension: Square of even numbers
squares = [x**2 for x in range(10) if x % 2 == 0]
print(squares)

# Dictionary Comprehension: Mapping names to lengths
names = ["Ali", "Ahmed", "Sara"]
name_len = {n: len(n) for n in names}
print(name_len)

