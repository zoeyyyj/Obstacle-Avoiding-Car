#include <Servo.h>          //standard library for the servo
#include <NewPing.h>        //for the Ultrasonic sensor function library.

//L298N motor control pins
const int LeftMotorForward = 6;
const int LeftMotorBackward = 7;
const int RightMotorForward = 5;
const int RightMotorBackward = 4;

//sensor pins
int trigPin = A2;
int echoPin = A1;
int maximumcm = 250;
int cm;

NewPing sonar(trig_pin, echo_pin, maximumcm);
Servo servo_motor; 

void setup() {
    pinMode(RightMotorForward, OUTPUT);
    pinMode(LeftMotorForward, OUTPUT);
    pinMode(LeftMotorBackward, OUTPUT);
    pinMode(RightMotorBackward, OUTPUT);

    servo_motor.attach(9);
    servo_motor.write(115);
    delay(2000);
    cm = readPing();
    delay(100);
}

void loop(){
    cm = readPing();
    int cmRight = 0;
    int cmLeft = 0;
    delay(50);

    if (distance <= 25) {
        moveStop();
        delay(200);
        moveBackward();
        delay(300);
        moveStop();
        delay(200);
        cmRight = lookRight();
        delay(200);
        cmLeft = lookLeft();
        delay(200);

        if (cmLeft <= 25 && cmRight <= 25) {
            moveStop();
            delay(200);
            moveBackward();
            delay(300);
            moveStop();
            delay(200);
            cmRight = lookRight();
            delay(200);
            cmLeft = lookLeft();
            delay(200);
            moveStop();
            delay(200);
        }
    
        else if (cmLeft > cmRight) {
            turnLeft();
            delay(300);
            moveStop();
        }

        else if (cmRight > cmLeft) {
            turnRight();
            delay(300);
            Stop();
        }
    }
  
    else {
        Forward();
    }
  
    cm = readPing();
}

int lookRight() {  
    servo_motor.write(50);
    delay(200);
    int cm = readPing();
    delay(200);
    servo_motor.write(115);
    return cm;
}

int lookLeft() {
    servo_motor.write(170);
    delay(200);
    int cm = readPing();
    delay(200);
    servo_motor.write(115);
    return cm;
}

int readPing() {
    delay(200);
    int cm = sonar.ping_cm();
    if (cm==0) {
        cm=250;
    }
    return cm;
}

void moveStop() {
    digitalWrite(RightMotorForward, LOW);
    digitalWrite(LeftMotorForward, LOW);
    digitalWrite(RightMotorBackward, LOW);
    digitalWrite(LeftMotorBackward, LOW);
}

void moveForward() {
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW); 
}

void moveBackward() {
    digitalWrite(LeftMotorBackward, HIGH);
    digitalWrite(RightMotorBackward, HIGH);
    digitalWrite(LeftMotorForward, LOW);
    digitalWrite(RightMotorForward, LOW); 
}

void turnRight() {
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorBackward, HIGH);
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorForward, LOW);
}

void turnLeft() {
    digitalWrite(LeftMotorBackward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
    digitalWrite(LeftMotorForward, LOW);
    digitalWrite(RightMotorBackward, LOW);
}
