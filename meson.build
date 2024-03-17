project('ScurvieUI', 'c', 'cpp',
  default_options : [ 'cpp_std=c++20']
)
version = '0.0.1'
soversion = '0'
pkg = import('pkgconfig')

LibWindow = library('Window',
  'Libraries/LibWindow/Wayland/Connection.cpp',
  version : version,
  soversion : soversion,
  include_directories : 'Libraries/LibWindow',
  install : true )
install_headers(
  'Libraries/LibWindow/Wayland/Connection.h',
  'Libraries/LibWindow/Wayland/Protocol.h',
  subdir : 'Window/Wayland' )
pkg.generate(LibWindow, name : 'LibWindow')
