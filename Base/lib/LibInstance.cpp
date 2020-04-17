//
// Created by bureaugau on 17/04/2020.
//

#include "LibInstance.hpp"
#include "Log.hpp"

LibInstance::LibInstance() {}

void LibInstance::print() {
  Log::log();
}

extern "C" LibInstance* create() {
  return new LibInstance;
}

extern "C" void destroy(LibInstance* lib) {
  delete lib;
}
