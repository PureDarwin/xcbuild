#
# Copyright (c) 2015-present, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.
#

file(GLOB_RECURSE dependency_HEADERS Headers/dependency/**/*.h)
add_library(dependency STATIC
            Sources/DependencyInfo.cpp
            Sources/DependencyInfoFormat.cpp
            Sources/BinaryDependencyInfo.cpp
            Sources/DirectoryDependencyInfo.cpp
            Sources/MakefileDependencyInfo.cpp
            ${dependency_HEADERS})

set_target_properties(dependency PROPERTIES FOLDER "Libraries")
target_link_libraries(dependency PUBLIC util ext)
target_include_directories(dependency PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Headers")

add_executable(dependency-info-tool Tools/dependency-info-tool.cpp)
set_target_properties(dependency-info-tool PROPERTIES FOLDER "Tools")
target_link_libraries(dependency-info-tool dependency process util)
install(TARGETS dependency-info-tool DESTINATION bin)

add_executable(dump_dependency Tools/dump_dependency.cpp)
set_target_properties(dump_dependency PROPERTIES FOLDER "Tools")
target_link_libraries(dump_dependency dependency process util)

if (BUILD_TESTING)
  ADD_UNIT_GTEST(dependency BinaryDependencyInfo Tests/test_BinaryDependencyInfo.cpp)
  ADD_UNIT_GTEST(dependency MakefileDependencyInfo Tests/test_MakefileDependencyInfo.cpp)
  ADD_UNIT_GTEST(dependency DirectoryDependencyInfo Tests/test_DirectoryDependencyInfo.cpp)
endif ()
