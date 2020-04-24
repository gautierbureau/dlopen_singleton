//
// Created by bureaugau on 17/04/2020.
//

#ifndef DLOPEN_SINGLETON_LIB_HPP
#define DLOPEN_SINGLETON_LIB_HPP

#include "Log.hpp"

class Lib {
 public:
  Lib() = default;

  virtual ~Lib() noexcept = default;

  Lib(const Lib&) = delete;

  Lib(Lib&&) = delete;

  Lib& operator=(const Lib&) = delete;

  Lib& operator=(Lib&&) noexcept = delete;

  virtual void print() = 0;
};

#endif //DLOPEN_SINGLETON_LIB_HPP
