//
// Created by bureaugau on 17/04/2020.
//

#include <iostream>

#include "Api.hpp"
#include "Log.hpp"
#include "Common.hpp"

void Api::api() {
  Trace("Log from api");
  std::cout << "api" << std::endl;
  Common c;
  c.common();
}
