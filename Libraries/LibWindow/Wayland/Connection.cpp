/*
 * Copyright (c) 2024, Sreehari Sreedev <me@ssree.dev>
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include "Connection.h"
#include "Message.h"
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

namespace LibWindow::Wayland {
  Connection::Connection() {
    char const* xdg_runtime_dir = std::getenv("XDG_RUNTIME_DIR");
    if (xdg_runtime_dir == nullptr) {
      throw std::runtime_error("XDG_RUNTIME_DIR not set!");
    }
    size_t const xdg_runtime_dir_len = strlen(xdg_runtime_dir);

    struct sockaddr_un addr = { .sun_family = AF_UNIX };
    if (xdg_runtime_dir_len >= sizeof(addr.sun_path)) {
      throw std::runtime_error("XDG_RUNTIME_DIR too long!");
    }
    size_t total_len = 0;
    std::memcpy(addr.sun_path, xdg_runtime_dir, xdg_runtime_dir_len);
    total_len += xdg_runtime_dir_len;

    addr.sun_path[total_len++] = '/';
    char const* wayland_display = std::getenv("WAYLAND_DISPLAY");
    if (wayland_display == nullptr) {
      char const wayland_zero[] = "wayland-0";
      size_t wayland_zero_len = sizeof(wayland_zero) - 1;
      if (total_len + wayland_zero_len >= sizeof(addr.sun_path)) {
        throw std::runtime_error("Socket path too long!");
      }
      std::memcpy(addr.sun_path + total_len, wayland_zero, wayland_zero_len);
      total_len += wayland_zero_len;
    } else {
      size_t wayland_display_len = strlen(wayland_display);
      if (total_len + wayland_display_len >= sizeof(addr.sun_path)) {
        throw std::runtime_error("Socket path too long!");
      }
      std::memcpy(addr.sun_path + total_len, wayland_display, wayland_display_len);
      total_len += wayland_display_len;
    }

    int fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (fd == -1) {
      throw std::runtime_error("Couldn't create wayland socket!");
    }

    if (connect(fd, reinterpret_cast<struct sockaddr*>(&addr), sizeof(addr)) == -1) {
      throw std::runtime_error("Couldn't connect to wayland socket!");
    }

    this->m_fd = fd;
  }

  Connection::~Connection() {
    close(this->m_fd);
  }

  int Connection::fd() {
    return this->m_fd;
  }

  uint32_t Connection::new_id() {
    return this->m_current_object_id++;
  }

  void Connection::send_message(Message msg) {
    ssize_t total_size = msg.size();
    std::vector<uint32_t> data = msg.data();
    if (total_size != send(this->m_fd, data.data(), total_size, MSG_DONTWAIT)) {
      throw std::runtime_error("send() failed!");
    }
  }
}
