#define BUTTON_PORT 7
#define LED_PORT 6

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON_PORT, INPUT);
  pinMode(LED_PORT, OUTPUT);
  digitalWrite(LED_PORT, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  int buttonState = digitalRead(BUTTON_PORT);
  
  if (buttonState == HIGH)
    digitalWrite(LED_PORT, HIGH);
  else
    digitalWrite(LED_PORT, LOW);

}
