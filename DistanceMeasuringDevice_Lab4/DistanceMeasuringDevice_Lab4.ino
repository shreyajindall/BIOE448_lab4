const int trigPin = 11;
const int echoPin = 12;
long duration;
int distanceCm, distanceInch;
int Threshold = 5; // in cms
void setup() {
  // put your setup code here, to run once:
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
pinMode(2,OUTPUT); // red LED, greater than threshold
pinMode(4, OUTPUT); // green LED, less than threshold
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm = duration /58;
distanceInch = duration / 148;
Serial.print("Distance: ");
Serial.print(distanceCm);
Serial.print(" cm/");
Serial.print(distanceInch);
Serial.println(" in");
if (distanceCm>Threshold){
digitalWrite(2, HIGH);
digitalWrite(4, LOW);
}
else{
digitalWrite(4, HIGH);
digitalWrite(2, LOW); 
}
delay(1000);

}
