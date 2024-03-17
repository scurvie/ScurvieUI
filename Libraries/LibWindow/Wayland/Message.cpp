/*
 * Copyright (c) 2024, Sreehari Sreedev <me@ssree.dev>
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */


#include <cstddef>
#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <sys/socket.h>
#include <vector>
#include "Message.h"

namespace LibWindow::Wayland {
  Message::Message(uint32_t object_id, uint16_t opcode) {
    this->m_values.push_back(object_id);
    this->m_values.push_back(opcode);
  }

  void Message::push(uint32_t value) {
    this->m_values.push_back(value);
  }

  void Message::push(std::string str) {
    size_t num = (str.length() + 3) / 4;
    uint32_t* arr = new uint32_t[num]();
    std::memcpy(arr, str.data(), str.length());

    this->m_values.insert(this->m_values.end(), &arr[0], &arr[num]);
    delete[] arr;
  }

  size_t Message::size() {
    return this->m_values.size() * sizeof(uint32_t);
  }

  std::vector<uint32_t> Message::data() {
    // always make sure total message size is up to date.
    uint16_t current_size = this->size();
    this->m_values[1] |= (current_size << 16);
    return this->m_values;
  }
}
