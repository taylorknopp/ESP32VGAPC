void sinNum(String cmd)
{
  float x = (float)getValue(cmd,',',1).toInt();
  float out = (sin(x*0.0174533));

  char result[8]; // Buffer big enough for 7-character float
  dtostrf(out, 6, 2, result); // Leave room for too large numbers!
  
  Serial.println(out);
  vga.println("");
  vga.println(result);
  
  
}
