//
// Created by bureaugau on 17/04/2020.
//

#include <iostream>
#include "Log.hpp"

Log::Log() { std::cout << "Log::Log" << std::endl; }

void Log::log() {
  getInstance().log_();
}

void Log::log_() {
  std::cout << "Log::log()" << std::endl;
}

Log&
Log::getInstance() {
  static Log INSTANCE;
  return INSTANCE;
}