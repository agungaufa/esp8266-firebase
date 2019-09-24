#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "db-firebase-230695.firebaseio.com"
#define FIREBASE_AUTH "TlTf54lV6Ero0y6bYG0XGh5YT5JQQc0zAmgOw7QN"
#define WIFI_SSID "@wifi.id open"
#define WIFI_PASSWORD "12345678"

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
long randNumPh;
long randNumTemp;

void loop() {

  randNumPh = random(0,14);
  randNumTemp = random(0,40);
  Serial.println(randNumPh);
  Serial.println(randNumTemp);
  // update value
  Firebase.setFloat("sensor/ph", randNumPh);
  Firebase.setFloat("sensor/suhu", randNumTemp);
  Firebase.succes();
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  

}
