#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

const int AirValue = 370;  
const int WaterValue = 276; 
int intervals = (AirValue - WaterValue)/3;
int soilMoistureValue = 0;
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
int i;
void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
}

void loop() {

  soilMoistureValue = analogRead(A0);  //put Sensor insert into soil
  int procent = map(soilMoistureValue, WaterValue, AirValue, 100, 0);
  Serial.println(procent);

  if(soilMoistureValue > WaterValue && soilMoistureValue < (WaterValue + intervals))
  {
    Serial.println("Very Wet");
  }
  else if(soilMoistureValue > (WaterValue + intervals) && soilMoistureValue < (AirValue - intervals))
  {
    Serial.println("Wet");
  }
  else if(soilMoistureValue < AirValue && soilMoistureValue > (AirValue - intervals))
  {
    Serial.println("Dry");
  }
  delay(100);

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("Wilgotnosc");
  display.print(procent);
  display.println("%");

  if(soilMoistureValue > WaterValue && soilMoistureValue < (WaterValue + intervals))
  {
    display.println("MOKRO");
  }
  else if(soilMoistureValue > (WaterValue + intervals) && soilMoistureValue < (AirValue - intervals))
  {
    display.println("Wilgotno");
  }
  else if(soilMoistureValue < AirValue && soilMoistureValue > (AirValue - intervals))
  {
    display.println("Sucho");
  }

  display.display(); 
  delay(2000);
  
}
 