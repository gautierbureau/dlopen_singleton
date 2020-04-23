//
// Created by bureaugau on 17/04/2020.
//

#ifndef DLOPEN_SINGLETON_LOG_HPP
#define DLOPEN_SINGLETON_LOG_HPP

#include <string>

class Log {
 public:
  static Log& getInstance();

  static void log(const std::string& message);
  
  static void init();
    
 private:
  Log();

  virtual ~Log();

  Log(const Log&) = delete;

  Log(Log&&) = delete;

  Log& operator=(const Log&) = delete;

  Log& operator=(Log&&) noexcept = delete;
  
  void log_(const std::string& message);
  
  void init_();
};

extern "C" void Trace(const std::string& message);


#endif //DLOPEN_SINGLETON_LOG_HPP
