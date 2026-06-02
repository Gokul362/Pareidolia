#include "FileWatcher.h"
#include "Serializer.h"
#include <iostream>

int main() {

	while (true) {
		
		if (ChangeDetected() == true) {
			BinaryConvert();
		}

	}


}