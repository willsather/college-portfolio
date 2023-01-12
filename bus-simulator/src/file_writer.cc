/**
 * @file file_writer.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "src/file_writer.h"

FileWriter::FileWriter() {}

void FileWriter::Write(std::string name, std::vector<std::string> vec) {
  // open file
  // write to file
  // close file

  std::ofstream outFS;
  outFS.open(name, std::ios::app);

  if (!outFS.is_open()) {
    std::cout << "FILE OPEN FAILED" << std::endl;
  }

  for (int i = 0; i < vec.size(); i++) {
    outFS << vec[i] << ",";
  }

  outFS.close();
}
