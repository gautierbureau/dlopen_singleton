//
// Created by bureaugau on 17/04/2020.
//

#ifndef DLOPEN_SINGLETON_LOG_HPP
#define DLOPEN_SINGLETON_LOG_HPP

#include <string>

class Log {
 public:
  static Log* getInstance();
  
  static Log** getPointerToInstance();

  static void init();
  
  static void destroyLog();

  static void log(std::string message);
  
  void setPointerToInstance(Log** log);
  
 private:
  Log();

  virtual ~Log();

  Log(const Log&) = delete;

  Log(Log&&) = delete;

  Log& operator=(const Log&) = delete;

  Log& operator=(Log&&) noexcept = delete;
  
  void log_(std::string message);
  
  void init_();
  
  static Log* m_pInstance;
  
  static Log** m_ppInstance;

};

extern "C" void destroyLog();

extern "C" Log* getLogInstance();

#endif //DLOPEN_SINGLETON_LOG_HPP
