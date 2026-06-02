#pragma once
#include "yaml-cpp/yaml.h"

void BinaryConvert();

inline YAML::Node root = YAML::LoadFile("test.yaml");