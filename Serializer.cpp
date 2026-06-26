#include <iostream>
#include <string>
#include <typeinfo>
#include "FileWatcher.h"
#include "Serializer.h"



void InitialSetup(std::ofstream& file) {
	char header[4] = { 'C', 'o', 's', '0' };
	file.write(header, sizeof(header));

	uint32_t TotalNodes = static_cast<uint32_t>(root.size());
	file.write(reinterpret_cast<char*>(&TotalNodes), sizeof(TotalNodes)); // Total number of nodes
}


void WriteKey(std::ofstream& file, auto Pair) {

	auto Key = Pair->first.as<std::string>();
	auto KeyLength = Key.size();

	file.write(reinterpret_cast<char*>(&KeyLength), 4);
	file.write(Key.c_str(), KeyLength);

}


void WriteValue(std::ofstream& file, auto Pair) {
	
	auto Value = Pair->second;
	auto ValueLength = Value.size();

	switch (Value.Type()) {

		case YAML::NodeType::Scalar: {

			std::string StrValue = Value.as<std::string>();

			if (StrValue == "true" || StrValue == "false") {
				DataTypes DataType = DataTypes::Bool;
				file.write(reinterpret_cast<char*>(&DataType), 1);

				bool WriteValue = Value.as<bool>();
				file.write(reinterpret_cast<char*>(&WriteValue), 1);
			}

			else if (StrValue.find_first_not_of("-.0123456789") == std::string::npos) {

				if (StrValue.contains(".")) {
					DataTypes DataType = DataTypes::Float;
					file.write(reinterpret_cast<char*>(&DataType), 1);

					float WriteValue = Value.as<float>();
					file.write(reinterpret_cast<char*>(&WriteValue), 4);
				}

				else {
					DataTypes DataType = DataTypes::Int;
					file.write(reinterpret_cast<char*>(&DataType), 1);

					int WriteValue = Value.as<int>();
					file.write(reinterpret_cast<char*>(&WriteValue), 4);
				}

			}

			else {
				DataTypes DataType = DataTypes::String;
				file.write(reinterpret_cast<char*>(&DataType), 1);

				auto StrValueLength = StrValue.size();
				file.write(reinterpret_cast<char*>(&StrValueLength), 4);

				file.write(StrValue.c_str(), StrValueLength);
			}

			break;

		}
		

		case YAML::NodeType::Map: {

			auto ValueNested = Value.begin();
			auto TotalNested = Value.size();
			DataTypes DataType = DataTypes::Nested;
			file.write(reinterpret_cast<char*>(&DataType), 1);
			file.write(reinterpret_cast<char*>(&TotalNested), 4);

			for (int n = 0; n < Value.size(); n++) {

				WriteKey(file, ValueNested);
				WriteValue(file, ValueNested);
				++ValueNested;

			}

			break;

		}

	}

}


void BinaryConvert() {

	// Intial Setup
	std::cout << "\n\n--GENERATING--\n\n";
	std::fstream data("test.yaml", std::ios::in | std::ios::out);
	std::ofstream outFile("Head.bin", std::ios::out | std::ios::binary | std::ios::trunc);
	InitialSetup(outFile);


	auto Pair = root.begin();

	for (int i = 0; i < root.size(); i++) {


		WriteKey(outFile, Pair);
		WriteValue(outFile, Pair);

		// To go to the next YAML pair
		++Pair;

	}

	outFile.close();
	std::cout << "\n\n--FILE WRITTEN--\n\n" << root;
}