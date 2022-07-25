#include <iot_LCD.h>

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


void initializeLcd()
{
    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
    {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;);
    }

    display.setTextSize(2);
    display.setTextColor(WHITE);
}

void loopLcd()
{
    display.clearDisplay();
    display.setCursor(0, 10);
    display.println("Wilgotnosc");
    display.print(MappedSensorValue);
    display.println("%");

    if(MappedSensorValue <= 30)
    {
        display.print("Sucho");
    }
    else if (MappedSensorValue > 30 && MappedSensorValue <= 70)
    {
        display.print("Wilgotno");
    }
    else if (MappedSensorValue > 70)
    {
        display.print("MOKRO");
    }

    display.display();
}
