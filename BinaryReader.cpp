#include <fstream>
#include "Serializer.h"
#include "BinaryReader.h"
#include <print>
#include <ranges>
#include <format>



void ReadBinary() {

	std::ifstream pxtan("Head.bin", std::ios::binary);

	uint8_t TargetHeaderBytes[4] = {0x43, 0x6F, 0x73, 0x30};
	auto TargetHeader = 0;
	std::memcpy(&TargetHeader, TargetHeaderBytes, 4);

	char CurrentBytes[4];
	pxtan.read(CurrentBytes, 4);
	auto CurrentHeader = 0;
	std::memcpy(&CurrentHeader, CurrentBytes, 4);

	if (CurrentHeader != TargetHeader) {
		std::cout << "\n\n\n--UNAUTHORIZED FILE DETECTED--";
	}
	else {
		std::cout << "\n\n\n--FILE ACCEPTED, STARTING READING PROCESS--";
	}

	// Total Pairs, used for the -for loop-
	char TotalPairs[4];
	pxtan.read(TotalPairs, sizeof(TotalPairs));
	auto TotalPairLoop = 0;
	std::memcpy(&TotalPairLoop, TotalPairs, 4);

	for (int i = 0; i < TotalPairLoop; i++) {

		// Reads the length into array "KeyLength", and puts the data from "KeyLength" into a variable
		char KeyLength[4];
		pxtan.read(KeyLength, sizeof(KeyLength));
		auto VarKeyLength = 0;
		std::memcpy(&VarKeyLength, KeyLength, 4);

		// Makes a vector with the length variable, and reads that many bytes into it
		std::vector<char> RawKey(VarKeyLength);
		pxtan.read(RawKey.data(), RawKey.size());
		std::string Key(RawKey.begin(), RawKey.end());

		char ValueDataType[1];
		pxtan.read(ValueDataType, sizeof(ValueDataType));
		auto RawDataType = 0; // Raw just means it is directly from the binary, not converted into the enum
		std::memcpy(&RawDataType, ValueDataType, 1);
		auto VarDataType = static_cast<DataTypes>(RawDataType);


		// Flags for Data Types
		bool isInt = false;
		bool isFloat = false;
		bool isBool = false;
		bool isString = false;



		if (VarDataType == DataTypes::Int) {
			std::cout << "\n\nThe Value is an Integer  ";
			isInt = true;
		} 
		
		else if (VarDataType == DataTypes::Float) {
			std::cout << "\n\nThe Value is a Float  ";
			isFloat = true;
		}

		else if (VarDataType == DataTypes::Bool) {
			std::cout << "\n\nThe Value is a Boolean  ";
			isBool = true;
		} 

		else {
			std::cout << "\n\nThe Value is a String  ";
			isString = true;
		}


		// NOTE: Replace "Value" with "NewValue" from the "Pair" strcut

		Pairs TempPair; // Struct for the "Key: Value"

		if (isInt == true) {
			char CharValue[4];
			pxtan.read(CharValue, 4);

			int Value;
			std::memcpy(&Value, CharValue, 4);
			TempPair = {Key, Value}; 
			std::println("{}: {}", Key, Value);
		}

		else if (isFloat == true) {
			char CharValue[4];
			pxtan.read(CharValue, 4);
			
			float Value;
			std::memcpy(&Value, CharValue, 4);
			TempPair = { Key, Value };
			std::println("{}: {}", Key, Value);
		}

		else if (isBool == true) {
			char CharValue[1];
			pxtan.read(CharValue, 1);

			bool Value;
			std::memcpy(&Value, CharValue, 1);
			TempPair = {Key, Value};
			std::println("{}: {}", Key, Value);
		}

		else if (isString == true) {

			char ValueLength[4];
			pxtan.read(ValueLength, sizeof(ValueLength));
			auto VarValueLength = 0;
			std::memcpy(&VarValueLength, ValueLength, 4);

			std::vector<char> RawValue(VarValueLength);
			pxtan.read(RawValue.data(), VarValueLength);

			std::string Value(RawValue.begin(), RawValue.end());
			TempPair = {Key, Value};
			std::println("{}: {}", Key, Value);

		}

		PairsList.push_back(TempPair); // PairsList holds all the Pairs, is defined in BinaryReader.h

	}


}

