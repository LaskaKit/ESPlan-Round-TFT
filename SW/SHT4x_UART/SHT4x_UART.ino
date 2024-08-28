/*
* This example code is used for LaskaKit ESPlan-Round-TFT board 
* with  Temperature and Humidity SHT40 sensor on board
* Board reads temperature and humidity from SHT40 sensor 
* and sends every second through UART
* 
*
* Made by (c) laskakit.cz 2024
*
* Libraries: https://github.com/Sensirion/arduino-i2c-sht4x
* 
*/

#include <SensirionI2cSht4x.h>


SensirionI2cSht4x sht4x;

void setup() {
  Serial.begin(115200);

  Wire.begin(33, 32);            // set dedicated I2C pins 33 - SDA, 32 - SCL

  uint16_t error;
  char errorMessage[256];

  sht4x.begin(&Wire);

  uint32_t serialNumber;
  error = sht4x.serialNumber(serialNumber);
  if (error) {
      Serial.print("Error trying to execute serialNumber(): ");
      errorToString(error, errorMessage, 256);
      Serial.println(errorMessage);
  } else {
      Serial.print("Serial Number: ");
      Serial.println(serialNumber);
  }
}

void loop() {
  uint16_t error;
  char errorMessage[256];
  float temperature;
  float humidity;
  
  error = sht4x.measureHighPrecision(temperature, humidity);
  if (error) {
      Serial.print("Error trying to execute measureHighPrecision(): ");
      errorToString(error, errorMessage, 256);
      Serial.println(errorMessage);
  } else {
      Serial.print("Temperature:");
      Serial.print(temperature);
      Serial.print("\t");
      Serial.print("Humidity:");
      Serial.println(humidity);
  }
  
  delay(1000);

}
