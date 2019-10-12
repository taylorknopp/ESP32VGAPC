void asc(String cmd)
{
  char val = getValue(cmd,',',1)[0];
  vga.println(val);
}
