#include <M5Dial.h>
#include <WiFi.h>

#define WIFI_SSID		 "xxxxx"
#define WIFI_PASSWORD "xxxxxxxxxx"

void setup() {
	// put your setup code here, to run once:
	auto cfg = M5.config();
	M5Dial.begin(cfg, true, true);
	M5Dial.Display.fillScreen(WHITE);
	
	M5Dial.Display.fillScreen(BLACK);
	M5Dial.Display.setTextColor(GREEN, BLACK);
	M5Dial.Display.setTextDatum(middle_center);
	M5Dial.Display.setTextFont(&fonts::Orbitron_Light_32);
	M5Dial.Display.setTextSize(0.5);
	
	// WiFi接続
	M5Dial.Display.drawString("WiFi connecting...", 120, 120);
	WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
	while(WiFi.status() != WL_CONNECTED){
		delay(500);
	}
	M5Dial.Display.fillScreen(BLACK);
	M5Dial.Display.drawString("Connected.", 120, 120);
}


void loop() {
	// put your main code here, to run repeatedly:
	
	delay(100);
}
