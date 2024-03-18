/*
 * Copyright (c) 2024, Sreehari Sreedev <me@ssree.dev>
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#pragma once
#include <memory>
#include <cstddef>

namespace LibWindow::Wayland {
  template <typename T>
  class RingBuffer {
    private:
      std::shared_ptr<T[]> m_buffer;

      size_t m_head;
      size_t m_tail;
      size_t m_max_size;
    public:
      RingBuffer();
      RingBuffer(size_t max_size);
      void enqueue(T item);
      T dequeue();
      T front();
      bool is_empty();
      bool is_full();
      size_t size();
  };

  template <typename T>
  RingBuffer<T>::RingBuffer() {
    this->m_head = 0;
    this->m_tail = 0;
    this->m_buffer = std::make_unique<T[]>(1024);
    this->m_max_size = 1024;
  }

  template <typename T>
  RingBuffer<T>::RingBuffer(size_t max_size) {
    this->m_head = 0;
    this->m_tail = 0;
    this->m_buffer = std::make_unique<T[]>(max_size);
    this->m_max_size = max_size;
  }

  template <typename T>
  void RingBuffer<T>::enqueue(T item) {
    if (this->is_full()) {
      throw std::runtime_error("buffer is full");
    }

    this->m_buffer[this->m_tail] = item;
    this->m_tail = (this->m_tail + 1) % this->m_max_size;
  }

  template <typename T>
  T RingBuffer<T>::dequeue() {
    if (this->is_empty()) {
      throw std::runtime_error("buffer is empty");
    }

    T item = this->m_buffer[this->m_head];

    T nothing;
    this->m_buffer[this->m_head] = nothing;

    this->m_head = (this->m_head + 1) % this->m_max_size;

    return item;
  }

  template <typename T>
  T RingBuffer<T>::front() {
    return this->m_buffer[this->m_head];
  }

  template <typename T>
  bool RingBuffer<T>::is_empty() {
    return this->m_head == this->m_tail;
  }

  template <typename T>
  bool RingBuffer<T>::is_full() {
    return (this->m_tail + 1) % this->m_max_size == this->m_head;
  }

  template <typename T>
  size_t RingBuffer<T>::size() {
    if (this->m_tail >= this->m_head) {
      return this->m_tail - this->m_head;
    }
    return this->m_max_size - (this->m_head - this->m_tail);
  }
};
