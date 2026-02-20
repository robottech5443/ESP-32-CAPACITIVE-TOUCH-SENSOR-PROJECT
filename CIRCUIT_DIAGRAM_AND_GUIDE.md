# ESP-32 Capacitive Touch Sensor with LED Control - Circuit Diagram

## Overview
This project uses the ESP-32's built-in capacitive touch sensors to detect touches on aluminum foil pads and control 2 LEDs. When the aluminum foil is touched, the corresponding LED lights up.

---

## 📋 Component List

| Component | Quantity | Details |
|-----------|----------|---------|
| ESP-32 Microcontroller | 1 | Any ESP-32 board (DevKit, WROOM, etc.) |
| LED (5mm or 3mm) | 2 | Red, Green, or any color |
| Resistor (220Ω) | 2 | 1/4W, 5% tolerance or better |
| Aluminum Foil | 2 | ~10cm x 10cm sheets (touch pads) |
| Connecting Wire | 6+ | 22 AWG or similar, preferably with breadboard connectors |
| Breadboard (optional) | 1 | For easier connections |
| GND/Power Rails | As needed | Ground and 3.3V |

---

## 🔌 Pin Configuration

### ESP-32 Pins Used:
- **GPIO4 (T0)**: Capacitive Touch Sensor 1 (Aluminum Foil 1)
- **GPIO0 (T1)**: Capacitive Touch Sensor 2 (Aluminum Foil 2)
- **GPIO12**: LED 1 Control (with 220Ω resistor)
- **GPIO13**: LED 2 Control (with 220Ω resistor)
- **GND**: Ground (connect all GND points together)
- **3.3V**: Power supply (for LEDs via resistors)

---

## 📐 Connection Diagram

```
                    ESP-32 DEVKIT
             ┌────────────────────────┐
             │                        │
    GPIO4(T0)├──────────────────────┐ │
             │                      │ │
    GPIO0(T1)├──────────────────────┼─┤ 
             │                      │ │
   GPIO12(D12)├─┐                   │ │
             │ │                    │ │
   GPIO13(D13)├─┼────────────┐      │ │
             │ │            │      │ │
    GND(GND) ├─┼────────────┼──────┐ │
             │ │            │      │ │
    3.3V     ├─┘            │      │ │
             │              │      │ │
             └────────────────────────┘
                    │         │
                    │         │
        ┌───────────┘         │
        │         ┌───────────┘
        │         │
    [220Ω] [220Ω]     (Resistors - current limiting)
        │         │
        ▼         ▼
      [LED1]   [LED2]
        │         │
        └─────────┴─────────── (Connected to GND)


    ALUMINUM FOIL CONNECTIONS (Touch Sensors)
    
    Aluminum Foil 1                Aluminum Foil 2
    (~10cm x 10cm)                (~10cm x 10cm)
         │                              │
         └──────────────────┬───────────┘
                            │
                      Touch Sensors
```

---

## 🔧 Step-by-Step Connection Guide

### Step 1: Prepare the Aluminum Foil Pads
1. Cut two pieces of aluminum foil approximately 10cm × 10cm
2. Attach wires to each piece using solder or conductive tape
3. Label them as "Foil 1" and "Foil 2"
4. Wrap them in tape if needed (recommended for safety)

### Step 2: Connect Touch Sensors
- **Aluminum Foil 1** → Connect wire to **ESP-32 GPIO4 (T0)**
- **Aluminum Foil 2** → Connect wire to **ESP-32 GPIO0 (T1)**

### Step 3: Connect LED 1
1. Connect one leg of the 220Ω resistor to **ESP-32 GPIO12**
2. Connect the other leg of the resistor to the **positive (longer) leg of LED 1**
3. Connect the **negative (shorter) leg of LED 1** to **GND**

### Step 4: Connect LED 2
1. Connect one leg of the second 220Ω resistor to **ESP-32 GPIO13**
2. Connect the other leg of the resistor to the **positive (longer) leg of LED 2**
3. Connect the **negative (shorter) leg of LED 2** to **GND**

### Step 5: Connect Ground
- Connect all **GND points** together (ESP-32 GND, LED cathodes, any other components)

---

## 📊 Detailed Schematic (ASCII Art)

```
ESP-32 Microcontroller Unit
┌──────────────────────────────────────┐
│  ┌─────────┐    ┌────────┐           │
│  │  GPIO4  │───→│ Touch 1│───→ Foil1 │
│  └─────────┘    └────────┘           │
│                                       │
│  ┌─────────┐    ┌────────┐           │
│  │  GPIO0  │───→│ Touch 2│───→ Foil2 │
│  └─────────┘    └────────┘           │
│                                       │
│  ┌─────────┐                         │
│  │ GPIO12  │──→ [220Ω] ──→ [LED1] ──→ GND
│  └─────────┘                    ↓    │
│                                │     │
│  ┌─────────┐                   │     │
│  │ GPIO13  │──→ [220Ω] ──→ [LED2] ──→ GND
│  └─────────┘                   ↓    │
│                                │     │
│  ┌─────────┐                   │     │
│  │   GND   │───────────────────┴─────┘
│  └─────────┘
└──────────────────────────────────────┘
```

---

## 💻 Code Details

The Arduino sketch (capacitive_touch_led.ino) includes:

- **Touch Threshold**: Set to 40 (adjustable if needed)
- **Touch Detection Logic**: When aluminum foil is touched, the touch value drops below the threshold
- **LED Control**: 
  - LED turns ON when touch detected
  - LED turns OFF when touch is released
- **Serial Debugging**: Outputs touch sensor values and LED status to Serial Monitor

### Key Functions:
```cpp
touchRead(TOUCH_PIN)  // Reads capacitive value from touch pin
digitalWrite(LED_PIN, HIGH/LOW)  // Controls LED on/off
Serial.println()  // Debug output
```

---

## ⚡ Power Considerations

- **ESP-32 Operating Voltage**: 3.3V
- **LED Forward Voltage**: ~2V (typical red LED)
- **Current through 220Ω Resistor**: ~(3.3V - 2V)/220Ω ≈ 5.9mA (safe for ESP-32 GPIO)
- **GPIO Max Current**: 40mA (per pin), 200mA total

---

## 🔧 Calibration & Troubleshooting

### Adjusting Touch Sensitivity
If the touch sensor is too sensitive or not sensitive enough, modify the TOUCH_THRESHOLD value

### Debug Steps:
1. Open Serial Monitor (Baud: 115200)
2. Observe touch values without touching
3. Touch aluminum foil and observe value change
4. Adjust threshold if needed

### Common Issues:
| Issue | Solution |
|-------|----------|
| LED doesn't turn on | Check connections, verify GPIO pins, check LED polarity |
| Touch not detected | Ensure aluminum foil is properly connected, adjust threshold |
| LED is dim | Verify 220Ω resistor value, check LED connections |
| Erratic behavior | Ensure good wire connections, check for loose contacts |

---

## 📝 Programming & Upload

1. Install Arduino IDE or PlatformIO
2. Install ESP-32 board package in Arduino IDE
3. Open the capacitive_touch_led.ino file
4. Select the correct board and COM port
5. Click Upload
6. Open Serial Monitor to see output

---

## 🎯 How It Works

1. **Capacitive Touch Detection**: ESP-32 has built-in touch sensors that measure capacitance
2. **Touch Event**: When you touch the aluminum foil with your finger, capacitance increases
3. **Value Change**: The touchRead() value drops (becomes lower)
4. **Threshold Comparison**: If value < TOUCH_THRESHOLD → LED turns ON
5. **Release**: When you remove your finger, value returns to normal → LED turns OFF

---

## 🔐 Safety Notes

- Use 220Ω resistors to protect GPIO pins
- Do not exceed 40mA per GPIO pin
- Ensure proper polarity when connecting LEDs
- Keep connections tight to avoid false touches
- Do not connect 5V directly to ESP-32 pins (use 3.3V only)

---

## ✨ Future Enhancements

- Add more touch sensors (up to 10 supported by ESP-32)
- Create animations/patterns with multiple LEDs
- Add EEPROM to save calibration values
- Integrate with WiFi/Bluetooth for remote control
- Add sound effects with a buzzer