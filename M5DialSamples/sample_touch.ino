#include <M5Dial.h>

void setup() {
	// put your setup code here, to run once:
	auto cfg = M5.config();
	M5Dial.begin(cfg, true, true);
	M5Dial.Display.fillScreen(BLACK);
	M5.Lcd.fillRect(70, 70, 100, 100, GREEN);
}

void loop() {
	// put your main code here, to run repeatedly:
	M5Dial.update();
	
	auto t = M5Dial.Touch.getDetail();
	if(t.state == 3){	// touch begin
		M5.Lcd.fillRect(70, 70, 100, 100, YELLOW);
	}
	else if(t.state == 2){	// touch end
		M5.Lcd.fillRect(70, 70, 100, 100, GREEN);
	}
	delay(10);
}
