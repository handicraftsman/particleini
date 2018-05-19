# ParticleINI

## Building and installing

```bash
$ git clone https://github.com/handicraftsman/particleini
$ cd particleini
$ mkdir build && cd build
$ meson ..
$ ninja
$ meson configure . -Dprefix=/usr/
$ sudo ninja install
```

## Using the library

```cpp
#include <iostream>

#include <particleini.hpp>

int main() {
  std::string path = "../test.ini";
  particleini::config config(path);
  for (std::pair<std::string, particleini::config::dsec> sp : config.data) {
    std::string& sname = sp.first;
    particleini::config::dsec& section = sp.second;
    for (std::pair<std::string, std::string> vp : section) {
      std::string& name = vp.first;
      std::string& value = vp.second;
      std::cout << sname << " <- " << name << " = " << value << std::endl;
    }
  }
}
```
