#include <cstdint>
#include <iostream>
#include <LibWindow/Wayland/Connection.h>
#include <LibWindow/Wayland/Message.h>
int main(int argc, char *argv[]) {
  LibWindow::Wayland::Connection c;
  LibWindow::Wayland::Message wl_display_get_registry(1, 1);
  uint32_t wl_registry_id = c.new_id();
  wl_display_get_registry.push(wl_registry_id);
  c.send_message(wl_display_get_registry);
  std::cout << "wl_display@1.get_registry: wl_registry=" << wl_registry_id << std::endl;
  return 0;
}
