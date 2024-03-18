#include <cstdint>
#include <iostream>
#include <iomanip>
#include <LibWindow/Wayland/Connection.h>
#include <LibWindow/Wayland/Message.h>
#include <LibWindow/Wayland/RingBuffer.hpp>
int main(int argc, char *argv[]) {
  LibWindow::Wayland::Connection c;
  LibWindow::Wayland::Message wl_display_get_registry(1, 1);
  uint32_t wl_registry_id = c.new_id();
  wl_display_get_registry.push(wl_registry_id);
  c.send_message(wl_display_get_registry);
  std::cout << "wl_display@1.get_registry: wl_registry=" << wl_registry_id << std::endl;

  c.recv_messages();
  LibWindow::Wayland::RingBuffer<uint32_t> bruh = c.ring();

  while (!bruh.is_empty()) {
    std::cout << std::setfill('0') << std::setw(8) << std::hex << bruh.dequeue() << std::endl;
  }
  return 0;
}
