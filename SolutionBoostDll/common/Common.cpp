//
// Created by bureaugau on 17/04/2020.
//

#include <iostream>

#include "Common.hpp"
#include "Log.hpp"
#include "Util.hpp"

void Common::common() {
  Trace("Log from common");
  std::cout << "common" << std::endl;
  Util u;
  u.util();
}
