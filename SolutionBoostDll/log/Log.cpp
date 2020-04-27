//
// Created by bureaugau on 17/04/2020.
//

#include <iostream>

#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/file.hpp>

#include "Log.hpp"

Log::Log() { std::cout << "Log::Log" << std::endl; }

Log::~Log() { std::cout << "Log::~Log" << std::endl; }

void Log::init() {
  getInstance().init_();
}

void Log::init_() {
  boost::log::add_file_log("sample.log");

  boost::log::core::get()->set_filter
  (
    boost::log::trivial::severity >= boost::log::trivial::info
  );
  boost::log::add_common_attributes();
}

void Log::log(const std::string& message) {
  getInstance().log_(message);
}

void Log::log_(const std::string& message) {
  boost::log::sources::severity_logger< boost::log::trivial::severity_level > lg;

  BOOST_LOG_SEV(lg, boost::log::trivial::info) << message;
}

Log&
Log::getInstance() {
  static Log instance;
  return instance;
}

extern "C" void Trace(const std::string& message) {
  Log::log(message);
}
