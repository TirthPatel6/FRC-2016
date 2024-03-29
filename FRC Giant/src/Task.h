/*
 * Task.h
 *
 *
 *  Created on: Feb 18, 2016
 *      Author: Tirth Patel & Pranav Kandarpa
 */

#ifndef SRC_TASK_H_
#define SRC_TASK_H_

#pragma once

#include "ErrorBase.h"
#include "HAL/Task.hpp"
#include <iostream>
#include <string>
#include <thread>

/**
 * Wrapper class around std::thread that allows changing thread priority
 */
class Task : public ErrorBase {
 public:
  static const uint32_t kDefaultPriority = 60;

  Task() = default;
  Task(const Task&) = delete;
  Task& operator=(const Task&) = delete;
  Task& operator=(Task&& task);

  template <class Function, class... Args>
  Task(const std::string& name, Function&& function, Args&&... args);

  virtual ~Task();

  bool joinable() const noexcept;
  void join();
  void detach();
  std::thread::id get_id() const noexcept;
  std::thread::native_handle_type native_handle();

  bool Verify();

  int32_t GetPriority();

  bool SetPriority(int32_t priority);

  std::string GetName() const;

 private:
  std::thread m_thread;
  std::string m_taskName;
  bool HandleError(STATUS results);
};

#include "Task.inc"



#endif /* SRC_TASK_H_ */
