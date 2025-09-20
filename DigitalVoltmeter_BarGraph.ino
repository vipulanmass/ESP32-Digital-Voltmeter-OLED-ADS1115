#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_ADS1X15.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

Adafruit_ADS1115 ads;

float dividerFactor = 1.0;
float calibration   = 0.969;
float maxVoltage    = 12.0; // adjust for expected input
float voltage = 0.0;

void setup() {
  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) while(1);
  if (!ads.begin()) while(1);
  ads.setGain(GAIN_ONE);
}

void loop() {
  long sum=0; for(int i=0;i<10;i++){sum+=ads.readADC_SingleEnded(0); delay(5);}
  int16_t avg=sum/10;
  voltage=(avg*0.000125)*dividerFactor*calibration;

  int barLength = map((int)(voltage*1000),0,(int)(maxVoltage*1000),0,128);

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("BAR GRAPH VOLTMETER");
  display.setTextSize(2);
  display.setCursor(10,15);
  display.print(voltage,2);
  display.println(" V");
  display.drawRect(0,45,128,15,SSD1306_WHITE);
  display.fillRect(0,45,barLength,15,SSD1306_WHITE);
  display.display();

  Serial.println(voltage,3);
  delay(500);
}
