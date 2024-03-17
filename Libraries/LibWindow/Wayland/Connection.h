/*
 * Copyright (c) 2024, Sreehari Sreedev <me@ssree.dev>
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#pragma once

class Connection {
private:
  int m_fd;
public:
  Connection();
  ~Connection();
  int fd();
};
