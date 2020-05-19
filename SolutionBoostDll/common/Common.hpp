//
// Created by bureaugau on 17/04/2020.
//

#ifndef DLOPEN_SINGLETON_COMMON_HPP
#define DLOPEN_SINGLETON_COMMON_HPP

#include <string>

class Common {
public:
   Common() = default;

   virtual ~Common() noexcept = default;

   Common(const Common&) = delete;

   Common(Common&&) = delete;

   Common& operator=(const Common&) = delete;

   Common& operator=(Common&&) noexcept = delete;

   void common();
};

#endif //DLOPEN_SINGLETON_COMMON_HPP
