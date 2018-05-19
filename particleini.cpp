#include "particleini.hpp"

#include <iostream>
#include <fstream>
#include <regex>

particleini::config::config(std::string& config_path) {
  static std::regex regex_section("^\\[(.+)\\]$");
  static std::regex regex_pair("^(.+?) ?= ?(.+)$");

  std::ifstream f(config_path);
  std::string line;

  std::string sname = "general";
  particleini::config::dsec section;

  while (std::getline(f, line)) {
    auto m = std::smatch {};
    if ((m = std::smatch {}, std::regex_match(line, m, regex_section))) {
      data[sname] = section;
      sname = m[1];
      section = particleini::config::dsec();
    } else if ((m = std::smatch {}, std::regex_match(line, m, regex_pair))) {
      std::string l = m[2];
      if (l[0] == '"' && l[l.size() - 1] == '"') {
        l = l.substr(1, l.size() - 2);
      } else if (l[0] == '\'' && l[l.size() - 1] == '\'') {
        l = l.substr(1, l.size() - 2);
      } else if ((l[0] == '\'' || l[l.size() - 1] == '\'' || l[0] == '"' || l[l.size() - 1] == '"') && l[0] != l[l.size() - 1]) {
        throw std::runtime_error("Invalid value");
      }
      section.push_back(std::make_pair(m[1], l));
    }
  }
  data[sname] = section;
}
