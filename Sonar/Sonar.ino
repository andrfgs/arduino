const int trigPin = 4;
const int echoPin = 2;

void setup() {
Serial.begin(9600);
}
void loop(){
int duration; // duration of the round trip
int cm; // distance of the obstacle
//The sensor is triggered by a HIGH pulse of 10 or more ms.
//Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
pinMode(trigPin, OUTPUT);
digitalWrite(trigPin, LOW);
delayMicroseconds(3);
// Start trigger signal
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Read the signal from the sensor: a HIGH pulse whose
// duration is the time (in microseconds) from the sending
// of the ping to the reception of its echo off of an object.
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
// convert the time into a distance
cm = 17*duration/1000.0; // cm=17* duration/1000
Serial.print(cm);
Serial.println(" centimeters");
delay(100);
// The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
// Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
pinMode(pingPin, OUTPUT);
digitalWrite(pingPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(5);
digitalWrite(pingPin, LOW);
// The same pin is used to read the signal from the PING))): a HIGH
// pulse whose duration is the time (in microseconds) from the sending
// of the ping to the reception of its echo off of an object.
pinMode(pingPin, INPUT);
duration = pulseIn(pingPin, HIGH);
// convert the time into a distance
cm = microsecondsToCentimeters(duration);
