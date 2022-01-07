int fan=11;
int probe=A5;
int probeVal;
int adjvolt;
float voltmap;

float fanVal;
int voltage;

int del=100;
int percentage;

String msg="Voltage too low! Fan off for safety.";


void setup() {
Serial.begin(9600);
pinMode(fan,OUTPUT);
pinMode(probe,INPUT);

}

void loop() {

adjvolt=map(probeVal, 0, 1023, 0, 255);
voltmap=map(adjvolt, 0, 255, 0., 100.);

probeVal=analogRead(probe);
fanVal=(255./1023.)*probeVal; 

// analogWrite(fan,fanVal);
analogWrite(fan,adjvolt);
Serial.println(voltmap);


}
