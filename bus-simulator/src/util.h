/**
 * @file util.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_UTIL_H_
#define SRC_UTIL_H_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


/** @ brief
The util class in our UML is used to parse
the string returned by the ostringstream
object (that contains the information from
the Report method) and stores parsed data
into a container to be able to write the
data to a file. 
*/
class Util {
 public:
  std::vector<std::string> processOutput(std::ostringstream*);
};

#endif  // SRC_UTIL_H_
