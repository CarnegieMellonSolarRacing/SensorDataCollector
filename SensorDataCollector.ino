#include "OperatorBridge.h"

OperatorBridge *ob = nullptr;
OperatorBridge::PacketOut out;
OperatorBridge::PacketIn *in;
int ledPin = 13;
int sensorPin = A0;
float r1 = 10.0;
float r2 = 1.0;
float scale = r2 / (r1 + r2);

void setup() {
  ob = new OperatorBridge();
  pinMode(ledPin, OUTPUT);
}

void loop() {
  out.batteryTemp = 123.4;
  out.batteryCharge = (float) analogRead(sensorPin) * 5.0 / scale / 1023.0;
  out.solarPanelChargeRate = 1234;
  ob->send(out);
  
  in = ob->read();
  if (in != nullptr) {
    digitalWrite(ledPin, HIGH);
    Serial.println(in->testValue);
    delete in;
  } else {
    digitalWrite(ledPin, LOW);
  }
  delay(1000);
}

