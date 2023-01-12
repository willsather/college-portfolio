/**
 * @file util.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <vector>
#include <string>
#include "src/util.h"

std::vector<std::string> Util::processOutput(std::ostringstream* report) {
  std::string sReport = report->str();
  std::vector<std::string> res;
  std::string temp = ",";

  for (int i = 0; i < sReport.size(); i++) {
    if (sReport[i] == ' ' || sReport[i] == ':'
      || sReport[i] == '\t' || sReport[i] == '\n') {
      if (temp != "") {
        res.push_back(temp);
      }
      temp = "";
    } else if (sReport[i] !=' ' && sReport[i] !=
    ':' && sReport[i] != '\t' && sReport[i] != '\n') {
      temp.push_back(sReport[i]);
    }
  }
  if (temp != "") {
    res.push_back(temp);
  }
  return res;


  /*
  std::vector<std::string> res;
  std::string temp = "";
  for (int i = 0; i<report.size(); i++) {
    if (report[i] == ' ' || report[i] == ':' || report[i] == '\t') {
      if (temp != "") {
        res.push_back(temp);
      }
      temp="";
    } else if (report[i] !=' ' && report[i] != ':' && report[i] != '\t') {
      temp.push_back(report[i]);
    }
  }
  if (temp != "") {
    res.push_back(temp);
  }
  return res;
  */
}
