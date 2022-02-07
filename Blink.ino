unsigned long previousMillis = 0;
unsigned long interval = 60000;



void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);    
}


void loop() {
  digitalWrite(LED_BUILTIN, LOW);   
  delay(1000);                      
  digitalWrite(LED_BUILTIN, HIGH);  
  delay(2000); 

  unsigned long currentMillis = millis();

if (currentMillis - previousMillis > interval) {
 previousMillis = currentMillis;
 Serial.println("This is after a minute man");
 
  
}

                       
}
