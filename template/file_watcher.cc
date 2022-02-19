#include "dyslevium.h"

int main(int argc, char* argv[]) {
  File_Watcher fw{"./main.cc", std::chrono::milliseconds(500)};

  fw.watch([] {
    system("clear");
    system("make run");
  });
}