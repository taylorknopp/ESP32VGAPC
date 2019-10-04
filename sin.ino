void sinNum(String cmd)
{
  float x = (float)getValue(cmd,',',1).toInt();
  float out = sin(x);
  vga.println(out)
  
}
