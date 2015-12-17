/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#ifndef __builtin_copyStrings_Driver_h
#define __builtin_copyStrings_Driver_h

#include <builtin/Driver.h>

namespace builtin {
namespace copyStrings {

class Driver : public builtin::Driver {
public:
    Driver();
    ~Driver();

public:
    virtual std::string name();

public:
    virtual int run(std::vector<std::string> const &args, std::unordered_map<std::string, std::string> const &environment);
};

}
}

#endif // !__builtin_copyStrings_Driver_h
