#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Mar  4 01:25:25 2026

@author: awais
"""

names = ["Ali", "Sara", "Ahmed"]
roll_nos = [101, 102, 103]
marks = [85, 92, 78]

# Merging into a list of tuples
combined = list(zip(names, roll_nos, marks))

print(combined)
# Output: [('Ali', 101, 85), ('Sara', 102, 92), ('Ahmed', 103, 78)]