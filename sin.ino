void sinNum(String cmd)
{
  float x = (float)getValue(cmd,',',1).toInt();
  float out = (sin(x*0.0174533))/0.0174533;
  Serial.println(out);
  vga.println(out);
  
}
