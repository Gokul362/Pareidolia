#include <iostream>
#include <fstream>
#include <string>
#include "FileWatcher.h"
#include "Serializer.h"


void BinaryConvert() {

	std::cout << "\n\n--GENERATING--\n\n";
	std::fstream data("test.yaml", std::ios::in | std::ios::out);

	std::ofstream outFile("Head.pxtan", std::ios::out | std::ios::binary | std::ios::trunc);
	char header[4] = { 'C', 'o', 's', '0' };
	outFile.write(header, sizeof(header));

	auto Pair = root.begin();
	auto Key = Pair->first.as<std::string>();
	auto Value = Pair->second.as<std::string>();
	auto KeyLength = Key.size();
	auto ValueLength = Value.size();

	uint32_t KeySize = static_cast<uint32_t>(KeyLength);

	outFile.write(reinterpret_cast<char*>(&KeyLength), sizeof(KeySize));
	outFile.write(Key.c_str(), KeyLength);
	outFile.close();
	std::cout << "\n\n--FILE WRITTEN--\n\n" << root;
}