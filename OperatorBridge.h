#ifndef OPERATOR_BRIDGE_H
#define OPERATOR_BRIDGE_H

// I'm Zach!
#include "Arduino.h"
#include <stdbool.h>

class OperatorBridge {
public:
    class PacketOut {
    public:
        float batteryTemp;
        float batteryCharge;
        float solarPanelChargeRate;
    };

    class PacketIn {
    public:
        bool error;
        float testValue;
    };

    OperatorBridge();
    ~OperatorBridge();

    // Reads a packet from the connection, null if nothing
    // has been received.
    PacketIn *read();
    // Sends a packet over the connection, returns
    // true iff success.
    bool send(PacketOut packet);
};

#endif
