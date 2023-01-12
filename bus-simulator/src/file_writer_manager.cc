/**
 * @file file_writer_manager.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <vector>
#include <string>

#include "src/file_writer_manager.h"
#include "src/file_writer.h"

FileWriterManager::FileWriterManager() {}

FileWriter FileWriterManager::GetInstance() {
  return file_writer;
}
