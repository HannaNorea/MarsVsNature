/*int buttonPin = 3;
int buttonInput = 1; 
int buttonState = 0; 
*/
int peltier = 6;

void setup() {
Serial.begin(115200);
//pinMode(buttonPin, INPUT);

}

void loop() {

analogWrite(peltier, 255);
//delay(500);
//analogWrite(peltier, 0);
//delay(500);// Look first on how much voltage your peltier unit can handle 255 = 5V
Serial.println("on");
//delay(5000);
//
//analogWrite(peltier, 0);
//Serial.println("off");
//delay(1000);
}
