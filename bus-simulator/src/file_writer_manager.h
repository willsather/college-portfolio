/**
 * @file file_writer_manager.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_FILE_WRITER_MANAGER_H_
#define SRC_FILE_WRITER_MANAGER_H_

#include <vector>
#include <string>

#include "src/file_writer.h"

/** @ brief
The file_writer_manager class
is used to implement the
singleton pattern 
*/
class FileWriterManager {
 private:
  static FileWriter file_writer;
 public:
  FileWriterManager();

  /** @ brief
  The file_writer_manager function
  is used to return a pointer to the
  current index of the singleton pattern 
  */
  static FileWriter GetInstance();
};

#endif  // SRC_FILE_WRITER_MANAGER_H_
