void sc(string cmd)
{
  char value[] = getValue(cmd,',',1);
  vga.println(value[0]);
}
