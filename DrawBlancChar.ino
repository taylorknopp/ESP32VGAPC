void drawBlancChar(int posX, int posY, int numCharToPrint)
{
  if(posX == -1)
  {
    vga.rect(-1,-1  , 8*numCharToPrint, 8, vga.RGB(0, 0, 0));
  }
  else
  {
    vga.rect(posX, posY , 8*numCharToPrint, 8, vga.RGB(0, 0, 0));
  }
  
}
