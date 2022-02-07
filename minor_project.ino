








//defining of the pin
#define inPin D3

void setup() {
  Serial.begin(9600);


 
//code for defining the pinmode
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode (inPin, INPUT);
}

// the loop function runs over and over again forever
void loop() {

 
   


  int output=digitalRead(inPin);

  if(output==1){
    Serial.println(output);
    
    }
   else{
    Serial.println(output);
    Serial.println("The led blinked");
    delay(1000);
    
    }
    

//Code for sending  data to the thingspeak cloud at the time of time of 1 min duration



  
}
