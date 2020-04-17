//
// Created by bureaugau on 17/04/2020.
//

#ifndef DLOPEN_SINGLETON_LOG_HPP
#define DLOPEN_SINGLETON_LOG_HPP


class Log {
 public:
  Log();

  virtual ~Log() noexcept = default;

  Log(const Log&) = delete;

  Log(Log&&) = delete;

  Log& operator=(const Log&) = delete;

  Log& operator=(Log&&) noexcept = delete;

  static Log& getInstance();

  static void log();

 private:

  void log_();

};


#endif //DLOPEN_SINGLETON_LOG_HPP
