#include<Wire.h>
#include<SPI.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

#define OLED_MOSI 11//d1
#define OLED_CLK 12//D0
#define OLED_DC 9//DC
#define OLED_CS 8//CS
#define OLED_RESET 10//RES
#define Light_PIN A0
Adafruit_SSD1306 display(OLED_MOSI,OLED_CLK,OLED_DC,OLED_RESET,OLED_CS);
void splash(){
  int light=analogRead(Light_PIN);
  display.clearDisplay();
  
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0,10);
  display.print("Light: ");
  display.setTextSize(2);
  display.setCursor(70,10);
  display.print(light);
  display.display();
  }
void setup() {
  Serial.begin(9600);
  pinMode(Light_PIN,INPUT);
  // put your setup code here, to run once:
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);
  display.clearDisplay();
  display.setTextWrap(false);

}

void loop() {
  // put your main code here, to run repeatedly:
  splash();

}
