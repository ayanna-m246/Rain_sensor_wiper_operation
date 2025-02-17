Automated Wiper System

Overview

This project simulates an automated wiper system using an Arduino, a rain sensor, and servo motors. The system detects rain intensity and adjusts the wiper speed accordingly. Additionally, it includes LED indicators and a secondary servo motor to display the selected speed level.

Features

Rain Detection: Uses an analog rain sensor to determine rain intensity.

Speed-Based Wiper Control: Adjusts wiper motion speed based on rain intensity.

LED Indicators: Displays the current speed level.

Speed Display Servo: A second servo motor moves to indicate the speed level.

Scalable Design: Can be modified to use a DC motor with an H-bridge for real-world applications.

Components Used

Arduino board

Rain sensor (analog output)

Servo motor (for wiper motion)

Second servo motor (for speed indication)

4 LEDs (to indicate speed levels)

Resistors (as needed)

Jumper wires & breadboard

Working Principle

The rain sensor measures moisture levels and sends an analog signal to the Arduino.

Based on the sensor reading, the system determines the rain intensity and selects a wiper speed level.

The primary servo motor (wiper) oscillates between 0° and 180° to simulate wiper motion.

The secondary servo motor moves to display the current speed level.

LEDs indicate the active speed level.

Speed Levels

Rain Intensity

Sensor Value Range

Wiper Speed

Speed Indicator

No Rain

> 1000

Off

No LED

Light Rain

800 - 1000

Slow

LED 1

Moderate Rain

600 - 800

Medium

LED 2

Heavy Rain

400 - 600

Fast

LED 3

Very Heavy Rain

< 400

Maximum

LED 4

Setup & Usage

Connect all components according to the circuit diagram.

Upload the Arduino code to your board.

Open the Serial Monitor to view real-time sensor values and wiper status.

Adjust rain levels manually (e.g., using a damp cloth) to test wiper speed changes.

Future Improvements

Integrate a DC motor and H-bridge for realistic wiper motion.

Use an LCD display instead of LEDs for a more detailed interface.

Implement wireless control for remote wiper adjustments.

This project provides a realistic prototype of an automated rain-sensing wiper system, making it a great foundation for future automotive applications.
