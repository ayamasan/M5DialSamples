#include <M5Dial.h>
#include <WiFi.h>

#define WIFI_SSID     "xxxxx"
#define WIFI_PASSWORD "xxxxxxxxxx"

#define NTP_TIMEZONE  "UTC-8"
#define NTP_SERVER1   "0.pool.ntp.org"
#define NTP_SERVER2   "1.pool.ntp.org"
#define NTP_SERVER3   "2.pool.ntp.org"

#if __has_include(<esp_sntp.h>)
#include <esp_sntp.h>
#define SNTP_ENABLED 1
#elif __has_include(<sntp.h>)
#include <sntp.h>
#define SNTP_ENABLED 1
#endif


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
	
	// NTP
	configTzTime(NTP_TIMEZONE, NTP_SERVER1, NTP_SERVER2, NTP_SERVER3);
	while(sntp_get_sync_status() != SNTP_SYNC_STATUS_COMPLETED){
		delay(1000);
		M5Dial.Display.fillScreen(BLACK);
		M5Dial.Display.drawString("NTP Connected.", 120, 120);
	}
	
	// RTC
	time_t tt = time(nullptr) + 1;	// Advance one second.
	while(tt > time(nullptr)){
			;	/// Synchronization in seconds
	}
	tt += (9 * 60 * 60);	// JPN
	M5Dial.Rtc.setDateTime(gmtime(&tt));
	
	// RTCから時刻を読み出す
	char buff1[100];
	char buff2[100];
	auto dt = M5Dial.Rtc.getDateTime();
	sprintf(buff1, "%04d/%02d/%02d\n",
	dt.date.year, dt.date.month, dt.date.date);
	sprintf(buff2, "%02d:%02d:%02d\n",
	dt.time.hours, dt.time.minutes, dt.time.seconds);
	M5Dial.Display.fillScreen(BLACK);
	M5Dial.Display.setTextSize(0.8);
	M5Dial.Display.drawString(buff1, 120, 120-20);
	M5Dial.Display.drawString(buff2, 120, 120+20);
	
}


void loop() {
	// put your main code here, to run repeatedly:
	
	delay(100);
}
