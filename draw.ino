void draw(String cmd)
{
  int x = getValue(cmd,',',1).toInt();
  int y = getValue(cmd,',',2).toInt();
  int x2 = getValue(cmd,',',3).toInt();
  int y2 = getValue(cmd,',',4).toInt();
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
  Serial.print(" x2: " );
  Serial.print(x2);
  Serial.print(" y2: ");
  Serial.print(y2);
  Serial.print(" R: ");
  Serial.print(r);
  Serial.print(" G: ");
  Serial.print(  g);
  Serial.print(" B: ");
  Serial.print(b);
  Serial.print(" ");
  Serial.println(shape);
  
  
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
  if(shape == "triangle")
  {
    if(fillShape == 0)
    {
      vga.line(x,y,x2,y2,vga.RGB(r, g, b));
      vga.line(x,y,SiseX,SiseY,vga.RGB(r, g, b));
      vga.line(SiseX,SiseY,x2,y2,vga.RGB(r, g, b));
    }
    else
    {
      vga.line(x,y,x2,y2,vga.RGB(r, g, b));
      vga.line(x,y,SiseX,SiseY,vga.RGB(r, g, b));
      vga.line(SiseX,SiseY,x2,y2,vga.RGB(r, g, b));
      int SxMax = x;
      
      if(SxMax < x2)
      {
        SxMax = x2; 
      }
      if(SxMax < SiseX)
      {
        SxMax = SiseX; 
      }

      int SxMin = x;
      if(SxMin > x2)
      {
        SxMin = x2; 
      }
      if(SxMin > SiseX)
      {
        SxMin = SiseX; 
      }
      int SyMax = y;
      if(SyMax < y2)
      {
        SyMax = y2; 
      }
      if(SyMax < SiseY)
      {
        SyMax = SiseY; 
      }
      int SyMin = y;
      if(SyMin > y2)
      {
        SyMin = y2; 
      }
      if(SyMin > SiseY)
      {
        SyMin = SiseY; 
      }


      double dx = x2 - x;
      double dy = y2 - y;
      for( int px = x; px <= x2; px++)
      {
        double py = y + dy * (px - x) / dx;
        vga.line(px,py,SiseX,SiseY,vga.RGB(r, g, b));
      }
      

      
      /*double m = (double)(y2 - y)/(double)(x2-x);
      double c = (double)(y2 - y)*m;
      Serial.print(m);
      Serial.print(",");
      Serial.println(c);
      for(int xForLoop = x; xForLoop <= x2; xForLoop++)
      {
        double yForLine = (double)m*xForLoop+c;
        
        Serial.print("Point: ");
        Serial.print(xForLoop);
        Serial.print(",");
        Serial.println(yForLine);
        
              
      }*/
      



/*      
      
      for(int Px = SxMin; Px <= SxMax; Px++)
      {
        
        for(int Py = SyMin; Py <= SyMax; Py++)
        {
          lineY1 = 0;
          lineY2 = 0;
          if(getValueInTriangle(x, y, x2,y2, SiseX, SiseY, Px, Py))
          {
            if(lineY1 == 0)
            {
              lineY1 = Py;
              
            }
            
            Serial.print(Py);
            lineY2 = Py;
            
          }
        }
        //Serial.println(lineY2);
        vga.line(Px,lineY1,Px,lineY2,vga.RGB(r, g, b));
        
      }
      vga.rect(SxMin, SyMin , SxMax - SxMin, SyMax - SyMin, vga.RGB(r, g, b));
*/

      
      //Serial.print("Point 1: ");
      //Serial.print(SxMax);
      //Serial.print(",");
      //Serial.print(SyMax);
      //Serial.print("Point 2: ");
     //Serial.print(SxMin);
     // Serial.print(",");
      //Serial.println(SyMin);




      
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

bool getValueInTriangle(int Ax,int Ay, int Bx,int By, int Cx,int Cy, int Px, int Py)
{
      double s1 = Cy - Ay;
      double s2 = Cx - Ax;
      double s3 = By - Ay;
      double s4 = Py - Ay;

      double w1 = (Ax * s1 + s4 * s2 - Px * s1) / (s3 * s2 - (Bx-Ax) * s1);
      double w2 = (s4- w1 * s3) / s1;
      return w1 >= 0 && w2 >= 0 && (w1 + w2) <= 1;
}
