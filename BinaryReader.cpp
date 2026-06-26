#include <fstream>
#include "Serializer.h"
#include "BinaryReader.h"
#include "Main.h"
#include <print>
#include <ranges>
#include <format>



void HeaderCheck(std::ifstream& file) {

	uint8_t TargetHeaderBytes[4] = { 0x43, 0x6F, 0x73, 0x30 };
	auto TargetHeader = 0;
	std::memcpy(&TargetHeader, TargetHeaderBytes, 4);

	char CurrentBytes[4];
	file.read(CurrentBytes, 4);
	auto CurrentHeader = 0;
	std::memcpy(&CurrentHeader, CurrentBytes, 4);

	if (CurrentHeader != TargetHeader) {
		std::cout << "\n\n\n--UNAUTHORIZED FILE DETECTED--";
		return;
	}
	else {
		std::cout << "\n\n\n--FILE ACCEPTED, STARTING READING PROCESS--";
	}

}


int TotalPairsCalculation(std::ifstream& file) {

	// Total Pairs, used for the -for loop-
	char TotalPairs[4];
	file.read(TotalPairs, sizeof(TotalPairs));
	auto TotalPairLoop = 0;
	std::memcpy(&TotalPairLoop, TotalPairs, 4);

	return TotalPairLoop;

}


std::string ReadKey(std::ifstream& file) {

	// Reads the length into array "KeyLength", and puts the data from "KeyLength" into a variable
	char KeyLength[4];
	file.read(KeyLength, sizeof(KeyLength));
	auto VarKeyLength = 0;
	std::memcpy(&VarKeyLength, KeyLength, 4);

	// Makes a vector with the length variable, and reads that many bytes into it
	std::vector<char> RawKey(VarKeyLength);
	file.read(RawKey.data(), RawKey.size());
	std::string Key(RawKey.begin(), RawKey.end());

	return Key;

}


DataTypes ReadDataType(std::ifstream& file) {

	char ValueDataType[1];
	file.read(ValueDataType, sizeof(ValueDataType));
	auto RawDataType = 0; // Raw just means it is directly from the binary, not converted into the enum
	std::memcpy(&RawDataType, ValueDataType, 1);
	DataTypes VarDataType = static_cast<DataTypes>(RawDataType);

	return VarDataType;

}

// --Data Type Value reading--

Pairs ReadIntValue(std::ifstream& file, auto key) {

	std::cout << "\n\nThe Value is an Integer  ";
	char CharValue[4];
	file.read(CharValue, 4);

	int Value;
	std::memcpy(&Value, CharValue, 4);
	Pairs StructInstance = { key, Value };
	std::println("{}: {}", key, Value);

	return StructInstance;

}


Pairs ReadFloatValue(std::ifstream& file, auto key) {

	std::cout << "\n\nThe Value is an Float  ";
	char CharValue[4];
	file.read(CharValue, 4);

	float Value;
	std::memcpy(&Value, CharValue, 4);
	Pairs StructInstance = { key, Value };
	std::println("{}: {}", key, Value);

	return StructInstance;

}


Pairs ReadBoolValue(std::ifstream& file, auto key) {

	std::cout << "\n\nThe Value is an Boolean  ";
	char CharValue[1];
	file.read(CharValue, 1);

	bool Value;
	std::memcpy(&Value, CharValue, 1);
	Pairs StructInstance = { key, Value };
	std::println("{}: {}", key, Value);

	return StructInstance;

}


Pairs ReadStringValue(std::ifstream& file, auto key) {

	std::cout << "\n\nThe Value is a String  ";
	char ValueLength[4];
	file.read(ValueLength, sizeof(ValueLength));
	auto VarValueLength = 0;
	std::memcpy(&VarValueLength, ValueLength, 4);

	std::vector<char> RawValue(VarValueLength);
	file.read(RawValue.data(), VarValueLength);

	std::string Value(RawValue.begin(), RawValue.end());
	Pairs StructInstance = { key, Value };
	std::println("{}: {}", key, Value);

	return StructInstance;

}


Pairs FilterAndReadValues(DataTypes VarDataType, std::ifstream& file, std::string Key) {

	Pairs TempPair;

	if (VarDataType == DataTypes::Int) {
		TempPair = ReadIntValue(file, Key);
	}

	else if (VarDataType == DataTypes::Float) {
		TempPair = ReadFloatValue(file, Key);
	}

	else if (VarDataType == DataTypes::Bool) {
		TempPair = ReadBoolValue(file, Key);
	}

	else if (VarDataType == DataTypes::String) {
		TempPair = ReadStringValue(file, Key);
	}

	else if (VarDataType == DataTypes::Nested) {

		char NestedLength[4];
		file.read(NestedLength, 4);

		int VarNestedLength = 0;
		std::memcpy(&VarNestedLength, NestedLength, 4);

		for (int n = 0; n < VarNestedLength; n++) {

			std::string Key = ReadKey(file);
			DataTypes VarDataType = ReadDataType(file);
			Pairs ChildPair = FilterAndReadValues(VarDataType, file, Key);
			PairsList.push_back(ChildPair); // PairsList holds all the Pairs, is defined in BinaryReader.h

		}

	}

	return TempPair;

}


void ReadBinary() {

	std::ifstream pxtan("Head.bin", std::ios::binary);
	HeaderCheck(pxtan);

	auto TotalPairLoop = TotalPairsCalculation(pxtan);

	for (int i = 0; i < TotalPairLoop; i++) {

		std::string Key = ReadKey(pxtan);
		DataTypes VarDataType = ReadDataType(pxtan);


		Pairs TempPair = FilterAndReadValues(VarDataType, pxtan, Key);
		if (VarDataType != DataTypes::Nested) {
			PairsList.push_back(TempPair); // PairsList holds all the Pairs, is defined in BinaryReader.h
		}
		


	}


}

