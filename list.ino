void list(File dir, int numTabs) {
  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      vga.print('\t');
    }
    vga.print(entry.name());
    if (entry.isDirectory()) {
      vga.println("/");
      list(entry, numTabs + 1);
    } else {
      // files have sizes, directories do not
      vga.print("\t\t");
      vga.println(entry.size(), DEC);
    }
    entry.close();
  }
}
