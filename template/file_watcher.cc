#include "dyslevium.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> files{"./main.cc", "./input.in"};
  std::chrono::duration<int, std::milli> delay =
      std::chrono::milliseconds(500);

  File_Watcher main_file(files, delay);
  auto commands = [] {
    system("clear");
    system("make run");
  };

  main_file.watch(commands);
}
