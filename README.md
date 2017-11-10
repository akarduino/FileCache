# FileCache

[![Build Status](https://travis-ci.org/akarduino/FileCache.svg?branch=master)](https://travis-ci.org/akarduino/FileCache)

Библиотека Arduino для хранения и получения ключ-значение данных на файловой системе.

Поддерживает только значения типа int(integer).

# Платформа

Пока поддерживается только Wemos

# Использование
```c++
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
```
# Todo
- Задавать хранение не путем файла, а только его именем
- Добавить поддержку хранения строк
