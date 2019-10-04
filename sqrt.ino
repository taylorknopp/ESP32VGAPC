void sqrtNum(String cmd)
{
  float x = getValue(cmd,',',1).toInt();
  float out = sqrt(x);
  vga.println(out);
}
