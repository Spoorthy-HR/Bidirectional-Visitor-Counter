# Bidirectional Visitor Counter
<hr>
This project is a bidirectional visitor counter that uses an Arduino microcontroller, Infrared (IR) sensors, and a buzzer to count the number of people entering and exiting a room. The counter increments when a person enters and decrements when a person exits. The buzzer provides audio feedback, alerting when the maximum room capacity is reached.

# Components Used
<hr>
Arduino: The core microcontroller that processes the sensor data and controls the buzzer.
IR Sensors: Two infrared sensors are used to detect the entry and exit of visitors. When a person passes through the sensors, the IR beam is interrupted, triggering the Arduino to update the visitor count.
Buzzer: The buzzer sounds an alert when certain conditions are met, such as reaching the maximum room capacity.
Display (Optional): An LCD or LED display can be added to show the current visitor count.

# Features
<hr>
Bidirectional Counting: The system can accurately detect and count people entering and exiting a room.
Real-Time Monitoring: The visitor count is updated in real-time, ensuring accurate tracking.
Capacity Alert: The buzzer sounds when the room reaches its maximum capacity, preventing overcrowding.
Simple and Cost-Effective: The project uses readily available components and is easy to assemble.

# How It Works
<hr>
1. IR Sensors Setup: Two IR sensors are placed at the entrance/exit point of the room. Sensor 1 detects when someone enters, and Sensor 2 detects when someone exits.
2. Counting Logic: The Arduino reads the state of the IR sensors. If Sensor 1 is triggered before Sensor 2, it means a person has entered, and the counter is incremented. If Sensor 2 is triggered before Sensor 1, it means a person has exited, and the counter is decremented.
3. Buzzer Alert: If the visitor count reaches a predefined maximum capacity, the Arduino triggers the buzzer to alert that the room is full.
4. Display Output: The current visitor count can be displayed on an optional LCD or LED screen for easy monitoring.

# Applications
<hr>
Room Occupancy Management: Ideal for managing the number of people in a room, such as in conference halls, auditoriums, and classrooms.
Retail Stores: Helps store managers monitor customer flow and ensure that occupancy limits are not exceeded.
Public Spaces: Useful in public places where crowd control is essential.

# Getting Started
<hr>
To build this project, you will need to assemble the components as per the circuit diagram provided and upload the Arduino code to the microcontroller. Follow the step-by-step instructions in the detailed documentation to complete the setup.


