
#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;

#define inPin D3

//for creating one minute delay

unsigned long previousMillis = 0;
unsigned long interval = 60000;


//login credentials for the wifi

const char* ssid = "BadBoys";   
const char* password = "study@exam";       


WiFiClient client;

unsigned long myChannelNumber = 1649330; 
const char * myWriteAPIKey = "Y1PS3ORXSZ0RTQFD"; 

void setup()
{
  Serial.begin(9600);
  delay(10);
  // Connect to WiFi network
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
   pinMode (inPin, INPUT);
}

void loop()
{

 static int counter=0;
 static int UnitConsumed=0;

 int output=digitalRead(inPin);

 if(output==1){
    Serial.println(output);
    
    }
   else{
    Serial.println(output);
    Serial.println("The led blinked");
    counter++;
    }

    if(counter ==10){
      Serial.println("There is one more  unit consumption");
      Serial.println(output);
      UnitConsumed++;
      
      counter=0;
      
      }

      //pusing data into the thingspeak cloud
  unsigned long currentMillis = millis();

if (currentMillis - previousMillis > interval) {
 previousMillis = currentMillis;
 ThingSpeak.writeField(myChannelNumber, 1,UnitConsumed, myWriteAPIKey); 
 Serial.println("Unit Consumption has been pushed into the cloud");
 
  
}
      
  
  
 
}
