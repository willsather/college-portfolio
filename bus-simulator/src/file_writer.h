/**
 * @file file_writer.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_FILE_WRITER_H_
#define SRC_FILE_WRITER_H_

#include <vector>
#include <string>

/** @ brief
This class writes the parsed data
from the container to a file
*/
class FileWriter {
 public:
  FileWriter();
  void Write(std::string name, std::vector<std::string> vec);
};

#endif  // SRC_FILE_WRITER_H_
