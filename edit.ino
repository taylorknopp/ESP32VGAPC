
void edit(char fileNameOrPath[])
{
  vga.clear();
  vga.setCursor(0, 0);
  vga.print("free memory: ");
  vga.print(fileNameOrPath);
}

