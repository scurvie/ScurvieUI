/*
 * Copyright (c) 2024, Sreehari Sreedev <me@ssree.dev>
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include "Color.h"

namespace LibDrawing {
  Color::Color(float red, float green, float blue, float alpha) {
    this->m_red = red;
    this->m_green = green;
    this->m_blue = blue;
    this->m_alpha = alpha;
  }
  float Color::red() {
    return this->m_red;
  }
  float Color::green() {
    return this->m_green;
  }
  float Color::blue() {
    return this->m_blue;
  }
  void Color::set_red(float red) {
    this->m_red = red;
  }
  void Color::set_green(float green) {
    this->m_green = green;
  }
  void Color::set_blue(float blue) {
    this->m_blue = blue;
  }
}
