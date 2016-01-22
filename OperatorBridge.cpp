#include <stdlib.h>
#include <avr/pgmspace.h>
#include "OperatorBridge.h"

OperatorBridge::OperatorBridge() {
  Serial.begin(9600);
  Serial.setTimeout(300);
}

OperatorBridge::~OperatorBridge() {
  Serial.end();
}

OperatorBridge::PacketIn *OperatorBridge::read() {
  if (Serial.available() > 30) {
    if (!Serial.find((char*)"BEGIN_PACKET")) return nullptr;
    if (!Serial.find((char*)"TEST_VAL1:")) return nullptr;
    float testValue = Serial.parseFloat();
    if (!Serial.find((char*)"END_PACKET")) return nullptr;
    Serial.readStringUntil('\n');

    PacketIn *packet = new PacketIn();
    Serial.println((int)packet);
    packet->testValue = testValue;
    return packet;
  }
  return nullptr;
}

bool OperatorBridge::send(OperatorBridge::PacketOut packet) {
  Serial.print(F("BEGIN_PACKET"));
  Serial.print(F("BATT_TEMP:"));
  Serial.print(packet.batteryTemp);
  Serial.print(F("BATT_CHRG:"));
  Serial.print(packet.batteryCharge);
  Serial.print(F("SOLR_RATE:"));
  Serial.print(packet.solarPanelChargeRate);
  Serial.print(F("END_PACKET"));
  Serial.print('\n');
  return true;
}
