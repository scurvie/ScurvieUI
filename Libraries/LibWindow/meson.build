LibWindow = library('LibWindow',
  'Wayland/Connection.cpp',
  'Wayland/Message.cpp',
  version : version,
  soversion : soversion,
  include_directories : incdir,
  install : true )
install_headers(
  'Wayland/Connection.h',
  'Wayland/Message.h',
  'Wayland/RingBuffer.hpp',
  subdir : 'LibWindow/Wayland' )
pkg.generate(LibWindow)
