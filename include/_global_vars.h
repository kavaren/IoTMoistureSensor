#pragma once

#include <Arduino.h>
#include <pinout.h>

#define BAUDRATE 9600
#define DELAY    100

extern int AirValue;
extern int WaterValue;
extern int SoilMoistureValue;
extern int MappedSensorValue;

extern double filtered1;
extern double filtered2;
extern double filtered3;