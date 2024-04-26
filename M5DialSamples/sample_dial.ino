#include <M5Dial.h>

long oldPosition = -999;

void setup() {
	// put your setup code here, to run once:
	auto cfg = M5.config();
	M5Dial.begin(cfg, true, true);
	M5Dial.Display.fillScreen(WHITE);
	
	M5Dial.Display.fillScreen(BLACK);
	M5Dial.Display.setTextColor(GREEN, BLACK);
	M5Dial.Display.setTextDatum(middle_center);
	M5Dial.Display.setTextFont(&fonts::Orbitron_Light_32);
	M5Dial.Display.setTextSize(1);
	M5Dial.Display.drawString("0", 120, 120);
}


void loop() {
	// put your main code here, to run repeatedly:
	char buff[20];
	
	M5Dial.update();
	
	// ダイアル処理
	long newPosition = M5Dial.Encoder.read();
	if(newPosition != oldPosition){
		sprintf(buff, "%d", newPosition);
		M5Dial.Display.fillScreen(BLACK);
		M5Dial.Display.drawString(buff, 120, 120);
		oldPosition = newPosition;
	}
	
	delay(100);
}
