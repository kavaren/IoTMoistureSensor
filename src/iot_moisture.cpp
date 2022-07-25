#include <iot_moisture.h>

Ewma adcFilter1(0.1);
Ewma adcFilter2(0.01);
Ewma adcFilter3(0.001);

void initializeMoisture()
{}

void loopMoisture()
{
    SoilMoistureValue = analogRead(MOISTURE_ADDR);  //put Sensor insert into soil
    filtered1 = adcFilter1.filter(SoilMoistureValue);
    filtered2 = adcFilter2.filter(SoilMoistureValue);
    filtered3 = adcFilter3.filter(SoilMoistureValue);
    MappedSensorValue = map(filtered2, WaterValue, AirValue, 100, 0);
}

