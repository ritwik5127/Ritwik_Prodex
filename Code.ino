// C++ code
//


#include <Servo.h>

Servo horizontalMotor;
Servo verticalMotor;


int topLeftSensor = A0;
int topRightSensor = A1;
int bottomLeftSensor = A2;
int bottomRightSensor = A3;

int horizontalPosition = 90;
int verticalPosition = 90;


int lightTolerance = 20;

void setup() {
  horizontalMotor.attach(10);
  verticalMotor.attach(9);

  horizontalMotor.write(horizontalPosition);
  verticalMotor.write(verticalPosition);
}

void loop() {
  
  int topLeftLight = analogRead(topLeftSensor);
  int topRightLight = analogRead(topRightSensor);
  int bottomLeftLight = analogRead(bottomLeftSensor);
  int bottomRightLight = analogRead(bottomRightSensor);

  
  int topLight = (topLeftLight + topRightLight) / 2;
  int bottomLight = (bottomLeftLight + bottomRightLight) / 2;

  
  int leftLight = (topLeftLight + bottomLeftLight) / 2;
  int rightLight = (topRightLight + bottomRightLight) / 2;

 
  if (abs(topLight - bottomLight) > lightTolerance) {
    if (topLight > bottomLight) {
      verticalPosition++;
    } else {
      verticalPosition--;
    }

    verticalPosition = constrain(verticalPosition, 0, 180);
    verticalMotor.write(verticalPosition);
  }
  
  if (abs(leftLight - rightLight) > lightTolerance) {
    if (leftLight > rightLight) {
      horizontalPosition--;
    } else {
      horizontalPosition++;
    }

    horizontalPosition = constrain(horizontalPosition, 0, 180);
    horizontalMotor.write(horizontalPosition);
  }

  delay(100);
}