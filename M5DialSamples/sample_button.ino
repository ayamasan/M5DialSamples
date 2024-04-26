#include <M5Dial.h>

void setup() {
	// put your setup code here, to run once:
	auto cfg = M5.config();
	M5Dial.begin(cfg, true, true);
	M5Dial.Display.fillScreen(BLACK);
	M5.Lcd.fillRect(70, 70, 100, 100, BLUE);
}

void loop() {
	// put your main code here, to run repeatedly:
	M5Dial.update();
	
	if(M5Dial.BtnA.wasPressed()){
		M5.Lcd.fillRect(70, 70, 100, 100, RED);
	}
	if(M5Dial.BtnA.wasReleased()){
		M5.Lcd.fillRect(70, 70, 100, 100, BLUE);
	}
	delay(10);
}
