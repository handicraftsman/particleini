#include <particlepm.hpp>

using namespace PPM::Utils;

PPM_PACKAGE(p) {
  p->name("particleini");
  p->version(PPM::Version("v0.1.4"));
  p->description("A simple INI parser for C++ ");
  p->github(PPM::GitHub("handicraftsman", "particleini"));
  p->license(PPM::License("MIT", "https://github.com/handicraftsman/particleini/blob/master/LICENSE.txt"));

  PPM::TargetPtr lib = p->library("particleini");
  lib->cpp("c++11");
  lib->cpp_files(std::vector<std::string> {
    "particleini.cpp"
  });
}