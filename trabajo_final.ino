const int pinPotentiometer = A0;  // The analog pin where the potentiometer is connected
int mappedValue = 0;              // Variable to store the mapped value
int START_BUTTON = 4;
int STOP_BUTTON = 3;
int SHUTDOWN_PIN = 5;
bool isStartButtonPressed = false;
bool isStopButtonPressed = false;
bool runProgram = false;
bool programRunning = false;

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 baud
  pinMode(START_BUTTON, INPUT_PULLUP);
  pinMode(STOP_BUTTON, INPUT_PULLUP);
  pinMode(SHUTDOWN_PIN, OUTPUT);
  digitalWrite(SHUTDOWN_PIN,LOW);
}

void loop() {
  isStartButtonPressed = readButton(START_BUTTON);
  isStopButtonPressed = readButton(STOP_BUTTON);

  if (isStartButtonPressed && !isStopButtonPressed && !programRunning) {
    digitalWrite(SHUTDOWN_PIN,LOW);
    programRunning = true;
    runProgram = true;
  } else if (isStopButtonPressed) {
    digitalWrite(SHUTDOWN_PIN,HIGH);
    programRunning = false;
    runProgram = false;
  }

  if (runProgram) {
    mapPotentiometer();
  }

  delay(100);  // Wait for a short period of time before reading the potentiometer again
}

void mapPotentiometer() {
  int potentiometerValue = analogRead(pinPotentiometer);  // Read the potentiometer value (0-1023)

  // Map the potentiometer value to the range of 30 to 90
  mappedValue = map(potentiometerValue, 0, 1023, 30, 90);
  Serial.print("Potentiometer value: ");
  Serial.print(potentiometerValue);
  Serial.print(" - Mapped value: ");
  Serial.println(mappedValue);
}

bool readButton(int pin) {
  return digitalRead(pin) == LOW;
}
