void tanNum(String cmd)
{
  float x = getValue(cmd,',',1).toInt();
  float out = tan(x);
  vga.println(out);
}
