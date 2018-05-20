project('particleini', ['cpp'], default_options : ['cpp_std=gnu++17'])

add_global_arguments('-Wall', language : 'cpp')
add_global_arguments('-Werror', language : 'cpp')

lib = shared_library(
  'particleini',
  [
    'particleini.cpp'
  ],
  install: true
)

install_headers('particleini.hpp')

executable(
  'pini-test',
  'pini-test.cpp',
  install: false,
  link_with: [lib]
)

pkg = import('pkgconfig')
pkg.generate(
  libraries: '-lparticleini',
  version: '0.1.3',
  name: 'particleini',
  filebase: 'particleini',
  description: 'A simple INI parser for C++'
)
