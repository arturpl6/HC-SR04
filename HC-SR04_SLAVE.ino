#define SLAVE_TRIGGER_PIN 12
#define SLAVE_ECHO_PIN 10 //raw echo
const unsigned long airClearDelay = 40;

bool slavePinState;

void setup() {
  Serial.begin(9600);
  pinMode(SLAVE_TRIGGER_PIN, OUTPUT);
  pinMode(SLAVE_ECHO_PIN, INPUT);
}

void loop() {
  
  slavePinState = digitalRead(SLAVE_ECHO_PIN);

  if (slavePinState)
  {
    delay(airClearDelay+20);
    digitalWrite(SLAVE_TRIGGER_PIN,LOW);
    digitalWrite(SLAVE_TRIGGER_PIN,HIGH);
    delayMicroseconds(15);
    digitalWrite(SLAVE_TRIGGER_PIN,LOW);
    Serial.println("Slave signal sent");
    delay(airClearDelay);
    slavePinState = 0;

  }
}
