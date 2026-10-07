#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Mar  4 01:27:40 2026

@author: awais
"""

names = ["Ali", "Sara", "Ahmed"]
roll_nos = [101, 102, 103]
marks = [85, 92]

for name, roll, mark in zip(names, roll_nos, marks):
    print(f"Student {name} (ID: {roll}) scored {mark} marks.")