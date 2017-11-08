#include <LWiFi.h>
#include "DHT.h"
#define DHTPIN 2   
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

char ssid[] = "apple";      //  your network SSID (name)
char pass[] = "star8693";   // your network password
int keyIndex = 0;           // your network key Index number (needed only for WEP)


int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
                Serial.begin(9600);                        // initialize serial communication
                pinMode(LED_BUILTIN, OUTPUT);             // set the LED pin mode
                while (status != WL_CONNECTED) {
                  Serial.print("Attempting to connect to Network named: ");
                  Serial.println(ssid);                    // print the network name (SSID);
                  status = WiFi.begin(ssid, pass);
                }
                server.begin();                           // start the web server on port 80
                printWifiStatus();                        // you're connected now, so print out the status
              }


void loop() {
              float h = dht.readHumidity();
              float t = dht.readTemperature();
              if (isnan(t) || isnan(h)) {
                  Serial.println("Failed to read from DHT");
              } 
              else {
                  Serial.print("Humidity: "); 
                  Serial.print(h);
                  Serial.print(" %\t");
                  Serial.print("Temperature: "); 
                  Serial.print(t);
                  Serial.println(" *C");
              }
              WiFiClient client = server.available();   // listen for incoming clients

              if (client) {                             // if you get a client,
              Serial.println("new client");           // print a message out the serial port
              String currentLine = "";                // make a String to hold incoming data from the client
              while (client.connected()) {            // loop while the client's connected
              if (client.available()) {             // if there's bytes to read from the client,
              char c = client.read();             // read a byte, then
              Serial.write(c);                    // print it out the serial monitor
              if (c == '\n') {                    // if the byte is a newline character
              if (currentLine.length() == 0) {
                     client.println("HTTP/1.1 200 OK");// HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
                     client.println("Content-type:text/html"); // and a content-type so the client knows what's coming, then a blank line:
                     client.println("Refresh:5");
                     client.println();
                     client.println("<html>");
                     client.println("<head>\n");
                     client.println("<meta charset='UTF-8'/>\n");
                     client.println("<title>Humidity_Temperature</title>\n");
                     client.println("<style>");
                     client.println("html{background-color:#A9F0F2;}");
                     client.println(".title{text-align:center;color:#5f0054;}");
                     client.println("a{display:block;text-decoration:none;background-color:lightgray;");
                     client.println("width:150px;text-align:center;margin:0 auto;margin-bottom:30px;font-size:2em;}");
                     client.println(".dis{background-color:#17A1A5;color:#004B4E;text-align:center;margin:0 auto;;font-size:2em;width:400px;}");
                     client.println("</style>");
                     client.println("</head>\n");
                     client.println("<body>");
                     client.println("<h1 class=\"title\">Humidity_Temperature</h1>");
                     client.println("<p class=\"dis\">Hum:");
                     client.println(h);
                     client.println("</p>");
                     client.println("<p class=\"dis\">Tem:");
                     client.println(t);
                     client.println("</p>");
                     client.println("</body></html>");
                     client.println();
                    // break out of the while loop:
                    break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
        if (currentLine.startsWith("GET /H")) {
          digitalWrite(LED_BUILTIN, HIGH);               // GET /H turns the LED on
        }
        if (currentLine.startsWith("GET /L")) {
          digitalWrite(LED_BUILTIN, LOW);                // GET /L turns the LED off
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("client disonnected");
  }
}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  // print where to go in a browser:
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}


