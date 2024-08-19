#include <Servo.h>

#define BUTTON_LEFT 4
#define BUTTON_RIGHT 2
int SERVO_PIN  = 3;
int angle = 0;

Servo servo;
bool canWrite = true;

void setup()
{
  Serial.begin(9600);
  servo.attach(SERVO_PIN);
  pinMode(BUTTON_LEFT, INPUT_PULLUP);
  pinMode(BUTTON_RIGHT, INPUT_PULLUP);
}
void loop()
{
  
  
  if (canWrite){
    byte leftState = digitalRead(BUTTON_LEFT);
    byte rightState = digitalRead(BUTTON_RIGHT);
    if (leftState == LOW) {
        canWrite = false;
        angle += 5;
        Serial.println("LEFT is pressed");
        servo.write(angle);
        delay(10);
        canWrite = true;
    }

    if (rightState == LOW) {
        canWrite = false;
        angle -= 5;
        Serial.println("RIGHT is pressed");
        servo.write(angle);
        delay(10);
        canWrite = true;
    }
  }
}