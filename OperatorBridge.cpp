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

bool OperatorBridge::send(OperatorBridge::PacketOut packet) {
  /* Will send strings of data in the following format:
   * 'temp, battery_charge, solar_charge\n' where each value is an int
   */
  Serial.print(packet.batteryTemp);
  Serial.print(",");
  Serial.print(packet.batteryCharge);
  Serial.print(",");
  Serial.println(packet.solarPanelChargeRate);
  return true;
}

OperatorBridge::PacketIn *OperatorBridge::read() {
  if (Serial.available() > 30) {
    if (!Serial.find((char*)"BEGIN_PACKET")) return nullptr;
    if (!Serial.find((char*)"TEST_VAL1:")) return nullptr;
    float testValue = Serial.parseFloat();
    if (!Serial.find((char*)"END_PACKET")) return nullptr;
    Serial.readStringUntil('\n');

    PacketIn *packet = new PacketIn();
    return packet;
  }
  return nullptr;
}


