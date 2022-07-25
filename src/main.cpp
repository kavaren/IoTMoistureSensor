#include <main.h>

void setup()
{
    delay(DELAY);
    Serial.begin(9600);
    delay(DELAY);
    initializeLcd();
    initializeMoisture();
}

void loop() 
{
    loopMoisture();
    loopLcd();

    Serial.print(SoilMoistureValue);
    Serial.print(", ");
    Serial.print(filtered1);
    Serial.print(", ");
    Serial.print(filtered2);
    Serial.print(", ");
    Serial.print(filtered3);
    Serial.println();

    delay(10);
}
