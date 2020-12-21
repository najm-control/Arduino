
void modBusSettings(){
  
  pinMode(MAX485_RE_NEG, OUTPUT);
  pinMode(MAX485_DE, OUTPUT);
  // Init in receive mode
  digitalWrite(MAX485_RE_NEG, 0);
  digitalWrite(MAX485_DE, 0);
  // Modbus communication runs at 38400 baud
  Serial1.begin(38400);
  // Modbus slave ID 1
  node.begin(1, Serial1);
  // Callbacks allow us to configure the RS485 transceiver correctly
  node.preTransmission(preTransmission);
  node.postTransmission(postTransmission);


   node2.begin(2, Serial1);
  // Callbacks allow us to configure the RS485 transceiver correctly
  node2.preTransmission(preTransmission);
  node2.postTransmission(postTransmission); 
}


void preTransmission()
{
  digitalWrite(MAX485_RE_NEG, 1);
  digitalWrite(MAX485_DE, 1);
}

void postTransmission()
{
  digitalWrite(MAX485_RE_NEG, 0);
  digitalWrite(MAX485_DE, 0);
}


void  getChillerData( ){
   uint8_t result;
  // Read n registers starting at 03E8 in Func 4
  result = node.readInputRegisters(0x3E8, 8);// result is response code from MODbus lib
  
  if (result == node.ku8MBSuccess){
  PV1=node.getResponseBuffer(0);
  SV1=node.getResponseBuffer(3);

  //Serial.print("PV1: "); Serial.println(PV1);
  //Serial.print("SV2: "); Serial.println(SV1);
  
  uint16_t miscIndicators=node.getResponseBuffer(6);
  OUT1_1=bitRead(miscIndicators, 3);
  OUT1_2=bitRead(miscIndicators, 4);
  }

 result = node2.readInputRegisters(0x3E8, 8);// result is response code from MODbus lib
  
  if (result == node.ku8MBSuccess){
  PV2=node2.getResponseBuffer(0);
  SV2=node2.getResponseBuffer(3);

  //Serial.print("PV2: "); Serial.println(PV2);
  //Serial.print("SV2: "); Serial.println(SV2);
  
  uint16_t miscIndicators=node2.getResponseBuffer(6);
    //bit0=> C indicator.... values = 0(off) 1 (on)
    //bit1=> F indicator.... values = 0(off) 1 (on)
    //bit2=> % indicator.... values = 0(off) 1 (on)
    //bit3=> OUT1 indicator.... values = 0(off) 1 (on)
    //bit4=> OUT2 indicator.... values = 0(off) 1 (on)
    //bit5=> AT indicator.... values = 0(off) 1 (on)
    //bit6=> SV1 indicator.... values = 0(off) 1 (on)
    //bit7=> SV2 indicator.... values = 0(off) 1 (on)
    //bit8=> SV3 indicator.... values = 0(off) 1 (on)
    //bit9=> AL1 indicator.... values = 0(off) 1 (on)
    //bitA=> AL2 indicator.... values = 0(off) 1 (on)
    //bitB=> MAN indicator .... values = 0(off) 1 (on)
    //bitC=> DI-1 input status .... values = 0(off) 1 (on)
    //bitD=> DI-2 input status .... values = 0(off) 1 (on)
  OUT2_1=bitRead(miscIndicators, 3);
  OUT2_2=bitRead(miscIndicators, 4);
  }
}

void setChillerValue(ModbusMaster desiredNode, uint8_t setValue ){
   uint8_t result;

   uint8_t regAddress=0x00; // register Address of SV
   result=desiredNode.writeSingleRegister(regAddress, setValue);// func06

   if (result == node.ku8MBSuccess)
  {
    //Serial.println("SV Changed");
    }
}
