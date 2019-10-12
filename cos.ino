void cosNum(String cmd)
{
  float x = getValue(cmd,',',1).toInt();
  float out = cos(x);
  vga.println(out);
}
