#include <ModbusMaster.h>


/*!
  We're using a MAX485-compatible RS485 Transceiver.
  Rx/Tx is hooked up to the hardware serial port at 'Serial'.
  The Data Enable and Receiver Enable pins are hooked up as follows:
*/
#define MAX485_DE      5
#define MAX485_RE_NEG  6

uint16_t PV1, SV1, PV2, SV2;
bool OUT1_1,OUT1_2,OUT2_1,OUT2_2;

void modBusSettings();
void setChillerValue(ModbusMaster desiredNode, uint8_t setValue );

