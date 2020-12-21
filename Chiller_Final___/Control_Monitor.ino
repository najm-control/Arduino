

void ControlMonitorSetting()
{
  pinMode(ind_chiller_1_pin, INPUT);
  pinMode(ind_pump_1_pin, INPUT);
  pinMode(ind_chiller_2_pin, INPUT); 
  pinMode(ind_pump_2_pin, INPUT);
  pinMode(ind_fillval_pin, INPUT);
  pinMode(ind_loc_rem_pin, INPUT);
  pinMode(ind_mains_pin, INPUT);

  pinMode(out_chiller_1, OUTPUT);
  pinMode(out_pump_1, OUTPUT);
  pinMode(out_chiller_2, OUTPUT);
  pinMode(out_pump_2, OUTPUT);
  pinMode(out_fillval, OUTPUT);
}

void readDigitalInputs()
{
  ind_chiller_1 = digitalRead(ind_chiller_1_pin);
  ind_pump_1 = digitalRead(ind_pump_1_pin);
  ind_chiller_2 = digitalRead(ind_chiller_2_pin);
  ind_pump_2 = digitalRead(ind_pump_2_pin);
  ind_fillval = digitalRead(ind_fillval_pin);
  ind_loc_rem = digitalRead(ind_loc_rem_pin);
  ind_mains = digitalRead(ind_mains_pin);
}

