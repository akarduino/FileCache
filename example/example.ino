#include <FileCache.h>

int myVal = 0;

FileCache dump = FileCache("./cache.txt");

void setup() {
  Serial.begin(115200);

  myVal = dump.get();
}

void loop() {
  delay(1000);

  Serial.print("My value: ");
  Serial.println(myVal);

  myVal++;
  dump.put(myVal);
}
