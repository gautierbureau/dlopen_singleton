//
// Created by bureaugau on 17/04/2020.
//

#ifndef DLOPEN_SINGLETON_UTIL_HPP
#define DLOPEN_SINGLETON_UTIL_HPP

#include <string>

class Util {
 public:
  Util() = default;

  virtual ~Util() noexcept = default;

  Util(const Util&) = delete;

  Util(Util&&) = delete;

  Util& operator=(const Util&) = delete;

  Util& operator=(Util&&) noexcept = delete;

  void util();
};

#endif //DLOPEN_SINGLETON_UTIL_HPP
