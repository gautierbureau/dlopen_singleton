//
// Created by bureaugau on 17/04/2020.
//
#include <iostream>

#include "Lib.hpp"
#include "Log.hpp"
#include "Common.hpp"
#include "Api.hpp"

void Lib::common() {
  std::cout << "lib::common"<< std::endl;
  Trace("Log from lib-common");
  Common c;
  c.common();
  Api api;
  api.api();
}