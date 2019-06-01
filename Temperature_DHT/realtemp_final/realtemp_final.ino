#include <FirebaseArduino.h> //Library สำหรับเชื่อมต่อ Firebase
#include <ESP8266WiFi.h> //Library สำหรับการใช้งาน ESP8266 กับ WiFi

#define WIFI_SSID "Room334" //SSID ของ WiFi ห้อง 334
#define WIFI_PASSWORD "334334334" //รหัสผ่าน WiFi ห้อง 334

#define FIREBASE_HOST "theeraphat-a723c.firebaseio.com" //URL ของ Firebase จากใน Realtime Database
#define FIREBASE_AUTH "IK9SGS2odR4rtsuxOGY14eVSkqQ11v8AK6VW6Cos"
//Database Secret Key (หาได้จาก - เฟือง > Project Settings > Service accounts > Database Secrets)


#include "DHT.h"

#define DHTPIN D1 // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11 // DHT 11 
//#define DHTTYPE DHT22 // DHT 22 (AM2302)
//#define DHTTYPE DHT21 // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(115200); //เริ่ม Serial Monitor ที่ 115200 baud

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); //เริ่มเชื่อมต่อ WiFi ด้วยค่าที่กำหนดไว้ที่บรรทัดที่ 4 และ 5
  Serial.print("Connecting"); //บอกสถานะว่ากำลังเชื่อมต่ออยู่

  while (WiFi.status() != WL_CONNECTED) { //ทำการวนรอบจนกว่า WiFi จะเชื่อมต่อได้
    Serial.print(".");
    delay(500);
  }
  //เมื่อเชื่อมต่อได้แล้วแสดงที่อยู่ IP ที่เชื่อมต่อ
  Serial.println();
  Serial.print("Connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); //เชื่อมต่อ Firebase ด้วยค่าที่กำหนดไว้ที่บรรทัดที่ 7 และ 8
  Serial.println("DHTxx test!");

dht.begin();

pinMode(D4, OUTPUT);


}
 String Status[2] = {"Danger", "Safe"};
void loop() {
// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
   float h = dht.readHumidity();
   float t = dht.readTemperature();

   int TempCommandAlert = Firebase.getInt("TempCommandAlert");

// check if returns are valid, if they are NaN (not a number) then something went wrong!
  Firebase.setFloat("temperature", t);
if(t > TempCommandAlert) {
  Firebase.setString("status", Status[0]);
  tone(D4, 1000);

} else {
  Firebase.setString("status", Status[1]);
  tone(D4, 0);
}

  

if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *C");
    delay(500); 
  }
  
}
