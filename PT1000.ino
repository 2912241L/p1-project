//resistance of thermisistor 
float resistance = 1600; //out here means global variable available in btoh parts)
float temperaturept;
void setup() {
  //put setup code to run here - to run once 
  Serial.begin(9600); //beginning a connection at 9600 bits per second - maybe change as different microcontroler 
}

void loop() {
  //put main code here, to run repeatedly 
int sensorValue = analogRead(27); //read analog pin 27 (in this case 3v3)
float sensorValue2 = sensorValue;
float voltage = 3.3 * (sensorValue2 / 4096); //max number of bits 2^12 - pico?
Serial.println(voltage)

float thermResistance = (voltage * resistance)/(3.3-voltage); //convert voltage to resistance 
temperaturept = (thermResistance - 1000)/3.85; // resistance to temperature conversion
Serial.println(temperaturept)

delay(2000); //ensures time between output values 

}
