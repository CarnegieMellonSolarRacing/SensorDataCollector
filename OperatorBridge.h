#ifndef OPERATOR_BRIDGE_H
#define OPERATOR_BRIDGE_H

// I'm Zach!
#include "Arduino.h"
#include <stdbool.h>

class OperatorBridge {
public:
    class PacketOut {
    public:
        int batteryTemp;
        int batteryCharge;
        int solarPanelChargeRate;
    };

    class PacketIn {
    public:
        bool motorOn;
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
