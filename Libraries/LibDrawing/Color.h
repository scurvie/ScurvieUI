/*
 * Copyright (c) 2024, Sreehari Sreedev <me@ssree.dev>
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#pragma once

namespace LibDrawing {
  class Color {
    private:
      float m_red;
      float m_green;
      float m_blue;
      float m_alpha;
  public:
      Color(float red, float green, float blue, float alpha);
      float red();
      float green();
      float blue();
      void set_red(float);
      void set_green(float);
      void set_blue(float);
  };
}
