#include <OperatorBridge.h>

OperatorBridge *ob = nullptr;
OperatorBridge::PacketOut out;
OperatorBridge::PacketIn *in;
int ledPin = 13;

void setup() {
  ob = new OperatorBridge();
  pinMode(ledPin, OUTPUT);
}

void loop() {
  out.batteryTemp = 123.4;
  out.batteryCharge = 1231234.12;
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
}

