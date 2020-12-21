#include "U8glib.h"

U8GLIB_ST7920_128X64 u8g(21,20, 25, U8G_PIN_NONE);
U8GLIB_ST7920_128X64 u8g1(21, 20, 26, U8G_PIN_NONE);

char level[5];
char flow[5];
int chiller1 = 2;
int pump1 = 3;
uint8_t draw_state = 0;

void u8g_prepare(void);
void u8g1_prepare(void);

void u8g_level();
void u8g1_level();
void u8g_chiller1();
void u8g1_chiller2();
void u8g_pump1();
void u8g1_pump2();
void u8g_pressure();
void u8g1_pressure();

void draw(void);
void draw1(void);
