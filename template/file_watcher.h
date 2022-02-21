#pragma once

#include "dyslevium.h"

class File_Watcher {
 public:
  std::vector<std::string> _files_to_watch;

  //  Time interval at which we check the files for changes
  std::chrono::duration<int, std::milli> _delay;

  File_Watcher(const std::vector<std::string>& files_to_watch,
               const std::chrono::duration<int, std::milli>& delay)
      : _files_to_watch(files_to_watch), _delay(delay) {
    std::vector<std::string> files_not_existing;
    for (const auto& file_path : _files_to_watch) {
      if (!file_exists(file_path)) files_not_existing.push_back(file_path);
    }

    if (!files_not_existing.empty()) {
      for (const auto& file_path : files_not_existing) {
        std::cout << file_path << " file does not exist." << std::endl;
      }
      return;
    }

    for (const auto& file_path : _files_to_watch) {
      files_last_write_time_prev_[file_path] =
          std::filesystem::last_write_time(file_path);
    }
  }

  void watch(const std::function<void()>& on_edit) {
    while (running_ && !files_last_write_time_prev_.empty()) {
      std::this_thread::sleep_for(_delay);

      bool can_run_on_edit = false;

      //  erased
      std::vector<std::string> files_not_existing;
      for (const auto& file : files_last_write_time_prev_) {
        const auto& file_path = file.first;
        if (!file_exists(file_path)) files_not_existing.push_back(file_path);
      }

      if (!files_not_existing.empty()) {
        for (const auto& file_path : files_not_existing) {
          std::cout << file_path << " file deleted." << std::endl;
        }
      } else
        can_run_on_edit = true;

      //  modified
      if (can_run_on_edit) {
        for (const auto& file : files_last_write_time_prev_) {
          const auto& file_path = file.first;
          auto last_write_time_prev = file.second;
          auto file_last_write_time =
              std::filesystem::last_write_time(file_path);
          if (file_last_write_time != last_write_time_prev) {
            last_write_time_prev = file_last_write_time;
            on_edit();
          }
        }
      }
    }
  }

 private:
  bool running_ = true;
  std::unordered_map<std::string, std::filesystem::file_time_type>
      files_last_write_time_prev_;

  bool file_exists(std::string file_path) {
    return std::filesystem::exists(file_path);
  }
}
