  //include library
  #include <Wire.h>
  #include <SPI.h>
  #include <Adafruit_GFX.h>
  #include <Adafruit_SSD1306.h>

  //Define Variables
  #define OLED_MOSI   11 //D1
  #define OLED_CLK   12 //D0
  #define OLED_DC    9 //DC
  #define OLED_CS    8 //CS
  #define OLED_RESET 10 //RES
  #define fsr_pin A0
  Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

  static const unsigned char PROGMEM JCC[]={
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000111, B10000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00011111, B11000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00111111, B11000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B01111000, B01000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B01110000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B01110000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B11110000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B11100000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B11100000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B11110000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B11110000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B01110000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B01110000, B00000000, B00000000, B00000000, B00000000, B00011000, B00000000, 
  B00000000, B01111000, B00000000, B00000000, B00000000, B00000000, B00111000, B00000000, 
  B00000000, B00111000, B00000000, B00000000, B00000000, B00000000, B01111000, B00000000, 
  B00000000, B00111100, B00000000, B00000000, B00000000, B00000001, B11111100, B00000000, 
  B00000000, B00011111, B00000111, B11000000, B00000000, B00000011, B11111110, B00000000, 
  B00000000, B00001111, B11111111, B11111111, B10000000, B00000111, B11111111, B00000000, 
  B00000000, B00001111, B11111111, B11111111, B11111111, B00011111, B11111111, B10000000, 
  B00000000, B00000111, B11111111, B11111111, B11111111, B11111111, B11111111, B10000000, 
  B00000000, B00000111, B11111111, B11111111, B11111111, B11111111, B11111111, B10000000, 
  B00000000, B00000111, B11111111, B11111111, B11111111, B11111111, B11111111, B00000000, 
  B00000000, B00000111, B11111111, B11111111, B11111111, B11111111, B11110000, B00000000, 
  B00000000, B00001111, B11111111, B11111111, B11111111, B11111111, B11100000, B00000000, 
  B00000000, B00001111, B11111111, B11111111, B11111111, B11111111, B11100000, B00000000, 
  B00000000, B00001111, B11111111, B11111111, B11111111, B11111111, B11000000, B00000000, 
  B00000000, B00001111, B11111111, B11111111, B11111111, B11111111, B11000000, B00000000, 
  B00000000, B00001111, B11111111, B11111111, B11111111, B11111111, B11000000, B00000000, 
  B00000000, B00011111, B11111111, B11111111, B11111111, B11111111, B11000000, B00000000, 
  B00000000, B00111111, B11111111, B11111111, B11111111, B11111111, B11000000, B00000000, 
  B00000000, B01111111, B11111111, B11111111, B11111111, B11111111, B11000000, B00000000, 
  B00000000, B11111111, B11111111, B11111101, B11111111, B11111111, B11000000, B00000000, 
  B00000000, B11111111, B11111110, B00000000, B00111111, B11111111, B11000000, B00000000, 
  B00000001, B11111100, B11111110, B00000000, B00111110, B00001111, B11000000, B00000000, 
  B00000001, B11100000, B11111100, B00000000, B00111100, B00000111, B11100000, B00000000, 
  B00000011, B10000000, B11111000, B00000000, B00111100, B00000011, B11110000, B00000000, 
  B00000011, B10000000, B11111000, B00000000, B00111000, B00000001, B11110000, B00000000, 
  B00000011, B00000000, B11110000, B00000000, B00111000, B00000000, B11111000, B00000000, 
  B00000011, B00000000, B11100000, B00000000, B01110000, B00000000, B00111100, B00000000, 
  B00000111, B00000000, B01110000, B00000000, B01100000, B00000000, B00011110, B00000000, 
  B00000111, B00000000, B01110000, B00000000, B01100000, B00000000, B00001111, B00000000, 
  B00000010, B00000000, B00111000, B00000000, B01110000, B00000000, B00000111, B11100000, 
  B00000000, B00000000, B00011111, B00000000, B01110000, B00000000, B00000001, B11100000, 
  B00000000, B00000000, B00001111, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  };

  static const unsigned char PROGMEM KRY[]={
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B11100000, B00000111, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000001, B11100000, B00000111, B10000000, B00000000, B00000000, 
  B00000000, B00000000, B00000001, B11000000, B00000011, B10000000, B00000000, B00000000, 
  B00000000, B00000000, B00000011, B11100000, B00000111, B11000000, B00000000, B00000000, 
  B00000000, B00000000, B00000011, B11111000, B00011111, B11000000, B00000000, B00000000, 
  B00000000, B00000000, B00000110, B00001100, B00110000, B01100000, B00000000, B00000000, 
  B00000000, B00000000, B00000100, B00000100, B00100000, B00100000, B00000000, B00000000, 
  B00000000, B00000000, B00001100, B00000110, B01100000, B00110000, B00000000, B00000000, 
  B00000000, B00001100, B00001100, B00000110, B01100000, B00110000, B00110000, B00000000, 
  B00000000, B00011000, B00001100, B00000110, B01100000, B00110000, B00011000, B00000000, 
  B00000000, B00111100, B00000100, B00000100, B00100000, B00100000, B00111100, B00000000, 
  B00000000, B00111111, B10000110, B00001100, B00110000, B01100001, B11111100, B00000000, 
  B00000000, B00111111, B11100011, B11111000, B00011111, B11000111, B11111100, B00000000, 
  B00000000, B00111000, B00110000, B11100000, B00000111, B00001100, B00011100, B00000000, 
  B00000000, B00110000, B00010000, B00000011, B11000000, B00001000, B00001100, B00000000, 
  B00000000, B00110000, B00010000, B00011111, B11111000, B00001000, B00001100, B00000000, 
  B00000000, B00100000, B00011000, B01110000, B00001110, B00011000, B00000100, B00000000, 
  B00000000, B00110000, B00010000, B11000000, B00000011, B00001000, B00001100, B00000000, 
  B00000000, B00010000, B00110011, B10000000, B00000001, B11001100, B00001000, B00000000, 
  B00000000, B00011000, B00110010, B00000000, B00000000, B01001100, B00011000, B00000000, 
  B00000000, B00001111, B11100110, B00000000, B00000000, B01100111, B11110000, B00000000, 
  B00000000, B00000011, B10001100, B00000000, B00000000, B00110001, B11000000, B00000000, 
  B00000000, B00000000, B00001000, B00000000, B00000000, B00010000, B00000000, B00000000, 
  B00000000, B00000000, B00011000, B00000000, B00000000, B00011000, B00000000, B00000000, 
  B00000000, B00000000, B00011000, B00000000, B00000000, B00011000, B00000000, B00000000, 
  B00000000, B00000000, B00010000, B00000000, B00000000, B00001000, B00000000, B00000000, 
  B00000000, B00000000, B00110000, B00000000, B00000000, B00001000, B00000000, B00000000, 
  B00000000, B00000000, B00110000, B00000000, B00000000, B00001100, B00000000, B00000000, 
  B00000000, B00000000, B00110000, B00000000, B00000000, B00001100, B00000000, B00000000, 
  B00000000, B00000000, B00110000, B00000000, B00000000, B00001100, B00000000, B00000000, 
  B00000000, B00000000, B00110000, B00000000, B00000000, B00001100, B00000000, B00000000, 
  B00000000, B00000000, B00110000, B00000000, B00000000, B00001100, B00000000, B00000000, 
  B00000000, B00000000, B00110000, B00000000, B00000000, B00001100, B00000000, B00000000, 
  B00000000, B00000000, B00010000, B00000000, B00000000, B00001000, B00000000, B00000000, 
  B00000000, B00000000, B00011000, B00000111, B11100000, B00011000, B00000000, B00000000, 
  B00000000, B00000000, B00001100, B00011100, B00111000, B00110000, B00000000, B00000000, 
  B00000000, B00000000, B00000110, B01111000, B00011110, B01100000, B00000000, B00000000, 
  B00000000, B00000000, B00000011, B11100000, B00000111, B11000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
      
  };


  const int ledCount = 10;    // the number of LEDs in the bar graph
  int ledPins[] = {1, 2, 3, 4, 5, 6, 7, 13};  


  void setup() {
    Serial.begin(9600);
    for(int thisled=0;thisled<ledCount;thisled++){
      pinMode(ledPins[thisled],OUTPUT);
    }
    display.begin(SSD1306_SWITCHCAPVCC,0x3D);
    display.clearDisplay();
    display.drawBitmap(23,0,JCC,64,64,WHITE);
    display.display();  
  }

  void loop() {
    int fsr_value=analogRead(fsr_pin);
    int led_value=map(fsr_value,0,256,0,8);
    for(int thisled=0;thisled<ledCount;thisled++){
      if(thisled<led_value){
         digitalWrite(ledPins[thisled],HIGH);
         display.clearDisplay();
         display.drawBitmap(23,0,JCC,64,64,WHITE);
         display.display();  
       }
       else{
         digitalWrite(ledPins[thisled],LOW);
         display.clearDisplay();
         display.drawBitmap(23,0,KRY,64,64,WHITE);
         display.display();  
       }
     }
  }
