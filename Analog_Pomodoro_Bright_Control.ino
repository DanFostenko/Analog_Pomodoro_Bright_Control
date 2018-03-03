/*
 * Pomodoro timer. Have a rest for 5 minutes after 20 minutes of work.
 * Analog fade of external LED.
 * Brightness is regulated by potentiometer.
 */

#define LED_PIN 9 // Define LED on 9th PWM pin
char POT_PIN = A0; // Potentiometer
long int workTime = 120000; // 20 Minutes = 1200000 Milliseconds, Time of work
const byte delayTime = 1; // 1 second = 1000 Milliseconds, Time of blink
//int k = 0; // unsigned char k = 0; LED will work faster
int rotation, brightness;
  
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(POT_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_PIN, LOW);

  delay(workTime); // Work

  long finishTime = 300000; // 5 Minutes = 300000 Milliseconds, declare local variable, time of rest
  for (long i = 0; i <= finishTime; i++) { // Rest time
  
  rotation = analogRead(POT_PIN); // Read rotation 0..1024
  brightness = rotation / 4; // Get brighness 0..255
  analogWrite(LED_PIN, 0); // Give result to LED
  
    for (brightness; brightness <=255; brightness++) { // Increase brightness
      analogWrite(LED_PIN, brightness);
      delay(delayTime);
    }
    for (brightness; brightness >= 0; brightness--) { // Decrease brightness
      analogWrite(LED_PIN, brightness);
      delay(delayTime);
    }
  finishTime = finishTime - (delayTime * 2 * 256);
  }
}