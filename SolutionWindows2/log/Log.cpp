//
// Created by bureaugau on 17/04/2020.
//

#include <iostream>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/global_logger_storage.hpp>

#include "Log.hpp"

Log* Log::m_pInstance = NULL;

Log::Log() { std::cout << "Log::Log" << std::endl; }

Log::~Log() { std::cout << "Log::~Log "; }

void Log::init_() {
	boost::log::add_file_log("sample.log");

    boost::log::core::get()->set_filter
    (
        boost::log::trivial::severity >= boost::log::trivial::info
    );
    boost::log::add_common_attributes();
}

void Log::log(const std::string& message) {
	getInstance()->log_(message);
}

void Log::log_(const std::string& message) {
	
	boost::log::sources::severity_logger< boost::log::trivial::severity_level > lg;

    BOOST_LOG_SEV(lg, boost::log::trivial::info) << message;
}

Log*
Log::getInstance() {
	if (!m_pInstance) {
		m_pInstance = new Log;
		m_pInstance->init_();
	}
	return m_pInstance;
}

void Log::destroyLog() {
	if (m_pInstance) {
		delete m_pInstance;
	}
}

extern "C" void destroyLog() {
  Log::destroyLog();
}

extern "C" void Trace(const std::string& message) {
	Log::log(message);
}
