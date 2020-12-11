//
// Created by bureaugau on 17/04/2020.
//

#ifndef DLOPEN_SINGLETON_API_HPP
#define DLOPEN_SINGLETON_API_HPP

#include <string>

class Api {
public:
   Api() = default;

   virtual ~Api() noexcept = default;

   Api(const Api&) = delete;

   Api(Api&&) = delete;

   Api& operator=(const Api&) = delete;

   Api& operator=(Api&&) noexcept = delete;

   void api();
};

#endif //DLOPEN_SINGLETON_API_HPP
