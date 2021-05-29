#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


void handleRoot(); 
void handleMainOff();
void handleMainOn();


ESP8266WebServer server(80);    // Create a webserver object that listens for HTTP request on port 80

// constants won't change. Used here to set a pin number:
const int ledPin1 =  12;// the number of the LED pin main light
const int ledPin2 =  13;// the number of the LED pin
const int ledPin3 =  14;// the number of the LED pin
const int ledPin4 =  15;// the number of the LED pin




// constants won't change:
const long delaytime = 100;           // interval at which to blink (milliseconds)

int mainLight = 1;

void setup() {
  // set the digital pin as output:
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(ledPin4, OUTPUT);
Serial.begin(115200);
  Serial.println();

  WiFi.begin("tslfg", "E4nREU3jercrbQY7");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
                // Call the 'handleRoot' function when a client requests URI "/"
  server.begin();                           // Actually start the server
  Serial.println("HTTP server started");
  server.on("/main/on", handleMainOn);               // Call the 'handleRoot' function when a client requests URI "/"
  server.on("/main/off", handleMainOff);               // Call the 'handleRoot' function when a client requests URI "/"
  server.on("/", handleRoot); 
}

void loop() {
if (mainLight == 1) {
analogWrite(ledPin1, random(105)+150);
} else {
  analogWrite(ledPin1, 0);
  
}
analogWrite(ledPin2, random(105)+150);
analogWrite(ledPin3, random(125)+130);
analogWrite(ledPin4, random(105)+150);
delay(random(delaytime));
server.handleClient();
}

void handleRoot() {

  //server.send(200, "text/html", "<p>Try 'John Doe' and 'password123' ...</p><p><form action=\"/main/off\" method=\"GET\"><input type=\"submit\" value=\"Off\"></form><form action=\"/main/on\" method=\"GET\"><input type=\"submit\" value=\"On\"></form></p>");
  server.send(200, "text/html", "<h1>The Hobbit book nook</h1><h2>Main light</h2><p style=\"width:100%;\"><button  style=\"width:100%; height:5em; font-size:40pt; font-weight:900; background-color:red;\" onclick=\"window.location.href='/main/off'\">Off</button></p><p><button  style=\"width:100%; height:5em; font-size:40pt; font-weight:900; background-color:green;\" onclick=\"window.location.href='/main/on'\">On</button></p>");

}
void handleMainOff() {
  mainLight = 0;
  Serial.print("Main off");
  server.sendHeader("Location", "/",true);   //Redirect to our html web page  
  server.send(302, "text/plane","");
}
void handleMainOn() {
  mainLight = 1;
  Serial.print("Main off");
  server.sendHeader("Location", "/",true);   //Redirect to our html web page  
  server.send(302, "text/plane","");
}
