📄 Project Description
This project is a 💡 Digital Voltmeter built with ⚡ ESP32, an 📏 ADS1115 16-bit ADC, and a 🖥️ 1.3″ I²C OLED (SSD1306).
It demonstrates how to measure analog voltages with high precision and display them in multiple visualization styles on a compact OLED screen.

✨ Key Highlights
🛠️ Reads up to 4 analog channels (A0–A3) from the ADS1115
🔌 Supports direct measurement (<4.096 V) and extended ranges (0–12 V / 0–24 V) using resistor dividers
📟 Display Modes:
🔢 Big Digital Number → clear numerical display
📊 Bar Graph → analog-style fill bar
🎚️ Needle Scale → retro-style moving needle across a scale
⚖️ Calibration included to match real multimeter readings
🧩 Built using Adafruit SSD1306, GFX, and ADS1X15 libraries in Arduino IDE

🚀 Future Improvements
🔘 Mode toggle button → Switch between Big Number, Bar Graph, Needle, Multi-channel
📊 Multi-channel OLED display → show all A0–A3 combined
🌐 WiFi/Bluetooth integration → Live data logging & IoT dashboard
🔋 Battery status indicator & auto-ranging for more professional performance
