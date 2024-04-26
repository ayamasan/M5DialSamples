#include <M5Dial.h>

void setup() {
	// put your setup code here, to run once:
	auto cfg = M5.config();
	M5Dial.begin(cfg, true, true);
	M5Dial.Display.fillScreen(NAVY);
	M5.Lcd.fillRect(0, 90, 240, 60, WHITE);
	
	M5Dial.Display.setTextColor(GREEN, NAVY);
	M5Dial.Display.setTextDatum(middle_center);
	M5Dial.Display.setTextFont(&fonts::Orbitron_Light_32);
	M5Dial.Display.setTextSize(1);
	M5Dial.Display.drawString("2024 R6", 120, 120-54);
	M5Dial.Display.drawString("04/17 Wed", 120, 120+50);
	
	M5Dial.Display.setTextColor(BLACK, WHITE);
	M5Dial.Display.setTextFont(7);
	M5Dial.Display.setTextSize(1);
	M5Dial.Display.drawString("12:09:34", 120, 120);
}


void loop() {
	// put your main code here, to run repeatedly:
	
	delay(100);
}
