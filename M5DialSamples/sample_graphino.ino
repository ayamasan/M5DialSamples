#include <M5Dial.h>
#include "m1.h"

void setup() {
	// put your setup code here, to run once:
	auto cfg = M5.config();
	M5Dial.begin(cfg, true, true);
	M5Dial.Display.fillScreen(WHITE);
	
	M5Canvas canvas(&M5Dial.Display);
	canvas.createSprite(110, 110);
	canvas.fillRect(0, 0, 110, 110, WHITE);
	
	canvas.drawPng(mm1, 8443, 0, 0, 110, 110);
	
	canvas.pushSprite(65, 65);
	
	M5Dial.Display.drawLine(60, 180, 180, 180, BLUE);
	M5Dial.Display.fillRect(60, 184, 120, 4, BLUE);
	M5Dial.Display.fillArc(120, 120, 100, 120, 0, 270, GREEN);
	M5Dial.Display.fillArc(120, 120, 100, 120, 270, 359, RED);
}

void loop() {
	// put your main code here, to run repeatedly:
	
	delay(100);
}
