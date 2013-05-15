/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led_tx = 72;
int led_rx = 73;

// the setup routine runs once when you press reset:
void setup() 
{                
  // initialize the digital pin as an output.
  pinMode(led_tx, OUTPUT);     
  pinMode(led_rx, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() 
{
  digitalWrite(led_tx, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led_rx, LOW);
  delay(500);               // wait for a second
  digitalWrite(led_tx, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(led_rx, HIGH);
  delay(500);               // wait for a second
}
