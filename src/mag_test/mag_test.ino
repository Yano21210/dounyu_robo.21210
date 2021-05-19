#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

uint16_t BNO055_SAMPLERATE_DELAY_MS = 100;

Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

void setup(void)
{
  Serial.begin(115200);
  /* Initialise the sensor */
  bno.begin();
  delay(1000);
}



void loop(void)
{
  sensors_event_t magnetometerData;
  bno.getEvent(&magnetometerData, Adafruit_BNO055::VECTOR_MAGNETOMETER);
  printEvent(&magnetometerData);

  uint8_t system, gyro, accel, mag = 0;
  delay(BNO055_SAMPLERATE_DELAY_MS);

}

void printEvent(sensors_event_t* event) {
  double x = -1000000, y = -1000000 , z = -1000000; //dumb values, easy to spot problem
  if (event->type == SENSOR_TYPE_MAGNETIC_FIELD) {
    //Serial.print("Mag:");
    x = event->magnetic.x;
    y = event->magnetic.y;
    z = event->magnetic.z;
    
  }//Serial.print("\tx= ");
//  Serial.print(x);
//  Serial.print(" |\ty= ");
//  Serial.print(",");
//  Serial.print(y);
//  Serial.print(" |\tz= ");
//  Serial.print(",");
//  Serial.println(z);
    Serial.println(atan2(y,x)*180/PI);
}
