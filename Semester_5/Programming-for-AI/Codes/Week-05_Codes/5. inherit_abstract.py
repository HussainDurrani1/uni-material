#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Mar 25 05:18:12 2026

@author: awais
"""

from abc import ABC, abstractmethod

class AIModel(ABC):
    @abstractmethod
    def train(self, data):
        """This is a pure virtual function equivalent"""
        pass

    def save_model(self):
        """Abstract classes can still have concrete methods"""
        print("Saving weights to disk...")

class NeuralNet(AIModel):
    def train(self, data):
        print(f"Training Neural Net on {len(data)} samples")

# model = AIModel() # Error! Cannot instantiate abstract class
nn = NeuralNet()
nn.train([1, 2, 3])
nn.save_model()