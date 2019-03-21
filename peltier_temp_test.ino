/* Test code for controlling peltier element with temp sensor
 * Temp sensor on pin 5 and peltier on pin 6
 * MARCH 2019 Hanna Thenor Årström
 */

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 5

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

float Celcius=0;

int peltier = 6;

void setup() {
  Serial.begin(9600);
  sensors.begin();

}

void loop() {

  sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  Serial.print(" C  ");
  Serial.println(Celcius);
  // remapping values to send to peltier element
  float temp = map(Celcius, 20, 25, 0, 255);
  Serial.print(" temp " );
  Serial.println(temp);
  analogWrite(peltier, temp);
  delay(500);

}
