

#include <LWiFi.h>
#include<DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

char ssid[] = "apple";      //  your network SSID (name)
char pass[] = "star8693";  // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;               // your network key Index number (needed only for WEP)

String apiKey = "JQPH4G9Q7DJO9FLJ";//Channel Write API Key 

const char* server = "api.thingspeak.com";

int status = WL_IDLE_STATUS;

WiFiClient client;

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
}




void setup() {
    //Initialize serial and wait for port to open:
    Serial.begin(9600);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }

    // attempt to connect to Wifi network:
    while (status != WL_CONNECTED) {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid);
        // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
        status = WiFi.begin(ssid, pass);
    }
    Serial.println("Connected to wifi");
    
    printWifiStatus();

}

void loop() {
     float h = dht.readHumidity();
     float t = dht.readTemperature();
 
    // if there are incoming bytes available
    // from the server, read them and print them:
          Serial.println("\nStarting connection to server...");

          if (client.connect(server, 80)) {
            client.print("GET https://api.thingspeak.com/update?api_key=");
            client.print(apiKey+"&field1=");
            client.print(h);
            
            client.print("&field2=");
            client.println(t);
            Serial.print(t);
            Serial.print(h);
            delay(10);
          }

        client.stop();
        delay(5000);

}


