project('ScurvieUI', 'c', 'cpp',
  default_options : [ 'cpp_std=c++20']
)
version = '0.0.1'
soversion = '0'
pkg = import('pkgconfig')

LibWindow = library('LibWindow',
  'Libraries/LibWindow/Wayland/Connection.cpp',
  'Libraries/LibWindow/Wayland/Message.cpp',
  version : version,
  soversion : soversion,
  include_directories : 'Libraries',
  install : true )
install_headers(
  'Libraries/LibWindow/Wayland/Connection.h',
  'Libraries/LibWindow/Wayland/Message.h',
  subdir : 'LibWindow/Wayland' )
pkg.generate(LibWindow)

LibDrawing = library('LibDrawing',
  'Libraries/LibDrawing/Color.cpp',
  version : version,
  soversion : soversion,
  include_directories : 'Libraries',
  install : true )
install_headers(
  'Libraries/LibDrawing/Color.h',
  subdir : 'LibDrawing' )
pkg.generate(LibDrawing)

test = executable('tester',
  'src/tester.cpp',
  include_directories : include_directories('Libraries'),
  link_with : [ LibWindow, LibDrawing ],
  install : true )
