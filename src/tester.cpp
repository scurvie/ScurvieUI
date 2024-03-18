#include <cstdint>
#include <iostream>
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

  LibWindow::Wayland::RingBuffer<uint32_t> rb(10);
  std::cout << "Size: " << rb.size() << std::endl;

  std::cout << "enqueue 1" << std::endl;
  rb.enqueue(1);
  std::cout << "Size: " << rb.size() << std::endl;

  std::cout << "enqueue 2" << std::endl;
  rb.enqueue(2);
  std::cout << "Size: " << rb.size() << std::endl;

  std::cout << "enqueue 2" << std::endl;
  rb.enqueue(2);
  std::cout << "Size: " << rb.size() << std::endl;

  std::cout << "enqueue 1" << std::endl;
  rb.enqueue(1);
  std::cout << "Size: " << rb.size() << std::endl;

  std::cout << "enqueue 2" << std::endl;
  rb.enqueue(2);
  std::cout << "Size: " << rb.size() << std::endl;

  std::cout << "enqueue 2" << std::endl;
  rb.enqueue(2);
  std::cout << "Size: " << rb.size() << std::endl;

  std::cout << "enqueue 2" << std::endl;
  rb.enqueue(2);
  std::cout << "Size: " << rb.size() << std::endl;

  std::cout << "enqueue 2" << std::endl;
  rb.enqueue(2);
  std::cout << "Size: " << rb.size() << std::endl;
  uint32_t b = rb.dequeue();
  std::cout << "dequeue: " << b << std::endl;
  return 0;
}
