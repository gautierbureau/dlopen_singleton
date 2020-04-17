#include <iostream>
#include <dlfcn.h>

#include "LibInstance.hpp"
#include "Log.hpp"

int main() {
  Log::log();

  void* handle = dlopen("./lib/liblib.so", RTLD_LAZY);

  if (!handle) {
    std::cerr << "Cannot load library: " << dlerror() << '\n';
    return 1;
  }

  // load the symbols
  create_t* create_lib = (create_t*) dlsym(handle, "create");
  destroy_t* destroy_lib = (destroy_t*) dlsym(handle, "destroy");
  if (!create_lib || !destroy_lib) {
    std::cerr << "Cannot load symbols: " << dlerror() << '\n';
    return 1;
  }

  // create an instance of the class
  Lib* lib = create_lib();

  lib->print();

  return 0;
}
