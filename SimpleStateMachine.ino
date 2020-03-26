int pushButton=A0;
int counterPushed = 0;
int led = 12;
int ExternalLED=12;
int InternalLED=13;

void setup() {
  Serial.begin(9600);
   pinMode(pushButton, INPUT); //initializes the button
   pinMode(ExternalLED, OUTPUT); //initializes the LED
   pinMode(InternalLED, OUTPUT);
}

void loop() {
  int statePushed = digitalRead(pushButton);
  if (statePushed == HIGH)
  {
    counterPushed++;
    delay(100);
  }
  if(counterPushed==4) //if the button was pushed 4 times the LED will light up
  {
    digitalWrite(led,HIGH);
  }
  if (counterPushed==5) //if the button is pushed a 5th time, the cycle resets, and the LED will shut off.
  {               //it will turn on again once the button is pressed 4 more times, cycling back infinitely until the code is manually terminated.
    digitalWrite(led,LOW);
    counterPushed=0; //used to restart the button pushing cycle.
  }          

}
