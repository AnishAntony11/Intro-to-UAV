#include <Arduino.h>
#include <WiFi.h>
#include <esp32PWMUtilities.h>
#include <DabbleESP32.h>

Motor Motor1;
Motor Motor2;

void _setup()
{
  Motor1.attach(14, 16, 17);

  Motor2.attach(15, 18, 19);

  Dabble.begin("Hello ESP32");
}

void _loop()
{
  Dabble.processInput();
}

void setup()
{
  _setup();
}

void Left()
{
  Motor1.moveMotor(-1 * 100);
  Motor2.moveMotor(1 * 100);
  delay(600);
}

void Forward()
{
  Motor1.moveMotor(1 * 100);
  Motor2.moveMotor(1 * 100);
  delay(1250);
}

void traceTriangle()
{
  
  Forward();
  Left();
  Forward();
  Left();
  Forward();
  Left();
  Forward();
  
}

void loop()
{
  _loop();
  if (GamePad.isPressed(3))
  {
    traceTriangle();
  }
  else if (GamePad.isPressed(2))
  {
    Forward();
  }
  else
  {
    Motor1.lockMotor();
    Motor2.lockMotor();
  }
}