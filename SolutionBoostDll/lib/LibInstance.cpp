//
// Created by bureaugau on 17/04/2020.
//

#if defined _WIN32
  #define DLL_PUBLIC __declspec(dllexport)
#else
  #define DLL_PUBLIC
#endif

#include "LibInstance.hpp"

LibInstance::LibInstance() {}

void LibInstance::print() {
  Trace("Log from lib");
}

extern "C" DLL_PUBLIC Lib* create() {
  return new LibInstance;
}

extern "C" DLL_PUBLIC void destroy(Lib* lib) {
  delete lib;
}
