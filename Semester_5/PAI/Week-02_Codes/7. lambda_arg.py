#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Mar  4 01:48:55 2026

@author: awais
"""

# Useful in sorting
points = [(1, 2), (4, 1), (9, 10), (13, -3)]
points.sort(key=lambda p: p[1]) # Sort by the second element (y-coordinate)

print(points)

# print only 1st value from tuple

# #using for
# for p in points:
#     print(p[0])
    
# #uing comprehension
# x_coords = [p[0] for p in points]
# print(x_coords)

# #using unpacking
# print(*(p[0] for p in points))