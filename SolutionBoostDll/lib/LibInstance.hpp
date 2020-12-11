//
// Created by bureaugau on 17/04/2020.
//

#ifndef DLOPEN_SINGLETON_LIBINSTANCE_HPP
#define DLOPEN_SINGLETON_LIBINSTANCE_HPP

#include "Lib.hpp"

class LibInstance : public Lib {
 public:
  LibInstance();

  virtual ~LibInstance() noexcept = default;

  LibInstance(const LibInstance&) = delete;

  LibInstance(LibInstance&&) = delete;

  LibInstance& operator=(const LibInstance&) = delete;

  LibInstance& operator=(LibInstance&&) noexcept = delete;

  void print();
};

#endif //DLOPEN_SINGLETON_LIBINSTANCE_HPP
