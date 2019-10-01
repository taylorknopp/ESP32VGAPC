
#include <SD.h>
#include <SPI.h>
#include <ESP32Lib.h>
#include <Ressources/Font6x8.h>
#include <Ressources/CodePage437_8x8.h>

//pin configuration
const int redPin = 14;
const int greenPin = 19;
const int bluePin = 27;
const int hsyncPin = 32;
const int vsyncPin = 33;
const int numCommands = 4;
int screenPos = 8;
String commands[numCommands] ={"clear","edit","draw","list"};
File root;


//VGA Device
VGA3BitI vga;
char incomingByte = ' ';
String command = "";
void setup()
{
  Serial.begin(115200);
	//initializing vga at the specified pins
  Mode myMode = vga.MODE1024x768.custom(600, 320);
	vga.init(myMode, redPin, greenPin, bluePin, hsyncPin, vsyncPin);
	//selecting the font
	vga.setFont(CodePage437_8x8);
	//displaying the text
  vga.print("free memory: ");
  vga.print((int)heap_caps_get_free_size(MALLOC_CAP_DEFAULT));
  vga.println();
  root = SD.open("/");
}

void loop()
{
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    drawScreen(incomingByte);
    //vga.print("I received: ");
    
   
  }
  
}


void drawScreen(char c)
{
    if(c == '\r' )
    {
      







      int ind = IndexOfSringInArray(commands,command);
      Serial.println(ind);
      switch (ind) {
        case 0:
          
        
          cls();
          break;
          
        case 1:
        
          edit("test.txt");
          break;

        case 2:
        
          draw(command);
          break;
        case 3:
        
          list(root,0);
          break;
          
        default:
          
          // statements
          break;
  }
  command = "";
  screenPos+= 8;
  vga.setCursor(0, screenPos);
  command = "";
  if(screenPos >= 592)
  {
    cls();
  }






    

    
    
  }
  else
  {
    vga.print(c);
    command += c;
  }
}

int IndexOfSringInArray(String ary[], String val)
{
  
  int wantedPos = -1;
  for (int i=0; i<numCommands; i++) {
    Serial.println(val.indexOf(ary[i]));
    if (val.indexOf(ary[i]) >= 0) {
      wantedPos = i;
      break;
    }
  }
  return wantedPos;
}


void cls()
{
  vga.clear();
  vga.setCursor(0, 0);
  screenPos = 8;
  vga.print("free memory: ");
  vga.println((int)heap_caps_get_free_size(MALLOC_CAP_DEFAULT));
}
