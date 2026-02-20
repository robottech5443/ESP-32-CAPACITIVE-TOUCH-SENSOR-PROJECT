#include <Arduino.h>

// Define touch pins and LED pins
const int TOUCH_PIN_1 = T0;  // GPIO4 - Touch Pin 0 (Aluminum Foil 1)
const int TOUCH_PIN_2 = T1;  // GPIO0 - Touch Pin 1 (Aluminum Foil 2)
const int LED_PIN_1 = 12;    // GPIO12 - LED 1
const int LED_PIN_2 = 13;    // GPIO13 - LED 2

// Touch threshold value
const int TOUCH_THRESHOLD = 40;

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  // Configure LED pins as outputs
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  
  // Turn off LEDs initially
  digitalWrite(LED_PIN_1, LOW);
  digitalWrite(LED_PIN_2, LOW);
  
  Serial.println("ESP-32 Capacitive Touch Sensor with LED Control");
  Serial.println("Touch the aluminum foil sensors to toggle LEDs!");
}

void loop() {
  // Read capacitive touch sensor values
  int touchValue1 = touchRead(TOUCH_PIN_1);
  int touchValue2 = touchRead(TOUCH_PIN_2);
  
  // Print touch values for debugging
  Serial.print("Touch Sensor 1: ");
  Serial.print(touchValue1);
  Serial.print(" | Touch Sensor 2: ");
  Serial.println(touchValue2);
  
  // Check if touch sensor 1 is touched (value drops below threshold)
  if (touchValue1 < TOUCH_THRESHOLD) {
    digitalWrite(LED_PIN_1, HIGH);  // Turn ON LED 1
    Serial.println("LED 1 ON - Touch Sensor 1 Detected!");
  } else {
    digitalWrite(LED_PIN_1, LOW);   // Turn OFF LED 1
  }
  
  // Check if touch sensor 2 is touched (value drops below threshold)
  if (touchValue2 < TOUCH_THRESHOLD) {
    digitalWrite(LED_PIN_2, HIGH);  // Turn ON LED 2
    Serial.println("LED 2 ON - Touch Sensor 2 Detected!");
  } else {
    digitalWrite(LED_PIN_2, LOW);   // Turn OFF LED 2
  }
  
  delay(100);  // Small delay to avoid overwhelming serial output
}