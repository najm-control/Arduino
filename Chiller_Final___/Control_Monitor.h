

//monitoring
int ind_chiller_1_pin = A8;
int ind_pump_1_pin = A9;
int ind_chiller_2_pin = A10;
int ind_pump_2_pin = A11;
int ind_fillval_pin = A12;
int ind_loc_rem_pin = A13;
int ind_mains_pin = A14;


bool ind_chiller_1;
bool ind_pump_1;
bool ind_chiller_2;
bool ind_pump_2;
bool ind_fillval;
bool ind_loc_rem;
bool ind_mains;

//control
int out_chiller_1 = 9;
int out_pump_1 = 7;
int out_chiller_2 = 8;
int out_pump_2 = 3;
int out_fillval = 2;

void ControlMonitorSetting();
void readDigitalInputs();


