#ifndef FileCache_h 
#define FileCache_h

#include "Arduino.h"
#include "FS.h"

class FileCache
{
	public:
    	FileCache(String fileName);
    	bool put(int value);
    	int get();
    private:
    	String _fileName;
};

#endif
