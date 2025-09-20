# 📟 ESP32 Digital Voltmeter with OLED + ADS1115  

## 📝 Project Description  

This project is a **💡 Digital Voltmeter** built with **⚡ ESP32**, an **📏 ADS1115 16-bit ADC**, and a **🖥️ 1.3″ I²C OLED (SSD1306)**.  
It demonstrates how to measure **analog voltages with high precision** and display them in **multiple visualization styles** on a compact OLED screen.  
The system can read up to **4 analog channels (A0–A3)**, supports both **direct measurements (<4.096 V)** and **extended ranges (0–12 V / 0–24 V)** using resistor dividers, and includes **calibration** to match real multimeter readings.  

## ✨ Features  

- ⚡ High-resolution **16-bit ADC** (ADS1115)  
- 🖥️ OLED output using SSD1306 driver  
- 🔌 Multi-channel support (A0–A3)  
- 📟 Three display modes:  
  - 🔢 **Big Digital Number** (precise value)  
  - 📊 **Bar Graph** (fill bar)  
  - 🎚️ **Needle Scale** (retro analog meter style)  
- ⚖️ Calibration + averaging filter for accurate readings  
- 🧩 Built with **Adafruit SSD1306, GFX, and ADS1X15 libraries**  


## ⚡ Hardware & Wiring  

### 📌 ESP32 ↔ OLED (SSD1306 I2C)  
| ESP32 Pin | OLED Pin |
|-----------|----------|
| 3.3V      | VCC      |
| GND       | GND      |
| GPIO21    | SDA      |
| GPIO22    | SCL      |

### 📌 ESP32 ↔ ADS1115  
| ESP32 Pin | ADS1115 Pin |
|-----------|-------------|
| 3.3V      | VCC         |
| GND       | GND         |
| GPIO21    | SDA         |
| GPIO22    | SCL         |

### 📌 Input Voltage  
- Positive → **A0**  
- Negative → **GND**  
- Use a resistor divider if input >4.096 V  
  - Example: 20kΩ + 10kΩ = 0–12 V range  

## 🖥️ Display Modes  
1️⃣ Big Digital Number  
2️⃣ Bar Graph  
3️⃣ Needle-Style Analog Scale  
4️⃣ Multi-Channel Mode

## 📚 Required Libraries  

Install via Arduino IDE Library Manager:  
- [Adafruit ADS1X15](https://github.com/adafruit/Adafruit_ADS1X15)  
- [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306)  
- [Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library)  

## 🚀 Future Improvements  

- 🔘 Mode toggle via button → switch between **Digital, Bar Graph, Needle, Multi-channel**   
- 🌐 WiFi/Bluetooth integration → live data logging  
- 🔋 Battery status indicator & auto-ranging  



