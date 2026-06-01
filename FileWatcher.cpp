#include "yaml-cpp/yaml.h"
#include <iostream>
#include <filesystem>
#include <chrono>
#include <thread>
#include <fstream>
#include "FileWatcher.h"

using namespace std;


void ChangeDetected() {

    bool fileChanged = false;

    YAML::Node file = YAML::LoadFile("test.yaml");
    filesystem::path test = "test.yaml";

    static auto lastSaved = filesystem::last_write_time(test);

    auto newSaved = filesystem::last_write_time(test);

    if (newSaved != lastSaved) {

        cout << "\n\n--WARNING--\n\n" << file;
        lastSaved = newSaved;

    }

    this_thread::sleep_for(chrono::milliseconds(200));
  


}