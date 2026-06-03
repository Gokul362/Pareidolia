#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
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

	// KeySize is how many bytes it takes up on RAM
	uint32_t KeySize = static_cast<uint32_t>(KeyLength);

	outFile.write(reinterpret_cast<char*>(&KeyLength), sizeof(KeySize)); 
	outFile.write(Key.c_str(), KeyLength);


	// Where the data type of the value is found
	if (Value == "true" || Value == "false") {
		DataTypes ValueType = DataTypes::Bool;
		outFile.write(reinterpret_cast<char*>(&ValueType), 1);

		auto ValueForWrite = Pair->second.as<bool>();
		outFile.write(reinterpret_cast<char*>(&ValueForWrite), sizeof(ValueForWrite));
	} 

	else if (Value.find_first_not_of("-+0123456789.") == std::string::npos) {

		if (Value.find(".") != std::string::npos) {
			DataTypes ValueType = DataTypes::Float;
			outFile.write(reinterpret_cast<char*>(&ValueType), 1);

			auto ValueForWrite = Pair->second.as<float>();
			outFile.write(reinterpret_cast<char*>(&ValueForWrite), sizeof(ValueForWrite));
		}

		else {
			DataTypes ValueType = DataTypes::Int;
			outFile.write(reinterpret_cast<char*>(&ValueType), 1);

			auto ValueForWrite = Pair->second.as<int>();
			outFile.write(reinterpret_cast<char*>(&ValueForWrite), sizeof(ValueForWrite));
		}

	}

	else {
		DataTypes ValueType = DataTypes::String;
		outFile.write(reinterpret_cast<char*>(&ValueType), 1);

		auto ValueForWrite = Pair->second.as<std::string>();
		outFile.write(reinterpret_cast<char*>(&ValueForWrite), sizeof(ValueForWrite));
	}



	


	outFile.close();
	std::cout << "\n\n--FILE WRITTEN--\n\n" << root;
}