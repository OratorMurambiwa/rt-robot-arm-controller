#include <Servo.h>

// Servo objects
Servo baseServo;
Servo elbowServo;
Servo clawServo;

// Arduino pins
const int BASE_PIN = 3;
const int ELBOW_PIN = 6;
const int CLAW_PIN = 9;

// Safe joint limits
const int BASE_MIN = 0;
const int BASE_MAX = 180;

const int ELBOW_MIN = 30;
const int ELBOW_MAX = 180;

const int CLAW_MIN = 0;
const int CLAW_MAX = 180;

// Current servo positions
int basePosition = 90;
int elbowPosition = 90;
int clawPosition = 90;

void setup()
{
    Serial.begin(9600);

    baseServo.attach(BASE_PIN);
    elbowServo.attach(ELBOW_PIN);
    clawServo.attach(CLAW_PIN);

    baseServo.write(basePosition);
    elbowServo.write(elbowPosition);
    clawServo.write(clawPosition);

    Serial.println("READY");
}

void loop()
{
    if (Serial.available() > 0)
    {
        String command = Serial.readStringUntil('\n');
        command.trim();

        processCommand(command);
    }
}

void processCommand(String command)
{
    if (command.length() < 2)
    {
        Serial.println("ERROR: Invalid command");
        return;
    }

    char joint = command.charAt(0);
    int angle = command.substring(1).toInt();

    if (joint == 'B' || joint == 'b')
    {
        moveServo(
            baseServo,
            angle,
            BASE_MIN,
            BASE_MAX,
            basePosition,
            "BASE");
    }
    else if (joint == 'E' || joint == 'e')
    {
        moveServo(
            elbowServo,
            angle,
            ELBOW_MIN,
            ELBOW_MAX,
            elbowPosition,
            "ELBOW");
    }
    else if (joint == 'C' || joint == 'c')
    {
        moveServo(
            clawServo,
            angle,
            CLAW_MIN,
            CLAW_MAX,
            clawPosition,
            "CLAW");
    }
    else
    {
        Serial.println("ERROR: Unknown joint");
    }
}

void moveServo(
    Servo &servo,
    int angle,
    int minimumAngle,
    int maximumAngle,
    int &currentPosition,
    const char *jointName)
{
    if (angle < minimumAngle || angle > maximumAngle)
    {
        Serial.print("ERROR: ");
        Serial.print(jointName);
        Serial.println(" angle outside safe range");

        return;
    }

    servo.write(angle);
    currentPosition = angle;

    Serial.print("OK: ");
    Serial.print(jointName);
    Serial.print(" ");
    Serial.println(angle);
}
