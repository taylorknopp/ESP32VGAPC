
void abs(String cmd)
{
  int value = getValue(cmd,',',1).toInt();
  vga.print(abs(value));
}
