#pragma once
#include "yaml-cpp/yaml.h"
#include <fstream>

void BinaryConvert();

inline YAML::Node root = YAML::LoadFile("test.yaml");

enum class DataTypes {

	Padding,
	Int,
	Float,
	Bool,
	String,
	Nested,
	Terminate

};