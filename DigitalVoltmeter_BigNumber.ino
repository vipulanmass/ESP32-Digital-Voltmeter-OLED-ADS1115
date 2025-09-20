#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_ADS1X15.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

Adafruit_ADS1115 ads;

float dividerFactor = 1.0;    // set if resistor divider used
float calibration   = 0.969;  // fine tune with multimeter
float voltage = 0.0;

void setup() {
  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) while(1);
  if (!ads.begin()) while(1);
  ads.setGain(GAIN_ONE);
}

void loop() {
  long sum = 0;
  for (int i=0;i<10;i++){ sum+=ads.readADC_SingleEnded(0); delay(5);}
  int16_t avg = sum/10;
  voltage = (avg * 0.000125) * dividerFactor * calibration;

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("DIGITAL VOLTMETER");
  display.setTextSize(3);
  display.setCursor(10,25);
  display.print(voltage,3);
  display.println(" V");
  display.display();

  Serial.println(voltage,3);
  delay(500);
}
