#include "OperatorBridge.h"
#include "PinMap.h"

OperatorBridge *ob = nullptr;
OperatorBridge::PacketOut out;

void setup() {
  // calls Serial.begin(9600)
  ob = new OperatorBridge();
}

void check_temp() {
  // turn on cooling fans if temperature too high
  return;
}

void loop() {
  /* NOTE: Future improvements can involve arduino sending packets back out to
   * android tablet about warnings (ex: high temperature) and have GUI show some
   * warning, but for now just have Arduino automatically turn on cooling fans
   * when temperature reaches a certain point. Of course, this requires Arduino
   * to do some temperature processing on its part when in reality, arduino
   * should simply collect and send data to tablet, let tablet do computations,
   * and let tablet send commands to arduino (ex: turn on cooling fans).
   */

   // reason for certain changes: why send floats over serial and put more
   // burden on communications. Just send raw int readings and let tablet handle
   // the rest. This makes changes to methods of measuring battery state of
   // charge easily changeable.
  out.batteryCharge = analogRead(BATTERY_AMM_PIN);
  out.solarPanelChargeRate = analogRead(SOLAR_AMM_PIN);
  out.batteryTemp = analogRead(BATTERY_TEMP_PIN);
  ob->send(out);
  delay(1000);
}

