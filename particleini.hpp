#pragma once

#include <map>
#include <string>
#include <utility>
#include <vector>

namespace particleini {

  class config {
  public:
    typedef std::vector<std::pair<std::string, std::string>> dsec;
    typedef std::map<std::string, dsec> dmap;

    config(std::string& config_path);

    dmap data;
  };

}
