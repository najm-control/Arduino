void u8g_prepare(void) {
  u8g.setFont(u8g_font_unifont);
  u8g.setFontRefHeightExtendedText();
  u8g.setDefaultForegroundColor();
  //u8g.setFontPosTop();
}

void u8g1_prepare(void) {
  u8g1.setFont(u8g_font_unifont);
  u8g1.setFontRefHeightExtendedText();
  u8g1.setDefaultForegroundColor();
  //u8g.setFontPosTop();
}


void u8g_level() {

  
  int l=60-(h/3.5);
  if(l>60 || l<30)
  l=59;
  
  //Serial.print(l);
  dtostrf(h, 3, 0, level);

  u8g.drawStr( 20, 15, "TANK#1 LEVEL");
  u8g.drawStr( 20, 50, level);
  u8g.drawStr( 45, 50, "%");
  u8g.drawLine(80, 30, 80, 60);
  u8g.drawLine(80, 60, 120, 60);
  u8g.drawLine(120, 30, 120, 60);
  u8g.drawBox(80,l,40,60-l);
  
}

void u8g1_level() {

  
  int l=60-(h/3.5);
  if(l>60 || l<30)
  l=59;
  
  //Serial.print(l);
  dtostrf(h, 3, 0, level);

  u8g1.drawStr( 20, 15, "TANK#2 LEVEL");
  u8g1.drawStr( 20, 50, level);
  u8g1.drawStr( 45, 50, "%");
  u8g1.drawLine(80, 30, 80, 60);
  u8g1.drawLine(80, 60, 120, 60);
  u8g1.drawLine(120, 30, 120, 60);
  u8g1.drawBox(80,l,40,60-l);
  
}

void u8g_chiller1() {

  u8g.drawStr( 25, 15, "CHILLER#1");
  if(ind_chiller_1 == 1)
  {
  u8g.drawDisc(60,35,9);
  u8g.drawStr( 50, 60, "ON");
  }
  else if(ind_chiller_1 == 0)
  {
  u8g.drawCircle(60,35,9);
  u8g.drawStr( 50, 60, "OFF");
  }
}

void u8g1_chiller2() {

  u8g1.drawStr( 25, 15, "CHILLER#2");
  if(ind_chiller_2 == 1)
  {
  u8g1.drawDisc(60,35,9);
  u8g1.drawStr( 50, 60, "ON");
  }
  else if(ind_chiller_2 == 0)
  {
  u8g1.drawCircle(60,35,9);
  u8g1.drawStr( 50, 60, "OFF");
  }
}

void u8g_pump1() {

  u8g.drawStr( 40, 15, "PUMP#1");
  if(ind_pump_1 == 1)
  {
  u8g.drawDisc(60,35,9);
  u8g.drawStr( 50, 60, "ON");
  }
  else if(ind_pump_1 == 0)
  {
  u8g.drawCircle(60,35,9);
  u8g.drawStr( 50, 60, "OFF");
  }
}

void u8g1_pump2() {

  u8g1.drawStr( 40, 15, "PUMP#2");
  if(ind_pump_2 == 1)
  {
  u8g1.drawDisc(60,35,9);
  u8g1.drawStr( 50, 60, "ON");
  }
  else if(ind_pump_2 == 0)
  {
  u8g1.drawCircle(60,35,9);
  u8g1.drawStr( 50, 60, "OFF");
  }
}

void u8g_pressure() {

  
  u8g.drawStr( 5, 15, "FLOW RATE O/P#1");
  dtostrf(sensorValue, 4, 0, flow);
  u8g.drawStr( 30, 40, flow);
  u8g.drawStr( 70, 40, "LPM");
  
}

void u8g1_pressure() {
  
  u8g1.drawStr( 5, 15, "FLOW RATE O/P#2");
  dtostrf(sensorValue, 4, 0, flow);
  u8g1.drawStr( 30, 40, flow);
  u8g1.drawStr( 70, 40, "LPM");
  
}




void draw(void) {
  u8g_prepare();
  switch(draw_state) {
    case 0: u8g_level(); break;
    case 1: u8g_chiller1(); break;
    case 2: u8g_pump1(); break;
    case 3: u8g_pressure(); break;

  }
}

void draw1(void) {
  u8g1_prepare();
  switch(draw_state) {
    case 0: u8g1_level(); break;
    case 1: u8g1_chiller2(); break;
    case 2: u8g1_pump2(); break;
    case 3: u8g1_pressure(); break;

  }
}
