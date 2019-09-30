void draw(String cmd)
{
  int x = getValue(cmd,',',1).toInt();
  int y = getValue(cmd,',',2).toInt();
  int x2 = getValue(cmd,',',3).toInt();
  int y2 getValue(cmd,',',4).toInt();
  int r = getValue(cmd,',',5).toInt();
  int g = getValue(cmd,',',6).toInt();
  int b = getValue(cmd,',',7).toInt();
  int SiseX = getValue(cmd,',',8).toInt();
  int SiseY = getValue(cmd,',',9).toInt();
  String shape = getValue(cmd,',',10);
  int fillShape = getValue(cmd,',',11).toInt();
  
  Serial.print("x: " );
  Serial.print(x);
  Serial.print(" y: ");
  Serial.print(y);
  Serial.print(" R: ");
  Serial.print(r);
  Serial.print(" G: ");
  Serial.print(  g);
  Serial.print(" B: ");
  Serial.print(b);
  Serial.print(" ");
  Serial.print(shape);
  
  
  shape.toLowerCase();
  if(shape == "rectangle")
  {
    if(fillShape == 0)
    {
      Serial.print(" Fill: False");
      vga.rect(x, y , SiseX, SiseY, vga.RGB(r, g, b));
    }
    else
    {
      Serial.print(" Fill: True");
      vga.fillRect(x, y , SiseX, SiseY, vga.RGB(r, g, b));
    }
    
  }
  if(shape == "circle")
  {
    
    if(fillShape == 0)
    {
      Serial.print(" Fill: False");
      vga.circle(x, y , SiseX/SiseY, vga.RGB(r, g, b));
    }
    else
    {
      Serial.print(" Fill: True");
      vga.fillCircle(x, y , SiseX/SiseY, vga.RGB(r, g, b));
    }
  }
  if(shape == "tringale")
  {
    if(fillshape == 0)
    {
      vga.line(x,y,x2,y2,vga.RGB(r, g, b))
      vga.line(x,y,SiseX,SiseY,vga.RGB(r, g, b))
      vga.line(SiseX,SiseY,x2,y2,vga.RGB(r, g, b))
    }
    else
    {
      
    }
  }
}


String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
