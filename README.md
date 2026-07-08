# smart-environmental-monitoring-system

## Overview

Arduino-based smart room monitoring system that collects environmental data and responds to changes in its surroundings. The system uses multiple sensors to measure temperature, humidity, light level, and motion, then displays the information on an LCD screen and controls an LED based on the conditions detected.


## Features

**Temperature Monitoring**

  * Uses a DHT11 sensor to measure room temperature

**Humidity Monitoring**

  * Uses the DHT11 sensor to measure humidity levels

**Light Detection**

  * Uses a photoresistor to determine whether the environment is bright or dark

**Motion Detection**

  * Uses a PIR motion sensor to detect movement

**Automatic Night Light**

  * Turns on an LED when the environment is dark and motion is detected

**LCD Display**

  * Displays real-time sensor information


## Components Used

* Arduino Uno R3
* DHT11 Temperature and Humidity Sensor
* 16x2 LCD Display
* Photoresistor (LDR)
* PIR Motion Sensor
* (1) blue LED
* 220Ω Resistor
* 10kΩ Resistor
* Potentiometer
* Breadboard
* (~25)Jumper Wires


## How It Works

The Arduino reads data from each sensor:

1. The DHT11 measures temperature and humidity
2. The photoresistor measures light intensity
3. The PIR sensor detects motion
4. The Arduino processes the sensor readings
5. The LCD displays the current environment conditions
6. If the room is dark and motion is detected, the LED turns on automatically

The system follows this logic:

Dark + Motion Detected → LED ON

Bright OR No Motion → LED OFF


## Wiring Summary

### LCD Display

* RS → D12
* E → D11
* D4 → D5
* D5 → D4
* D6 → D3
* D7 → D2

### DHT11 Sensor

* VCC → 5V
* GND → GND
* DATA → D7

### Photoresistor

* Connected to analog pin A0 using a voltage divider with a 10kΩ resistor

### PIR Motion Sensor

* VCC → 5V
* GND → GND
* OUT → D8

### LED

* Positive leg → D9 through 220Ω resistor
* Negative leg → GND


## Challenges and Solutions

### LCD Wiring

Problem: The LCD initially showed blank screens or blocks.

Solution: Checked the wiring and adjusted the potentiometer to control LCD contrast.

### Sensor Integration

Problem: Individual sensors worked separately but needed to work together.

Solution: Combined the sensor code into one Arduino program and assigned each component its own pin.

### Light Detection

Problem: The photoresistor threshold was different from example tutorials.

Solution: Tested sensor values and adjusted the light threshold to match the environment.

### PIR Sensor

Problem: Motion detection required troubleshooting due to different PIR module designs.

Solution: Tested the sensor separately before integrating it into the final system.


## What I Learned

* How to read data from multiple sensors
* How to control outputs based on sensor conditions
* How embedded systems combine sensors, processing, and outputs


## Future Improvements

* Add an I2C LCD to reduce the amount of jumper wires needed
* Add data logging to save temperature and humidity history
* Add a fan or motor that activates when temperatures get too high
  
## Demo


https://github.com/user-attachments/assets/f6fa66b7-6b61-4853-a3fd-3a5899b33492



