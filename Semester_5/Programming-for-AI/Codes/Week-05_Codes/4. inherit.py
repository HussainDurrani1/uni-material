#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Mar 25 05:15:32 2026

@author: awais
"""

class Sensor:
    def __init__(self, sensor_id):
        self.sensor_id = sensor_id

    def get_reading(self):
        return "Generic sensor reading: 0.0"

class ECG_Sensor(Sensor):
    # Overriding the parent method
    def get_reading(self):
        # We can call the parent method using super() if needed
        base_msg = super().get_reading()
        return f"ECG {self.sensor_id} Signal: 0.85mV (Base was: {base_msg})"

# --- Calling ---
generic = Sensor("S001")
ecg = ECG_Sensor("E99")

print(generic.get_reading()) # Generic sensor reading: 0.0
print(ecg.get_reading())     # ECG E99 Signal: 0.85mV (Base was: Generic...)