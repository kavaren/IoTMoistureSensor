#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <Ewma.h>

Ewma adcFilter1(0.1);
Ewma adcFilter2(0.01);    
Ewma adcFilter3(0.001); 
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

const int AirValue = 361;  
const int WaterValue = 275; 
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

  display.setTextSize(2);
  display.setTextColor(WHITE);  
}

void loop() {


  int raw = analogRead(A0);
  int filtered1 = adcFilter1.filter(raw);
  int filtered2 = adcFilter2.filter(raw);
  int filtered3 = adcFilter3.filter(raw);

  soilMoistureValue = analogRead(A0);  //put Sensor insert into soil
  int procent = map(filtered2, WaterValue, AirValue, 100, 0);
  
  Serial.print(soilMoistureValue);
  Serial.print(", ");
  Serial.print(filtered1);
  Serial.print(", ");
  Serial.print(filtered2);
  Serial.print(", ");
  Serial.print(filtered3);
  Serial.println();

  display.clearDisplay();
  display.setCursor(0, 10);
  display.println("Wilgotnosc");
  display.print(procent);
  display.println("%");

  if(procent <= 30){
    display.print("Sucho");
  }else if (procent > 30 && procent <= 70)
  {
    display.print("Wilgotno");
  }else if (procent > 70)
  {
    display.print("MOKRO");
  }
  
  display.display(); 
  delay(10);
}
 