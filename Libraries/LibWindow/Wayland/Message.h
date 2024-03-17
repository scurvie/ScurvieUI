/*
 * Copyright (c) 2024, Sreehari Sreedev <me@ssree.dev>
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include "Connection.h"

namespace LibWindow::Wayland {
  class Message {
    private:
      std::vector<uint32_t> m_values;
    public:
      Message(uint32_t object_id, uint16_t opcode);
      void push(uint32_t value);
      void push(std::string str);
      std::vector<uint32_t> data();
      size_t size();
  };
}
