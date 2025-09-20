#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_ADS1X15.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

Adafruit_ADS1115 ads;

float dividerFactor=1.0;
float calibration=0.969;

void setup(){
  Serial.begin(115200);
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C)) while(1);
  if(!ads.begin()) while(1);
  ads.setGain(GAIN_ONE);
}

void loop(){
  float v0=ads.readADC_SingleEnded(0)*0.000125*dividerFactor*calibration;
  float v1=ads.readADC_SingleEnded(1)*0.000125*dividerFactor*calibration;
  float v2=ads.readADC_SingleEnded(2)*0.000125*dividerFactor*calibration;
  float v3=ads.readADC_SingleEnded(3)*0.000125*dividerFactor*calibration;

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("A0: "); display.println(v0,3);
  display.print("A1: "); display.println(v1,3);
  display.print("A2: "); display.println(v2,3);
  display.print("A3: "); display.println(v3,3);
  display.display();

  Serial.print("A0: "); Serial.print(v0,3);
  Serial.print(" | A1: "); Serial.print(v1,3);
  Serial.print(" | A2: "); Serial.print(v2,3);
  Serial.print(" | A3: "); Serial.println(v3,3);

  delay(800);
}
