#include <ESP8266Firebase.h>
#include <ESP8266WiFi.h>
#define FIREBASE_Host "https://esp8266-66b33-default-rtdb.asia-southeast1.firebasedatabase.app/"                  // Its my  Firebase Host
#define FIREBASE_authorization_key "yCcAUFhZp23ctOfCvdBVfEuxHbLimQSKZcK4jdWo" // Its my secret key
#define Your_SSID "Redmi"       // MY SSID ID
#define Your_PASSWORD "arravindh" //My  Password

String led_state = "";           // LED State
int led_gpio = 2;                                                               

void setup() {

  Serial.begin(9600);
  delay(1000);
  pinMode(2, OUTPUT);                
  WiFi.begin(Your_SSID, Your_PASSWORD);                                      
  Serial.print("Connecting to WIFI");
  while (WiFi.status() != WL_CONNECTED)
  Serial.print(".");
  delay(500);

  Serial.println();
  Serial.print("Connected to WIFI!");
  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());                                                      //print local IP address
  Firebase begin(FIREBASE_Host, FIREBASE_authorization_key);                                       // connect to firebase
  Firebase setString("LED State: ","OFF");                                         //send initial string of led status

}

void loop() 
{

   Firebase getString("LED State: ");
    led_state=("LED State: ");
      
  if (led_state == "ON") {                   

    Serial.println("Led is ON");                 
    digitalWrite(led_gpio, HIGH);                                                         

  }

  else if (led_state == "OFF") {             

    Serial.println("Led is OFF");
    digitalWrite(led_gpio, LOW);                                                         

  }

  else {
     Serial.println("Wrong value entered! Only ON or OFF accepted");

  }

}
