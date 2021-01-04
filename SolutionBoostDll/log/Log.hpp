//
// Created by bureaugau on 17/04/2020.
//

#ifndef DLOPEN_SINGLETON_LOG_HPP
#define DLOPEN_SINGLETON_LOG_HPP

#include <string>

extern "C" void Trace(const std::string& message = "default");

class Log {
 public:
  static void init();

 private:
  Log();

  virtual ~Log();

  Log(const Log&) = delete;

  Log(Log&&) = delete;

  Log& operator=(const Log&) = delete;

  Log& operator=(Log&&) noexcept = delete;

  static Log& getInstance();

  static void log(const std::string& message);

  void log_(const std::string& message);

  void init_();

  friend void Trace(const std::string& message);
};

#endif //DLOPEN_SINGLETON_LOG_HPP
