 #include <SPI.h>
 #include <Ethernet.h> 
 #include <EthernetUdp.h>


void ethernetSetting();

//default
String controller="Chiller Remote Control ";
String swVersion="1.0";

// Ethernet params
 byte mac[]=  { 0xDE, 0xAD, 0xCA, 0xFE, 0xBA, 0xC1 };
 String macString="DE:AD:CA:FE:BA:C1";
 IPAddress ip(192,168,10,111);
 EthernetServer server(80);
 EthernetClient client;

bool commandProcessed=false;   
unsigned int arduinoUDPPort = 8011;      // port of Arduino
unsigned int receiverPort = 3011;      // port to listen on my PC
unsigned int UDPServer=2;
EthernetUDP Udp;
bool UDPSendFlag = true;



