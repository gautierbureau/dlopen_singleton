#ifdef WIN32
#include <direct.h>
#include <windows.h>
#else
#include <sys/types.h>
#include <dlfcn.h>
#endif

#include <iostream>

#include "LibInstance.hpp"
#include "Log.hpp"

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
	
	create_t* create_lib;
	destroy_t* destroy_lib;
	
	#ifdef WIN32
	HINSTANCE handle;
	#else
	void* handle;
    #endif
	
	#ifdef WIN32
    handle = LoadLibrary(TEXT(name.c_str()));
    if (!handle) {
        std::cerr << "Cannot load library: " << TEXT(name.c_str()) << std::endl;
		return 1;
	}
	create_lib = (create_t*) GetProcAddress(handle, "create");
    if (!create_lib) {
		std::cerr << "Cannot load symbol create: " << GetLastError() << std::endl;
		return 1;
	}
	destroy_lib = (destroy_t*) GetProcAddress(handle, "destroy");
    if (!destroy_lib) {
		std::cerr << "Cannot load symbol destroy: " << GetLastError() << std::endl;
		return 1;
	}
	#else
	handle = dlopen(name.c_str(), RTLD_NOW | RTLD_GLOBAL);
	if (!handle) {
		std::cerr << "Cannot load library: " << dlerror() << '\n';
		return 1;
	}
	create_t* create_lib = (create_t*) dlsym(handle, "create");
	if (!create_lib) {
		std::cerr << "Cannot load symbols: " << dlerror() << '\n';
		return 1;
	}
	destroy_t* destroy_lib = (destroy_t*) dlsym(handle, "destroy");
	if (!destroy_lib) {
		std::cerr << "Cannot load symbols: " << dlerror() << '\n';
		return 1;
	}
	#endif
	
	Log::init();
    
	Log::log("Log from main");
  
	// create an instance of the class
	Lib* lib = create_lib();

	lib->print();
	
	destroy_lib(lib); 
	
	#ifdef WIN32
	FreeLibrary(handle);
	#else
	dlclose(handle);
	#endif
	
  return 0;
}
