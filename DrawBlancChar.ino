void drawBlancChar(int posX, int posY, int numCharToPrint)
{
 
    Serial.print(posX);
    Serial.print(" ");
    Serial.print(posY);
    Serial.print(" ");
    Serial.println(numCharToPrint);
    vga.fillRect(posX, posY ,numCharToPrint*8 , 8, vga.RGB(0, 0, 0));
    
    
  
  
}
