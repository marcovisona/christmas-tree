/*
  Christmas tree lights
*/
#define BUTTON 2
#define SOUND_BUTTON 2
#define BUZZER_PIN 8

const int ledPins[] = { 12, 11, 10, 9, 7, 6, 5, 3 };  // the number of the LED pin
const int len = sizeof(ledPins) / sizeof(int);

int ledState[] = { LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW };         // ledState used to set the LED
unsigned long previousMillis[] = { 0, 0, 0, 0, 0, 0, 0, 0 };         // will store last time LED was updated
const long interval[] = { 600, 900, 700, 500, 800, 750, 950, 550 };  // interval at which to blink (milliseconds)
int prevButtonState;

void setup() {
  Serial.begin(9600);

  soundSetup(BUZZER_PIN);

  // set the digital pin as output:
  Serial.println(len);
  for (int i = 0; i < len; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  pinMode(BUTTON, INPUT);

  prevButtonState = digitalRead(BUTTON);

  tone(BUZZER_PIN, 1047, 50);
}


void loop() {

  static bool on = false;
  static bool changed = false;

  int val = digitalRead(BUTTON);  // legge il valore dell'input e lo conserva

  if (val == HIGH && prevButtonState == LOW) {
    changed = true;
    on = !on;
  }
  prevButtonState = val;


  soundLoop(on, changed);
  lightLoop(true);

  changed = false;
}

void lightLoop(bool on) {

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (on) {
    for (int i = 0; i < len; i++) {
      if (currentMillis - previousMillis[i] >= interval[i]) {
        // save the last time you blinked the LED
        previousMillis[i] = currentMillis;

        // if the LED is off turn it on and vice-versa:
        if (ledState[i] == LOW) {
          ledState[i] = HIGH;
        } else {
          ledState[i] = LOW;
        }

        // set the LED with the ledState of the variable:
        digitalWrite(ledPins[i], ledState[i]);
      }
    }
  } else {
    for (int i = 0; i < len; i++) {
      digitalWrite(ledPins[i], LOW);
    }
  }
}