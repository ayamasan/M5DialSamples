#include <M5Dial.h>

void setup() {
	// put your setup code here, to run once:
	auto cfg = M5.config();
	M5Dial.begin(cfg, true, true);
	M5Dial.Display.fillScreen(BLACK);
}

void loop() {
	// put your main code here, to run repeatedly:
	M5.Lcd.fillRect(110, 110, 20, 20, RED);
	delay(300);
	M5.Lcd.fillRect(110, 110, 20, 20, GREEN);
	delay(300);
}
