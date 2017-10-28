#include "Arduino.h"
#include "FS.h"
#include "FileCache.h"

String _fileName;

FileCache::FileCache(String fileName)
{
	SPIFFS.begin();

	_fileName = fileName;
	if (!SPIFFS.exists(_fileName)) {
		Serial.print("Create file ");
	    Serial.println(_fileName);
	    
	    File file = SPIFFS.open(_fileName, "w");
	    file.println(0);
	}
}

bool FileCache::put(int value)
{
	File file = SPIFFS.open(_fileName, "w");
	if (!file) {
		Serial.println("Unable to put into file");
		file.close();
		return false;
	}
	
	file.println(value);
	file.close();

	return true;
}

int FileCache::get()
{
	File file = SPIFFS.open(_fileName, "r");
	if (!file) {
		Serial.println("Unable to get from file");
		file.close();
		return 0;
	}

	String myVal = file.readStringUntil('\n');
	file.close();

	return myVal.toInt();  
}
