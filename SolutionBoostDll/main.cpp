#include <boost/dll/import.hpp>
#include <boost/dll/shared_library.hpp>
#include <boost/function.hpp>

#include "LibInstance.hpp"
#include "Log.hpp"
#include "Common.hpp"

const char* sharedLibraryExtension() {
#ifdef _WIN32
static const char extension[] = ".dll";
#elif __APPLE__
static const char extension[] = ".dylib";
#elif __linux__
static const char extension[] = ".so";
#elif __unix__  // all unices not caught above
static const char extension[] = ".so";
#else
#error "Unknown compiler"
#endif
  return extension;
}

int main() {

  std::string name = "./lib" + std::string(sharedLibraryExtension());

  boost::function<create_t> create_lib;
  boost::function<destroy_t> destroy_lib;

  boost::dll::shared_library library(name);
  if (library.has("create"))
    create_lib = boost::dll::import<create_t>(library, "create");
  else
    throw std::runtime_error("No symbol create in plugin.");
  if (library.has("destroy"))
    destroy_lib = boost::dll::import<destroy_t>(library, "destroy");
  else
    throw std::runtime_error("No symbol destroy in plugin.");

  Log::init();

  Trace("Log from main");

  Common c;
  c.common();

  // create an instance of the class
  Lib* lib = create_lib();

  lib->print();

  destroy_lib(lib);

  return 0;
}
