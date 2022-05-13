# Obstacle-Avoiding-Car

read more about the construction: https://medium.com/@zoey_yj

Equipment
Arduino Nano, ultrasonic sensor, motor driver L298N, TT gear motor, servo motor SG90, 18650 Li-on battery, battery holder, male and female jumper wire, wheels, chassis plate, screw and nuts

Preparation
cut jumper wire into half, solder female pin headers to power supply and male pin headers to TT gear motors

Assembling
(1) glue ultrasonic sensor on servo motor.

(2) screw Arduino nano, servo motor, TT gear motor, battery holder onto the chassis plate.

(3) attach wheels on the TT gear motor.

(4) connect TT gear motor to motor driver terminals, connect motor driver and servo motor to Arduino nano.

Programming
(1) Arduino IDE

(2) Language: C++

(3) Code:

(a). build function for checking distance: ultrasonic sensor uses ultrasonic sound waves to measure the distance to an object by timing the pulse bounced off of the object and return to the sensor.

(b). build function for movement: use Arduino Nano digital pin to send motor driver signal to control the motion of left and right side motors to achieve the following five movements:

move forward: both left and right motors going forward
move backward: both sides going backward
turn left: left motors going backward and right motors going forward
turn right: right motors going backward and left motors going forward, and
stop: both sides stop moving
(c) logics of operating

if distance is more than 25cm ahead, the car move forward
else stop and move backward for two seconds and stop
check left and right side distances, decide which side has larger distance,
make the turn, move forward and keep checking distance ahead
