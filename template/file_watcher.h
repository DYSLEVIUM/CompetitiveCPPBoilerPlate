#pragma once

#include "dyslevium.h"

class File_Watcher {
 public:
  std::string _file_to_watch;

  //  Time interval at which we check the base folder for changes
  std::chrono::duration<int, std::milli> _delay;

  File_Watcher(std::string file_to_watch,
               std::chrono::duration<int, std::milli> delay)
      : _delay(delay) {
    if (!file_exists(file_to_watch)) {
      std::cout << "File does not exist." << std::endl;
      return;
    }

    _file_to_watch = file_to_watch;
    file_last_write_time_prev_ =
        std::filesystem::last_write_time(_file_to_watch);
  }

  void watch(const std::function<void()>& on_edit) {
    while (running_) {
      std::this_thread::sleep_for(_delay);

      //  erased
      if (!file_exists(_file_to_watch)) {
        std::cout << "File not found." << std::endl;
        running_ = false;
        break;
      }

      //  modified
      auto file_last_write_time =
          std::filesystem::last_write_time(_file_to_watch);
      if (file_last_write_time != file_last_write_time_prev_) {
        file_last_write_time_prev_ = file_last_write_time;
        on_edit();
      }
    }
  }

 private:
  bool running_ = true;
  std::filesystem::file_time_type file_last_write_time_prev_;

  bool file_exists(std::string file_path) {
    return std::filesystem::exists(file_path);
  }
};