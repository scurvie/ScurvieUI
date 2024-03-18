/*
 * Copyright (c) 2024, Sreehari Sreedev <me@ssree.dev>
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#pragma once
#include <cstdint>
#include "Message.h"
#include "RingBuffer.hpp"

namespace LibWindow::Wayland {
  class Message;
  class Connection {
    private:
      static inline uint32_t m_current_object_id = 2;
      int m_fd;
      RingBuffer<uint32_t> m_ring;
    public:
      Connection();
      ~Connection();
      void send_message(Message msg);
      void recv_messages();
      uint32_t new_id();
      int fd();
      RingBuffer<uint32_t> ring();
  };
}
