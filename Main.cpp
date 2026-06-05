#include "FileWatcher.h"
#include "Serializer.h"
#include "BinaryReader.h"
#include <iostream>

int main() {

	while (true) {
		
		if (ChangeDetected() == true) {
			BinaryConvert();
			ReadBinary();
		}

	}


}
