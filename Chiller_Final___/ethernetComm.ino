void ethernetSetting(){
    Ethernet.begin(mac,ip);
    server.begin();
    Serial.print(controller);
    Serial.println(Ethernet.localIP());

    Udp.begin(arduinoUDPPort);
    Serial.print("UDP has been Initialized at ");  Serial.println(arduinoUDPPort);
}

void checkEthernet(){
  // Check if a client has connected
   client = server.available();
   
   // Read the first line of the request
 if (client){
  if (client.connected()) {
 //   Serial.println("Client Connected...");
    String req = client.readStringUntil('\r');
    //Serial.println(req);
  processCommand(req);
  //client.flush();
  client.stop();
  //client.flush();
 //Serial.println("Client disonnected");
  }
}
 delay(1);
  
 }

void webpage(){
String page="<!DOCTYPE HTML><html><head><title>";
page.concat(controller);
page.concat("</title></head><body><h1>Hello From Field SICG Controller:");
page.concat(controller);
page.concat(" Version:");
page.concat(swVersion);
page.concat("</h1></body></html>\r\n\r\n");
client.print(page);

}

void code200(char type[]) {
String resp="";
resp="HTTP/1.1 200 OK";
resp.concat("\r\n");
if(strcmp (type, "html") == 0)    resp.concat("Content-Type: text/html");
else if(strcmp (type, "json") == 0)    resp.concat("Content-Type: application/json;charset=utf-8");
resp.concat("\r\n");
resp.concat("Server: ");
resp.concat(controller);
resp.concat("\r\n");
resp.concat("Access-Control-Allow-Origin: *");
resp.concat("\r\n");
resp.concat("Connection: close");
resp.concat("\r\n\r\n");

client.print(resp);
}


void sendJson(String A, String B){
      code200("json");
      String jsonString ="{\"";
      jsonString.concat(A);
      jsonString.concat("\":\"");
      jsonString.concat(B);
      jsonString.concat("\"");
      jsonString.concat("}\n");
      client.print(jsonString);
}


void processCommand(String req){// here commands is being processed
   if (req.indexOf("/?SV1=") != -1){
          unsigned int val;
          String temp=req.substring(req.indexOf('=')+1,req.indexOf("HTTP")-1);// extract value
          val= temp.toInt();
          //Serial.println("Got This ..."+temp+"=> "+String(val));
          commandProcessed=true;
          setChillerValue(node, val);
          sendJson("SV1",String(val));
         }  
   else if (req.indexOf("/?SV2=") != -1){
          unsigned int val;
          String temp=req.substring(req.indexOf('=')+1,req.indexOf("HTTP")-1);// extract value
          val= temp.toInt();
          //Serial.println("Got This ..."+temp+"=> "+String(val));
          commandProcessed=true;
          setChillerValue(node2, val);
          sendJson("SV2",String(val));
         } 

   else if (req.indexOf("/?chiller1=") != -1){
          unsigned int val;
          String temp=req.substring(req.indexOf('=')+1,req.indexOf("HTTP")-1);// extract value of delay
          val= temp.toInt();
          commandProcessed=true;
          if( val == 1 )  chiller_1_on();
          else if(val == 0) chiller_1_off();    
         }

   else if (req.indexOf("/?pump1=") != -1){
          unsigned int val;
          String temp=req.substring(req.indexOf('=')+1,req.indexOf("HTTP")-1);// extract value of delay
          val= temp.toInt();
          commandProcessed=true;
          if( val == 1 )  pump_1_on();
          else if(val == 0) pump_1_off();    
         }  

   else if (req.indexOf("/?chiller2=") != -1){
          unsigned int val;
          String temp=req.substring(req.indexOf('=')+1,req.indexOf("HTTP")-1);// extract value of delay
          val= temp.toInt();
          commandProcessed=true;
          if( val == 1 )  chiller_2_on();
          else if(val == 0) chiller_2_off();    
         }  

   else if (req.indexOf("/?pump2=") != -1){
          unsigned int val;
          String temp=req.substring(req.indexOf('=')+1,req.indexOf("HTTP")-1);// extract value of delay
          val= temp.toInt();
          commandProcessed=true;
          if( val == 1 )  pump_2_on();
          else if(val == 0) pump_2_off();    
         }  

   else if (req.indexOf("/?fillval=") != -1){
          unsigned int val;
          String temp=req.substring(req.indexOf('=')+1,req.indexOf("HTTP")-1);// extract value of delay
          val= temp.toInt();
          commandProcessed=true;
          if( val == 1 )  fillval_on();
          else if(val == 0) fillval_off();    
         }  
         
  else if (req.indexOf("/?ChillerSendAll") != -1){
           sendAllStatus();   
         } 
  else {
        // send webpage
        code200("html");
        webpage();
     }
 
}



void  sendAllStatus(){
  
    
   code200("json");
      String jsonString ="{\"";
      jsonString.concat("PV1");
      jsonString.concat("\":");
      jsonString.concat(PV1);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("SV1");
      jsonString.concat("\":");
      jsonString.concat(SV1);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("chillerUnit1");
      jsonString.concat("\":");
      jsonString.concat(OUT1_2);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("PV2");
      jsonString.concat("\":");
      jsonString.concat(PV2);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("SV2");
      jsonString.concat("\":");
      jsonString.concat(SV2);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("chillerUnit2");
      jsonString.concat("\":");
      jsonString.concat(OUT2_2);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("chiller_1");
      jsonString.concat("\":");
      jsonString.concat(ind_chiller_1);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("pump_1");
      jsonString.concat("\":");
      jsonString.concat(ind_pump_1);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("chiller_2");
      jsonString.concat("\":");
      jsonString.concat(ind_chiller_2);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("pump_2");
      jsonString.concat("\":");
      jsonString.concat(ind_pump_2);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("fill_val");
      jsonString.concat("\":");
      jsonString.concat(ind_fillval);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("loc_rem");
      jsonString.concat("\":");
      jsonString.concat(ind_loc_rem);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("mains_power");
      jsonString.concat("\":");
      jsonString.concat(ind_mains);
      jsonString.concat(",");
      
      jsonString.concat("\"");
      jsonString.concat("pressure");
      jsonString.concat("\":");
      jsonString.concat(sensorValue);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("waterlevel");
      jsonString.concat("\":");
      jsonString.concat(h);
      
      jsonString.concat("}\n");
      client.print(jsonString);
}

void sendUDPPacket(void){
  IPAddress receiverIP(192,168,10,2);

      String jsonString ="{\"";
      jsonString.concat("PV1");
      jsonString.concat("\":");
      jsonString.concat(PV1);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("SV1");
      jsonString.concat("\":");
      jsonString.concat(SV1);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("chillerUnit1");
      jsonString.concat("\":");
      jsonString.concat(OUT1_2);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("PV2");
      jsonString.concat("\":");
      jsonString.concat(PV2);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("SV2");
      jsonString.concat("\":");
      jsonString.concat(SV2);
      jsonString.concat(",");
      
      jsonString.concat("\"");
      jsonString.concat("chillerUnit2");
      jsonString.concat("\":");
      jsonString.concat(OUT2_2);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("chiller_1");
      jsonString.concat("\":");
      jsonString.concat(ind_chiller_1);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("pump_1");
      jsonString.concat("\":");
      jsonString.concat(ind_pump_1);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("chiller_2");
      jsonString.concat("\":");
      jsonString.concat(ind_chiller_2);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("pump_2");
      jsonString.concat("\":");
      jsonString.concat(ind_pump_2);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("fill_val");
      jsonString.concat("\":");
      jsonString.concat(ind_fillval);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("loc_rem");
      jsonString.concat("\":");
      jsonString.concat(ind_loc_rem);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("mains_power");
      jsonString.concat("\":");
      jsonString.concat(ind_mains);
      jsonString.concat(",");
      
      jsonString.concat("\"");
      jsonString.concat("pressure");
      jsonString.concat("\":");
      jsonString.concat(sensorValue);
      jsonString.concat(",");

      jsonString.concat("\"");
      jsonString.concat("waterlevel");
      jsonString.concat("\":");
      jsonString.concat(h);
      
      jsonString.concat("}\n");
      client.print(jsonString);


 Udp.beginPacket(receiverIP, receiverPort); //start udp packet
 Udp.print(jsonString);
 Udp.endPacket(); // end packet  
}


void chiller_1_on(){
  digitalWrite(out_chiller_1, true); 
  sendJson("chiller_1", "On"); 
}

void chiller_1_off(){
  digitalWrite(out_chiller_1, false); 
  sendJson("chiller_1", "Off");
}

void pump_1_on(){
  digitalWrite(out_pump_1, true); 
  sendJson("pump_1", "On"); 
}

void pump_1_off(){
  digitalWrite(out_pump_1, false); 
  sendJson("pump_1", "Off");
}
  
void chiller_2_on(){
  digitalWrite(out_chiller_2, true); 
  sendJson("chiller_2", "On"); 
}

void chiller_2_off(){
  digitalWrite(out_chiller_2, false); 
  sendJson("chiller_2", "Off");
}

void pump_2_on(){
  digitalWrite(out_pump_2, true); 
  sendJson("pump_2", "On");
} 

void pump_2_off(){
  digitalWrite(out_pump_2, false); 
  sendJson("pump_2", "Off");
}

void fillval_on(){
  digitalWrite(out_fillval, true); 
  sendJson("fillval", "On");
} 

void fillval_off(){
  digitalWrite(out_fillval, false); 
  sendJson("fillval", "Off");
}

