/*
 * Copyright (c) 2024, Sreehari Sreedev <me@ssree.dev>
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#pragma once
#include <Connection.h>
#include <cstdint>
#include <string>
#include <vector>

class WireMessage {
private:
  std::vector<uint32_t> m_values;
public:
  WireMessage(uint32_t object_id, uint16_t opcode);
  void push(uint32_t value);
  void push(std::string str);
  std::vector<uint32_t> data();
  size_t size();
};

class WireProtocol {
private:
  uint32_t m_current_object_id = 0;
  int m_fd;
public:
  WireProtocol(Connection);
  void send_message(WireMessage msg);
};
