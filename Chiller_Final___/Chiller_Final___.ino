
#include "Control_Monitor.h"
#include"ethernetComm.h"
#include"lcd128x64.h"
#include"ultraSonic.h"
#include "modbusTempController.h"


int sensorValue;
ModbusMaster node;
ModbusMaster node2;

void setup(void) {

#if defined(ARDUINO)
  pinMode(13, OUTPUT);           
  digitalWrite(13, HIGH);  
#endif



  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  ethernetSetting();
  ultraSonicSetting();
  modBusSettings();
  ControlMonitorSetting();
  
  //delay(2000);
}

void loop(void) {

  if(draw_state==0){
  calculateLevel();
  Serial.println(h);
  }

  else if(draw_state==3){
  sensorValue = analogRead(A15);
  Serial.println(sensorValue);
  }

  readDigitalInputs();
  checkEthernet();
  if(UDPSendFlag) sendUDPPacket();
 
  u8g.firstPage();    
  do {
    draw();
  } while( u8g.nextPage() );

  u8g1.firstPage();  
  do {
    draw1();
  } while( u8g1.nextPage() );
  
  // increase the state
  draw_state++;
  if ( draw_state >= 4 )
    draw_state = 0;
    getChillerData();
  
  

}


