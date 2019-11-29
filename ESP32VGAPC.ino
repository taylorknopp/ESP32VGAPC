#include <pitches.h>
#include <Tone32.h>


#include <pitches.h>





//#include <PS2Kbd.h>
#include <ESP32Lib.h>
#include <SD.h>
#include <SPI.h>
#include <Ressources/Font6x8.h>
#include <Ressources/CodePage437_8x8.h>
#include <math.h>

#define KEYBOARD_DATA 35
#define KEYBOARD_CLK  34

//pin configuration

const int redPins[] = {2, 4, 12, 13, 14};
const int greenPins[] = {15, 16, 17, 5, 18};
const int bluePins[] = {21, 22, 23, 27};
const int hsyncPin = 32;
const int vsyncPin = 33;
const int buzzerPin = 19;

// int redPin = 14;
// int greenPin = 19;
// int bluePin = 27;
// int hsyncPin = 32;
// int vsyncPin = 33;
const int numCommands = 11;
int screenPos = 8;
String commands[numCommands] ={"clear","edit","draw","list","abs","asc","cos","sin","tan","sqrt","splash"};
File root;


//PS2Kbd keyboard(KEYBOARD_DATA, KEYBOARD_CLK);
void drawScreen(char c);
int IndexOfSringInArray(String ary[], String val);
void cls();
void edit(char fileNameOrPath  []);
void draw(String cmd);
void list(File dir, int numTabs);
void absNum(String cmd);
void asc(String cmd);
void cosNum(String cmd);
void sinNum(String cmd);
void tanNum(String cmd);
void sqrtNum(String cmd);
String getValue(String data, char separator, int index);
void printMem();
void drawBlancChar(int posX, int posY, int numCharToPrint);
void splash();


//VGA Device

//VGA3BitI vga;
VGA14BitI vga;
char incomingByte = ' ';
String command = "";
void setup()
{
  Serial.begin(115200);
	//initializing vga at the specified pins
  Mode myMode = vga.MODE400x300;
  vga.init(myMode, redPins, greenPins, bluePins, hsyncPin, vsyncPin);
	//vga.init(myMode, redPin, greenPin, bluePin, hsyncPin, vsyncPin);
	//selecting the font
	vga.setFont(CodePage437_8x8);
	//displaying the text
  vga.print("free memory: ");
  vga.print(ESP.getFreeHeap());
   vga.print(" Bytes");
  vga.println();
  root = SD.open("/");
  
  //keyboard.begin();
  pinMode(buzzerPin,OUTPUT);
  splash();
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
  /*if (keyboard.available()) {
    // read the incoming byte:
    incomingByte = keyboard.read();

    // say what you got:
    drawScreen(incomingByte);
    //vga.print("I received: ");


  }*/

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

        case 4:

          absNum(command);
          break;

        case 5:

          asc(command);
          break;

        case 6:

          cosNum(command);
          screenPos += 8;
          break;

        case 7:

          sinNum(command);
          screenPos += 8;
          break;

        case 8:

          tanNum(command);
          screenPos += 8;
          break;

        case 9:

          sqrtNum(command);
          break;
        case 10:

          splash();
          break;


        default:

          // statements
          break;
          printMem();
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
    if(c == 127 || c == 8)
    {
      if(command.length() > 0)
      {
        Serial.println("BackSpcae");

        command.remove(command.length() - 1);
        int xpos = (command.length()*8);
        drawBlancChar(xpos,screenPos, 1);
        vga.setCursor(xpos, screenPos);

      }

    }
    else
    {
      vga.print(c);
      command += c;
    }

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


void printMem()
{
  drawBlancChar(0,0, 360);
  vga.setCursor(0, 0);
   vga.print("free memory: ");
  vga.print(ESP.getFreeHeap());
   vga.print(" Bytes");
  vga.setCursor(command.length()*8,screenPos);
}

void cls()
{
  vga.clear();
  vga.setCursor(0, 0);
  screenPos = 8;
 printMem();
}
