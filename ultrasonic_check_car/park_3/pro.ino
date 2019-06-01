#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>
#include <Ultrasonic.h> 
#define WIFI_SSID "Room334"
#define WIFI_PASSWORD "334334334" 
#define FIREBASE_HOST "theeraphat-a723c.firebaseio.com" 
#define FIREBASE_AUTH "IK9SGS2odR4rtsuxOGY14eVSkqQ11v8AK6VW6Cos"
unsigned long ShowTime;
Ultrasonic ultrasonic(D0,D1); 
int distance,count=0; 
void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); 
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 
}
  int before=0,after=0;
  int past_car=0;
void loop() {
  //time current
  Serial.print("Time: ");
  ShowTime = millis();
  Serial.println(ShowTime/1000);
  distance = ultrasonic.read(CM);

  //time
  if(distance<30){  
    count++;
    after=ShowTime;
  }
  if(count==1 && distance<30){
    before=ShowTime;
  }
  
  if(distance > 30 && count > 0 ){
    past_car = after/1000 - before/1000;
    before=0;
    after=0;
    count=0; 
   }

  int realTime= after/1000 - before/1000;

//print  
  Serial.println(past_car);
  Serial.print("Distance in CM: "); 
  Serial.println(distance);
  Serial.println(after-before);

 //firebase 
  Firebase.setInt("Park_3/S",distance);
  Firebase.setInt("Park_3/TotalTime",past_car);
  Firebase.setInt("Park_3/DurationTime",realTime);

  
  delay(1000);
  /*Serial.print("Time: ");
  ShowTime = millis();
  Serial.println(ShowTime/1000);
  Firebase.setInt("TIME3",distance);*/
}
