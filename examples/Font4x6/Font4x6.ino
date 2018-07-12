#include <Arduboy2.h>
#include "Font4x6.h"

Arduboy2Base arduboy;
Font4x6 font = Font4x6();

void setup() {

  arduboy.boot();

}

void loop() {

  if (!(arduboy.nextFrame())) return;

  arduboy.clear();
  font.setCursor(0, 12);
  font.println(F("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
  font.println(F("abcdefghijklmnopqrstuvwxyz"));
  font.println(F("0123456789"));
  font.println(F("!."));

  arduboy.display();

}
