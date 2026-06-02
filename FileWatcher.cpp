#include <iostream>
#include <filesystem>
#include <chrono>
#include <thread>
#include <fstream>
#include "Serializer.h"
#include "FileWatcher.h"

using namespace std;


bool ChangeDetected() {


    filesystem::path test = "test.yaml";
    static auto lastSaved = filesystem::last_write_time(test);

    auto newSaved = filesystem::last_write_time(test);

    if (newSaved != lastSaved) {

        root = YAML::LoadFile("test.yaml");
        lastSaved = newSaved;
        return true;

    }

    this_thread::sleep_for(chrono::milliseconds(200));
    return false;
  


}