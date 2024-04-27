#define LED_AMOUNT 4
// 2, 3, 4, 5
#define LED_START 2

void setup() {
  for(int i = 0; i < LED_AMOUNT; i++) {
    pinMode(LED_START + i, OUTPUT);
    digitalWrite(LED_START + i, LOW);
  }
  
  Serial.begin(9600);

  // Pretty lights!
  setState(15);
  delay(250);
  setState(0);
  delay(250);
  setState(15);
  delay(250);
  setState(0);
}

void setState(int data) {
  for(int i = 0; i < LED_AMOUNT; i++) {
    int state = (data >> i) & 1;
    
    digitalWrite(LED_START + (LED_AMOUNT - 1) - i, state > 0 ? HIGH : LOW);
  }
}

void loop() {
  if( Serial.available() > 0 ) {
    int data = int(Serial.read());
    setState(data);
  }
}
