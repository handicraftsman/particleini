#pragma once

#include <map>
#include <string>
#include <unordered_map>
#include <utility>

namespace particleini {

  class config {
  public:
    typedef std::unordered_map<std::string, std::string> dsec;
    typedef std::map<std::string, dsec> dmap;

    config(std::string& config_path);

    dmap data;
  };

}
