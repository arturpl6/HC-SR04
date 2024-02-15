#define MASTER_TRIGGER_PIN 10
#define MASTER_ECHO_PIN 11 //raw echo
#define SPEED_OF_SOUND 34.4 // Speed of sound in meters/microsec
#define CLEARING_DELAY 40 // 40 milliseconds in microseconds


const unsigned long airClearDelay = 40;
unsigned long CurrentTime = 0;
unsigned long PrevTime = 0;

unsigned long TimeOut = 100000;


unsigned long mainClockStart = 0;
bool slavePinState;
bool masterPinState;

unsigned long timeDelta;


bool flipFlop = 0;
void setup() {
  Serial.begin(9600);
  pinMode(MASTER_TRIGGER_PIN, OUTPUT);
  pinMode(MASTER_ECHO_PIN, INPUT);
}

void loop() {
  start:
  digitalWrite(MASTER_TRIGGER_PIN,LOW);
  digitalWrite(MASTER_TRIGGER_PIN,HIGH);
  delayMicroseconds(16);
  digitalWrite(MASTER_TRIGGER_PIN,LOW);
  delay(airClearDelay);
  mainClockStart = micros();
  CurrentTime = mainClockStart;
  PrevTime = CurrentTime;
  do
  {
    CurrentTime = micros();
    
    if(CurrentTime - PrevTime >= TimeOut)
    {
      PrevTime = CurrentTime;
      Serial.println("Time overflow MASTER NO SIGNAL");
      goto start;
    }
    
    masterPinState = digitalRead(MASTER_ECHO_PIN);


  }while(!masterPinState);

 timeDelta = ((CurrentTime - mainClockStart)-24040);
   int pomiar = timeDelta * 0.034; //pojedyńczy pomiar
 Serial.print("MASTER Time delta: ");
  Serial.println(timeDelta);
  Serial.print("Distance: ");
  Serial.println(timeDelta*0.034);
  delay(airClearDelay);
  
  

}
